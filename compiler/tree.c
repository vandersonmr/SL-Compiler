#include "tree.h"
#include <string.h>
#include <stdio.h>


#ifndef debug 
#define DEBUG_MSG(M)
#else
#define DEBUG_MSG(M) printf("DEBUG > %s\n", M);
#endif

TreeNode* root;

void *getTree() {
  return root;
}

void dfsCounts(void* root, int* functions, int* funcalls, int* whiles, int* ifs, int* bin) {
  if (root == NULL) return;

  TreeNode* rootNode = root;
  switch (rootNode->node_type) {
  case 1:
  case 2:
    (*functions)++;
    break;
  case 6:
    (*funcalls)++;
    break;
  case 10:
    (*whiles)++;
    break;
  case 11:
  case 12:
    (*ifs)++;
    break;
  case 20:
  case 30:
  case 31:
    (*bin)++;
    break;
  }

  List* next = rootNode->nodes;
  while (next != NULL) {
    if (next->value != NULL) {
      if (next->is_list) {
        // If current child is a List, we need to iterate over all members of 
        // this list also.
        List* inter_next = (List*) next->value;
        while (inter_next != NULL) {
          if (!inter_next->is_list && inter_next->value != NULL)
            dfsCounts(inter_next->value, functions, funcalls, whiles, ifs, bin);
          inter_next = inter_next->next;
        }
      } else {
        // If not, just call dfsCounts recursivily
        dfsCounts(next->value, functions, funcalls, whiles, ifs, bin);
      }
    }
    next = next->next;
  }
}

void counts(void* root, int* functions, int* funcalls, int* whiles, int* ifs, int* bin) {
  *functions = 0;
  *funcalls  = 0;
  *whiles    = 0;
  *ifs       = 0;
  *bin       = 0;

  dfsCounts(root, functions, funcalls, whiles, ifs, bin);
}


TreeNode* allocTreeNode(int node_type) {
  TreeNode* node = malloc(sizeof(TreeNode));
  node->node_type = node_type;
  node->name = NULL;
  node->type = NULL;
  node->nodes = NULL;
  return node;
}

void insertChild(TreeNode* node, void* child, int is_list) {
  if (node->nodes == NULL) {
    node->nodes = allocList(child, is_list);
    return;
  }

  insertIntoList(node->nodes, child, is_list);
}

void* getChild(TreeNode* node, int pos) {
  return getFromList(node->nodes, pos);
}

void setName(TreeNode* node, char* name) {
  node->name = name;
}

void setType(TreeNode* node, char* name) {
  node->type = malloc(strlen(name));
  strcpy(name, node->type);
}

#define ListTy 1
#define TreeNodeTy 0

void createProgramNode(TreeNode* func) {
  DEBUG_MSG("Creating program node");
  root = allocTreeNode(0);
  insertChild(root, func, TreeNodeTy);
}

TreeNode* createVoidFunctionNode(TreeNode* func) {
  DEBUG_MSG("Creating void function node");
  TreeNode* node = allocTreeNode(1);
  insertChild(node, func, TreeNodeTy);

  return node;
}

TreeNode* createFunctionNode(char* ret_type, TreeNode* func) {
  DEBUG_MSG("Creating function node");
  TreeNode* node = allocTreeNode(2);
  insertChild(node, func, TreeNodeTy);

  setType(node, ret_type);

  return node;
}

TreeNode* createFuncDeclarationNode(char* name, List* params, TreeNode* block) {
  DEBUG_MSG("Creating function declaration node");
  TreeNode* node = allocTreeNode(3);

  setName(node, name);

  insertChild(node, params, ListTy);
  insertChild(node, block, TreeNodeTy);

  return node;
}

TreeNode* createBlockNode(List* labels, List* types, List* variables,
                          List* functions, List* body) {
  DEBUG_MSG("Creating block node");
  TreeNode* node = allocTreeNode(5);

  insertChild(node, labels, ListTy);
  insertChild(node, types, ListTy);
  insertChild(node, variables, ListTy);
  insertChild(node, functions, ListTy);
  insertChild(node, body, ListTy);

  return node;
}

List* createTypeList(char* name, TreeNode* type) {
  TreeNode* type_node = allocTreeNode(7);
  setName(type_node, name);
  type_node->pair = type;
  return allocList(type_node, TreeNodeTy);
}

void insertTypeList(List* type_list, char* name, TreeNode* type) {
  TreeNode* type_node = allocTreeNode(7);
  setName(type_node, name);
  type_node->pair = type;
  insertIntoList(type_list, type_node, TreeNodeTy);
}

