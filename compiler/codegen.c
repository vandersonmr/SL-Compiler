#include "codegen.h"
#include <stdio.h>
#include <string.h>
#include "slc.h"

void processCall(TreeNode*);
void processExp(TreeNode*);
void processTerm(TreeNode*, int);
void processStatement(TreeNode*);
void processFunction(TreeNode*);

int labelGen = 1;
int exitLabel = -1;
int retValueAddrs = 0;


void processFactor(TreeNode* factor) {
  switch (factor->node_type) {
  case 18:
    printf("      LDCT   %d\n", factor->value);
    break;
  case 21:
    if (strcmp(factor->name, "true") == 0) {
      printf("      LDCT   1\n");
    } else if (strcmp(factor->name, "false") == 0) {
      printf("      LDCT   0\n");
    } else {
      if (findSymbol(factor->name) == NULL) SemanticError("Variable doesn't exist!\n");
      Symbol* sym = findSymbol(factor->name);
      printf("      LDVL   %d,%d\n", sym->level, sym->addr);
    }
    break;
  case 6:
    processCall(factor);
    break;
  case 17:
    processFactor((TreeNode*) getChild(factor, 0));
    printf("      LNOT\n");
    break;
  default:
    processExp(factor);
    break;
  }
}

void processMultLoop(List* multLoop) {
  unsigned size = getListSize(multLoop);
  for (unsigned i = 0; i < size; i++) {
    TreeNode* factor = getFromList(multLoop, i);
    if (factor != NULL) {
      processFactor((TreeNode*) getChild(factor, 0));

      if (factor->value == '*') {
        printf("      MULT\n");
      } else if (factor->value == '/') {
        printf("      DIVD\n");
      } else if (factor->value == '&') {
        printf("      LAND\n");
      }
    }
  }
}

void processAdditiveLoop(List* additiveLoop) {
  unsigned size = getListSize(additiveLoop);
  for (unsigned i = 0; i < size; i++) {
    TreeNode* term = getFromList(additiveLoop, i);
    if (term != NULL) {
      processTerm((TreeNode*) getChild(term, 0), 0);

      if (term->value == '+') {
        printf("      ADDD\n");
      } else if (term->value == '-') {
        printf("      SUBT\n");
      } else if (term->value == '|') {
        printf("      LOR\n");
      }
    }
  }
}

void processTerm(TreeNode* term, int minus_op) {
  TreeNode* factor = getChild(term, 0);
  List* multLoop = getChild(term, 1);

  processFactor(factor);
  if (minus_op == '-')
    printf("      NEGT\n");

  if (multLoop != NULL)
    processMultLoop(multLoop);
}

void processSimpleExp(TreeNode* exp) {
  int minus_op = exp->value;
  processTerm(getChild(exp, 0), minus_op);

  List* additiveLoop = getChild(exp, 1);
  if (additiveLoop != NULL)
    processAdditiveLoop(additiveLoop);
}

void processRelationalExp(TreeNode* exp) {
  TreeNode* left = getChild(exp, 0);
  TreeNode* right = getChild(exp, 1);

  processSimpleExp(left);
  processSimpleExp(right);

  switch (exp->value) {
  case '=': // ==
    break;
  case '#': // !=
    break;
  case '(': // <=
    break;
  case '<':
    printf("      LESS\n");
    break;
  case ')': // >=
    break;
  case '>':
    printf("      GRTR\n");
    break;
  }
}

void processExp(TreeNode* exp) {
  switch (exp->node_type) {
  case 28:
    processSimpleExp(exp);
    break;
  case 20:
    processRelationalExp(exp);
    break;
  }
}

void processExps(List* exps) {
  unsigned size = getListSize(exps);
  for (unsigned i = 0; i < size; i++) {
    TreeNode* exp = getFromList(exps, i);
    if (exp != NULL)
      processExp(exp);
  }
}

