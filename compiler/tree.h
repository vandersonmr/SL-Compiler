#ifndef TREE_INCLUDED
#define TREE_INCLUDED

#include <stdlib.h>
#include "list.h"

extern void *getTree();
extern void counts(void*, int*, int*, int*, int*, int*);

#define TreeNode struct TreeNodeStruct

struct TreeNodeStruct {
  int node_type;
  char* name;
  char* type;
  int value;
  TreeNode* pair;
  List* nodes;
};

void createProgramNode(TreeNode*);
TreeNode* createVoidFunctionNode(TreeNode*);
TreeNode* createFunctionNode(char*, TreeNode*);
TreeNode* createFormalParamNode(List*);
TreeNode* createFuncDeclarationNode(char*, List*, TreeNode*);
List* createIntList(int);
void insertIntList(List*, int);
List* createIdentifierList(char*);
void insertIdentifierList(List*, char*);
TreeNode* createVariablesNode(List*);
List* createVariableList(List*, TreeNode*);
void insertVariableList(List*, List*, TreeNode*);
TreeNode* createFunctionsNode(List*);
List* createFunctionList(TreeNode*);
void insertFunctionList(List*, TreeNode*);
TreeNode* createBlockNode(List*, List*, List*, List*, List*);
List* createTypeList(char*, TreeNode*);
void insertTypeList(List*, char*, TreeNode*);
List* createStatementList(TreeNode*);
void insertStatementList(List*, TreeNode*);
TreeNode* createTypeNode(char*);
TreeNode* createArrayTypeNode(char*, List*);
List* createFormalParamList(TreeNode*);
void insertFormalParamList(List*, TreeNode*);
TreeNode* createExpParamNode(int, List*, char*);
TreeNode* createFuncParamNode(char*, char*, List*);
TreeNode* createLabeledStatementNode(char*, TreeNode*);
TreeNode* createVariableNode(char*);
TreeNode* createArrayVariableNode(char*, List*);
List* createVarBracketList(TreeNode*);
void insertVarBracketList(List*, TreeNode*);
TreeNode* createReturnNode();
TreeNode* createAssignmentNode(TreeNode*, TreeNode*);
TreeNode* createGotoNode(char*);
TreeNode* createReturnValueNode(TreeNode*);
List* createUnlabeledStmList(TreeNode*);
void insertUnlabeledStmList(List*, TreeNode*);
TreeNode* createIfNode(TreeNode*, List*);
TreeNode* createIfElseNode(TreeNode*, List*, List*);
TreeNode* createWhileNode(TreeNode*, List*);
TreeNode* createRelationalExpNode(TreeNode*, int, TreeNode*);
TreeNode* createSimpleExpNode(int, TreeNode*, List*);
List* createAdditiveList(int, TreeNode*);
void insertAdditiveList(List*, int, TreeNode*);
TreeNode* createMultTermNode(TreeNode*, List*);
List* createMultiplicativeList(int, TreeNode*);
void insertMultiplicativeList(List*, int, TreeNode*);
TreeNode* createIntNode(int);
TreeNode* createNegationNode(TreeNode*);
TreeNode* createCallNode(char*, List*);
List* createExpList(TreeNode*);
void insertExpList(List*, TreeNode*);
TreeNode* createCompoundNode(List*);

void* getChild(TreeNode*, int);
#endif