TreeNode* createTypeNode(char* name) {
  DEBUG_MSG("Creating type node");
  TreeNode* node = allocTreeNode(8);
  setName(node, name);
  return node;
}

TreeNode* createArrayTypeNode(char* name, List* brackets) {
  DEBUG_MSG("Creating type node");
  TreeNode* node = allocTreeNode(9);
  setName(node, name);

  insertChild(node, brackets, ListTy);
  return node;
}

TreeNode* createIntNode(int value) {
  DEBUG_MSG("Creating Int node");
  TreeNode* node = allocTreeNode(18);

  node->value = value;

  return node;
}

List* createIntList(int i) {
  return allocList(createIntNode(i), TreeNodeTy);
}

void insertIntList(List* int_list, int i) {
  insertIntoList(int_list, createIntNode(i), TreeNodeTy);
}

List* createIdentifierList(char* identifier) {
  TreeNode* Identifier = allocTreeNode(19);
  setName(Identifier, identifier);
  return allocList(Identifier, TreeNodeTy);
}

void insertIdentifierList(List* iden_list, char* identifier) {
  TreeNode* Identifier = allocTreeNode(19);
  setName(Identifier, identifier);
  insertIntoList(iden_list, Identifier, TreeNodeTy);
}

List* createVariableList(List* iden_list, TreeNode* type) {
  TreeNode* node = allocTreeNode(23);
  insertChild(node, iden_list, ListTy);
  insertChild(node, type, TreeNodeTy);
  return allocList(node, TreeNodeTy);
}

void insertVariableList(List* var_list, List* iden_list, TreeNode* type) {
  TreeNode* node = allocTreeNode(23);
  insertChild(node, iden_list, ListTy);
  insertChild(node, type, TreeNodeTy);
  insertIntoList(var_list, node, TreeNodeTy);
}

List* createFunctionList(TreeNode* func) {
  return allocList(func, TreeNodeTy);
}

void insertFunctionList(List* func_list, TreeNode* func) {
  insertIntoList(func_list, func, TreeNodeTy);
}

List* createStatementList(TreeNode* stm) {
  return allocList(stm, TreeNodeTy);
}

void insertStatementList(List* stm_list, TreeNode* stm) {
  insertIntoList(stm_list, stm, TreeNodeTy);
}

List* createFormalParamList(TreeNode* formal_param) {
  return allocList(formal_param, TreeNodeTy);
}

void insertFormalParamList(List* param_list, TreeNode* formal_param) {
  insertIntoList(param_list, formal_param, TreeNodeTy);
}

TreeNode* createExpParamNode(int is_var, List* ident_list, char* type) {
  DEBUG_MSG("Creating exp node");
  TreeNode* node;
  if(is_var == 0) node = allocTreeNode(24);
  else            node = allocTreeNode(25);

  setType(node, type);
  insertChild(node, ident_list, ListTy);

  return node;
}

TreeNode* createFuncParamNode(char* ret_type, char* name, List* param_list) {
  DEBUG_MSG("Creating param node");
  TreeNode* node = allocTreeNode(26);
  if (ret_type) setType(node, ret_type);
  setName(node, name);
  insertChild(node, param_list, ListTy);
  return node;
}

TreeNode* createLabeledStatementNode(char* label, TreeNode* unlabeled_stm) {
  DEBUG_MSG("Creating label node");
  TreeNode* node = allocTreeNode(27);
  setName(node, label);
  insertChild(node, unlabeled_stm, TreeNodeTy);
  return node;
}

TreeNode* createVariableNode(char* var_name) {
  DEBUG_MSG("Creating variable node");
  TreeNode* node = allocTreeNode(21);

  setName(node, var_name);

  return node;
}

TreeNode* createArrayVariableNode(char* var_name, List* bracket_values) {
  DEBUG_MSG("Creating array variable node");
  TreeNode* node = allocTreeNode(22);

  setName(node, var_name);

  insertChild(node, bracket_values, ListTy);

  return node;
}

List* createVarBracketList(TreeNode* exp) {
  return allocList(exp, TreeNodeTy);
}

void insertVarBracketList(List* values_list, TreeNode* exp) {
  insertIntoList(values_list, exp, TreeNodeTy);
}

TreeNode* createAssignmentNode(TreeNode* var_name, TreeNode* exp) {
  DEBUG_MSG("Creating assigment node");
  TreeNode* node = allocTreeNode(16);

  insertChild(node, var_name, TreeNodeTy);
  insertChild(node, exp, TreeNodeTy);

  return node;
}

TreeNode* createGotoNode(char* label) {
  DEBUG_MSG("Creating goto node");
  TreeNode* node = allocTreeNode(13);

  setName(node, label);

  return node;
}