void processCall(TreeNode* call) {
  char* name = call->name;
  List* exps = getChild(call, 0);
  if (strcmp(name, "write") == 0) {
    unsigned size = getListSize(exps);
    for (unsigned i = 0; i < size; i++) {
      TreeNode* exp = getFromList(exps, i);
      if (exp != NULL) {
        processExp(exp);
        printf("      PRNT\n");
      }
    }
    return;
  }
  else if (strcmp(name, "read") == 0) {
    unsigned size = getListSize(exps);
    for (unsigned i = 0; i < size; i++) {
      TreeNode* exp = getFromList(exps, i);
      if (exp != NULL) {
        printf("      READ\n");
        TreeNode* varName = getChild(getChild(exp, 0), 0);
        Symbol* sym = findSymbol(varName->name);
        if (sym == NULL) SemanticError("Didn't find symbol to assign\n");
        printf("      STVL   %d,%d\n", sym->level, sym->addr);
      }
    }
    return;
  }
  else {
    Symbol* sym = findSymbol(name);
    if (sym == NULL) SemanticError("Trying to call a function that doesn't exist!\n");
    if (strcmp(sym->type->label, "void") != 0) printf("      ALOC   1\n");

    if (exps != NULL)
      processExps(exps);
    printf("      CFUN   L%d,0\n", sym->addr);
  }

}

void processAssignment(TreeNode* assign) {
  TreeNode* varName = getChild(assign, 0);
  Symbol* sym = findSymbol(varName->name);
  if (sym == NULL) SemanticError("Didn't find symbol to assign\n");
  processExp(getChild(assign, 1));
  printf("      STVL   %d,%d\n", sym->level, sym->addr);
}

void processLabeledStatement(TreeNode* stm) {
  Symbol* sym = findSymbol(stm->name);
  if (sym == NULL) {
    sym = insertSymbol(stm->name, "label");
    sym->addr = labelGen;
    labelGen++;
  }
  printf("L%d:   ENLB   %d,%d\n", sym->addr, sym->level, 0);
  if (getChild(stm, 0) != NULL)
    processStatement((TreeNode*) getChild(stm, 0));
}

void processGoto(TreeNode* g) {
  Symbol* sym = findSymbol(g->name);
  if (sym == NULL) {
    sym = insertSymbol(g->name, "label");
    sym->addr = labelGen;
    labelGen++;
  }
  if (strcmp(sym->type->label, "label") != 0) SemanticError("Trying to goto to not a label\n");

  printf("      JUMP   L%d\n", sym->addr);
}

void processStatementLoop(List*);

void processIf(TreeNode* stm) {
  TreeNode* exp = getChild(stm, 0);
  List* ifBody = getChild(stm, 1);

  int l1 = labelGen;
  labelGen += 1;
  processExp(exp);
  printf("      JMPF   L%d\n", l1);
  processStatementLoop(ifBody);
  printf("L%d:   NOOP\n", l1);
}

void processIfElse(TreeNode* stm) {
  TreeNode* exp = getChild(stm, 0);
  List* ifBody = getChild(stm, 1);
  List* elseBody = getChild(stm, 2);

  int l1 = labelGen;
  int l2 = labelGen+1;
  labelGen += 2;
  processExp(exp);
  printf("      JMPF   L%d\n", l1);
  processStatementLoop(ifBody);
  printf("      JUMP   L%d\n", l2);
  printf("L%d:   NOOP\n", l1);
  processStatementLoop(elseBody);
  printf("L%d:   NOOP\n", l2);
}

void processWhile(TreeNode* stm) {
  TreeNode* exp = getChild(stm, 0);
  List* whileBody = getChild(stm, 1);

  int l1 = labelGen;
  int l2 = labelGen+1;
  labelGen += 2;
  printf("L%d:   NOOP\n", l1);
  processExp(exp);
  printf("      JMPF   L%d\n", l2);
  processStatementLoop(whileBody);
  printf("      JUMP   L%d\n", l1);
  printf("L%d:   NOOP\n", l2);
}

void processRet(TreeNode* ret) {
  if (ret->node_type == 15) { 
    TreeNode* exp = getChild(ret, 0);

    if (exp != NULL) {
      processExp(exp);
      printf("      STVL   %d,%d\n", stackHeight()-1, -retValueAddrs);
    }
  }

  if (exitLabel != -1) {
    printf("      JUMP   L%d\n", exitLabel);
  }
}

void processStatement(TreeNode* stm) {
  switch(stm->node_type) {
  case 6:
    processCall(stm);
    break;
  case 16:
    processAssignment(stm);
    break;
  case 13:
    processGoto(stm);
    break;
  case 27:
    processLabeledStatement(stm);
    break;
  case 11:
    processIf(stm);
    break;
  case 12:
    processIfElse(stm);
    break;
  case 10:
    processWhile(stm);
    break;
  case 14:
  case 15:
    processRet(stm);
    break;
  }
}

