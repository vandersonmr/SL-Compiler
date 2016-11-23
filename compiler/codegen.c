#include "codegen.h"
#include <stdio.h>
#include <string.h>
#include "slc.h"

int labelGen = 1;

int stackHeight() {
  return 1;
}

void processParams(List* params) {
}

void processAdditiveLoop(List* additiveLoop) {
}

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
  }
}

void processMultLoop(List* multLoop) {
}

void processTerm(TreeNode* term) {
  TreeNode* factor = getChild(term, 0);
  List* multLoop = getChild(term, 1);

  processFactor(factor);

  if (multLoop != NULL)
    processMultLoop(multLoop);
}

void processSimpleExp(TreeNode* exp) {
  int minus_op = exp->value;
  processTerm(getChild(exp, 0));

  List* additiveLoop = getChild(exp, 1);
  if (additiveLoop != NULL)
    processAdditiveLoop(additiveLoop);
}

void processExp(TreeNode* exp) {
  switch (exp->node_type) {
  case 28:
    processSimpleExp(exp);
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
  if (strcmp(name, "write") == 0) {
    List* exps = getChild(call, 0);
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
    List* exps = getChild(call, 0);
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

}

void processAssignment(TreeNode* assign) {
  processExp(getChild(assign, 1));
  TreeNode* varName = getChild(assign, 0);
  Symbol* sym = findSymbol(varName->name);
  if (sym == NULL) SemanticError("Didn't find symbol to assign\n");
  printf("      STVL   %d,%d\n", sym->level, sym->addr);
}

void processStatement(TreeNode*);

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

void processBlock(TreeNode* block) {
  List* vars = getChild(block, 2);
  List* body = getChild(block, 4);

  if (vars != NULL)
    allocVars(vars);

  if (body != NULL)
    processStatementLoop(body);

  if (vars != NULL)
    dellocVars(vars);
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
  int level = increaseStackSize();
  if (level == 0) {
    insertType("integer", 1);
    insertType("boolean", 1);
    insertType("label", 0);
  }

  switch (function->node_type) {
  case 1:
    processFuncDeclaration(getChild(function, 0));
    break;
    //TODO: Not void function
  }

  decreaseStackSize();
}

void processProgram(void* tree) {
  printf("      MAIN\n");
  processFunction(getChild(tree, 0));
  printf("      STOP\n");
  printf("      END\n");
}