TreeNode* createReturnNode() {
  DEBUG_MSG("Creating return node");
  TreeNode* node = allocTreeNode(14);
  return node;
}

TreeNode* createReturnValueNode(TreeNode* exp) {
  DEBUG_MSG("Creating return with value node");
  TreeNode* node = allocTreeNode(15);

  insertChild(node, exp, TreeNodeTy);

  return node;
}

List* createUnlabeledStmList(TreeNode* unlabeled_stm) {
  return allocList(unlabeled_stm, TreeNodeTy);
}

void insertUnlabeledStmList(List* stm_list, TreeNode* unlabeled_stm) {
  insertIntoList(stm_list, unlabeled_stm, TreeNodeTy);
}

TreeNode* createIfNode(TreeNode* exp, List* if_body) {
  DEBUG_MSG("Creating if node");
  TreeNode* node = allocTreeNode(11);

  insertChild(node, exp, TreeNodeTy);
  insertChild(node, if_body, ListTy);

  return node;
}

TreeNode* createIfElseNode(TreeNode* exp, List* if_body, List* else_body) {
  DEBUG_MSG("Creating ifelse node");
  TreeNode* node = allocTreeNode(12);

  insertChild(node, exp, TreeNodeTy);
  insertChild(node, if_body, ListTy);
  insertChild(node, else_body, ListTy);

  return node;
}

TreeNode* createCompoundNode(List* compound) {
  DEBUG_MSG("Creating compound node");
  TreeNode *node = allocTreeNode(32);

  insertChild(node, compound, ListTy);
  return node;
}

TreeNode* createSimpleExpNode(int minus_op, TreeNode* term1, List* tail) {
  DEBUG_MSG("Creating simple expression node");
  TreeNode *node = allocTreeNode(28);

  node->value = minus_op;
  insertChild(node, term1, TreeNodeTy);
  insertChild(node, tail, ListTy);
  return node;
}

TreeNode* createMultTermNode(TreeNode* factor1, List* tail) {
  DEBUG_MSG("Creating term node");
  TreeNode *node = allocTreeNode(29);

  insertChild(node, factor1, TreeNodeTy);
  insertChild(node, tail, ListTy);
  return node;
}

List* createAdditiveList(int op, TreeNode* term) {
  TreeNode* node = allocTreeNode(30);
  node->value = op;
  insertChild(node, term, TreeNodeTy);
  return allocList(node, TreeNodeTy);
}

void insertAdditiveList(List* list, int op, TreeNode* term) {
  TreeNode* node = allocTreeNode(30);
  node->value = op;
  insertChild(node, term, TreeNodeTy);
  insertIntoList(list, node, TreeNodeTy); 
}

List* createMultiplicativeList(int op, TreeNode* factor) {
  TreeNode* node = allocTreeNode(31);
  node->value = op;
  insertChild(node, factor, TreeNodeTy);
  return allocList(node, TreeNodeTy);
}

void insertMultiplicativeList(List* list, int op, TreeNode* factor) {
  TreeNode* node = allocTreeNode(31);
  node->value = op;
  insertChild(node, factor, TreeNodeTy);
  insertIntoList(list, node, TreeNodeTy);
}

TreeNode* createNegationNode(TreeNode* factor) {
  DEBUG_MSG("Creating negation node");
  TreeNode* node = allocTreeNode(17);

  insertChild(node, factor, TreeNodeTy);

  return node;
}

TreeNode* createCallNode(char* func_name, List* params) {
  DEBUG_MSG("Creating call node");
  TreeNode* node = allocTreeNode(6);

  setName(node, func_name);

  insertChild(node, params, ListTy);

  return node;
}

List* createExpList(TreeNode* exp) {
  return allocList(exp, TreeNodeTy);
}

void insertExpList(List* exp_list, TreeNode* exp) {
  insertIntoList(exp_list, exp, TreeNodeTy);
}

TreeNode* createWhileNode(TreeNode* exp, List* body) {
  DEBUG_MSG("Creating while node");
  TreeNode* node = allocTreeNode(10);

  insertChild(node, exp, TreeNodeTy);
  insertChild(node, body, ListTy);

  return node;
}

TreeNode* createRelationalExpNode(TreeNode* exp1, int rel_op, TreeNode* exp2) {
  DEBUG_MSG("Creating relational exp node");
  TreeNode* node = allocTreeNode(20);

  insertChild(node, exp1, TreeNodeTy);
  insertChild(node, exp2, TreeNodeTy);
  node->value = rel_op;
  return node;
}