void processStatementLoop(List* stms) {
  unsigned size = getListSize(stms);
  for (unsigned i = 0; i < size; i++) {
    TreeNode* stm = getFromList(stms, i);
    if (stm != NULL)
      processStatement(stm);
  }
}

void allocVars(List* vars) {
  unsigned totalToAlloc = 0;
  unsigned size = getListSize(vars);
  for (unsigned i = 0; i < size; i++) {
    TreeNode* var = getFromList(vars, i);
    List* indenList = getChild(var, 0);
    TreeNode* type = getChild(var, 1);

    unsigned idenSize = getListSize(indenList);
    for (unsigned j = 0; j < idenSize; j++) {
      TreeNode* iden = getFromList(indenList, j);
      insertSymbol(iden->name, type->name);
    }

    totalToAlloc += getListSize(indenList);
  }

  printf("      ALOC   %u\n", totalToAlloc);
}

void dellocVars(List* vars) {
  unsigned totalToAlloc = 0;
  unsigned size = getListSize(vars);
  for (unsigned i = 0; i < size; i++) {
    TreeNode* var = getFromList(vars, i);
    List* indenList = getChild(var, 0);
    TreeNode* type = getChild(var, 1);

    totalToAlloc += getListSize(indenList);
  }

  printf("      DLOC   %u\n", totalToAlloc);
}

void processFuncLoop(List* funcLoop) {
  unsigned size = getListSize(funcLoop);
  for (unsigned i = 0; i < size; i++) {
    TreeNode* func = getFromList(funcLoop, i);

    int l1 = labelGen;
    int l2 = labelGen+1;
    exitLabel = l2;
    labelGen += 2;

    TreeNode* funcDeclaration = getChild(func, 0);
    Symbol* sym;
    if (func->node_type == 1)
      sym = insertSymbol(funcDeclaration->name, "void");
    else
      sym = insertSymbol(funcDeclaration->name, func->type);
    sym->addr = l1;

    printf("L%d:   ENFN   %d\n", l1, stackHeight());

    increaseStackSize();
    processFunction(func);
    decreaseStackSize();

    printf("L%d:   NOOP\n", l2);
    printf("      RTRN   %d\n", retValueAddrs-5);
  }
}

void processBlock(TreeNode* block) {
  List* typs = getChild(block, 1);
  List* vars = getChild(block, 2);
  List* funs = getChild(block, 3);
  List* body = getChild(block, 4);

  int l1;

  if (vars != NULL)
    allocVars(vars);

  if (funs != NULL) {
    l1 = labelGen;
    labelGen += 1;
    printf("      JUMP   L%d\n", l1);
    processFuncLoop(funs);
  }

  if (body != NULL) {
    if (funs != NULL) printf("L%d:   NOOP\n", l1);
    processStatementLoop(body);
  }

  if (vars != NULL)
    dellocVars(vars);
}

void processParams(List* params) {
  unsigned size = getListSize(params);
  int addrs = 4;
  for (unsigned i = 0; i < size; i++) {
    TreeNode* formalParam = getFromList(params, i);
    List* indenList = getChild(formalParam, 0);
    char* type = formalParam->type;
    addrs += findType(type)->size * getListSize(indenList);
  }
  retValueAddrs = addrs+1;

  for (unsigned i = 0; i < size; i++) {
    TreeNode* formalParam = getFromList(params, i);

    char* type = formalParam->type;
    List* indenList = getChild(formalParam, 0);

    unsigned idenListSize = getListSize(indenList);
    for (unsigned j = 0; j < idenListSize; j++) {
      TreeNode* iden = getFromList(indenList, j);

      Symbol* sym = insertSymbol(iden->name, type);
      sym->addr = -addrs;
      addrs -= findType(type)->size;
    }
  }
}

void processFuncDeclaration(TreeNode* funDeclaration) {
  List* params = getChild(funDeclaration, 0);
  TreeNode* block = getChild(funDeclaration, 1);

  if (params != NULL)
    processParams(params);

  if (block != NULL)
    processBlock(block);
}

void processFunction(TreeNode* function) {
    processFuncDeclaration(getChild(function, 0));
}

void processProgram(void* tree) {
  increaseStackSize();
  insertType("integer", 1);
  insertType("boolean", 1);
  insertType("label", 0);
  insertType("void", 0);

  printf("      MAIN\n");
  processFunction(getChild(tree, 0));
  printf("      STOP\n");
  printf("      END\n");
  decreaseStackSize();
}
