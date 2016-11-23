#include "codegen.h"
#include "tree.h"
#include <stdio.h>
#include <string.h>

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
      printf("\tLDCT %d\n", factor->value);
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

void processExps(List* exps) {
  unsigned size = getListSize(exps);
  for (unsigned i = 0; i < size; i++) {
    TreeNode* exp = getFromList(exps, i);
    if (exp != NULL) {
      switch (exp->node_type) {
        case 28:
          processSimpleExp(exp);
          break;
      }
    }
  }
}

void processCall(TreeNode* call) {
  char* name = call->name;
  processExps(getChild(call, 0));
  if (strcpy(name, "write") != 0) {
    printf("\tPRNT\n");
  }
}

void processStatementLoop(List* stms) {
  unsigned size = getListSize(stms);
  for (unsigned i = 0; i < size; i++) {
    TreeNode* stm = getFromList(stms, i);
    if (stm != NULL) {
      switch(stm->node_type) {
        case 6:
          processCall(stm);
          break;
      }
    }
  }
}

void allocVars(List* vars) {
  unsigned totalToAlloc = 0;
  unsigned size = getListSize(vars);
  for (unsigned i = 0; i < size; i++) {
    TreeNode* var = getFromList(vars, i);
    List* indenList = getChild(var, 0);
    TreeNode* type = getChild(var, 1);

    totalToAlloc += getListSize(indenList);
  }

  printf("\tALOC %u\n", totalToAlloc);
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

  printf("\tDLOC %u\n", totalToAlloc);
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
  switch (function->node_type) {
    case 1:
      processFuncDeclaration(getChild(function, 0));
      break;
      //TODO: Not void function
  }
}

void processProgram(void* tree) {
  printf("\tMAIN\n");
  processFunction(getChild(tree, 0));
  printf("\tSTOP\n");
  printf("\tEND\n");
}
