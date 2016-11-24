%{
#include "tree.h"
%}

%union{
  char *strval;
  int intval;
  TreeNode* nodeval;
  List* listval;
}

%token VOID LABELS TYPES VARS FUNCTIONS VAR GOTO RETURN IF WHILE ELSE 
IDENTIFIER OPEN_PAREN OPEN_BRACKET CLOSE_PAREN CLOSE_BRACKET EQUAL ASSIGN
DIFFERENT LESS_OR_EQUAL LESS GREATER_OR_EQUAL GREATER PLUS MINUS MULTIPLY
DIV AND OR CLOSE_BRACE OPEN_BRACE COLON COMMA NOT SEMI_COLON INTEGER 
UNFINISHED_COMMENT LEXICAL_ERROR END_OF_FILE

%type <strval> IDENTIFIER
%type <intval> INTEGER relational_operator plus_or_minus additive_operator 
multiplicative_operator EQUAL DIFFERENT LESS LESS_OR_EQUAL GREATER_OR_EQUAL 
GREATER MINUS PLUS OR DIV AND MULTIPLY;
%type <nodeval> function function_declaration block statement unlabeled_statement
assignment function_call_statement goto return conditional repetitive expression
function_parameter expression_parameter formal_parameter variable function_call
term factor type empty_statement simple_expression
%type <listval> formal_parameterLoop identifier_list types_assigLoop bracketLoop 
variablesLoop functionLoop statementLoop variables functions body labels types
formal_parameters varBracketLoop unlabeled_statementLoop expression_list compound
multiplicativeLoop additiveLoop

%start program

%%

program: function END_OF_FILE { createProgramNode($1); return 0; }
        ;

function: VOID function_declaration       { $$ = createVoidFunctionNode($2); }
        | IDENTIFIER function_declaration { $$ = createFunctionNode($1, $2); }
        ;

function_declaration: IDENTIFIER formal_parameters block
                  {
                    $$ = createFuncDeclarationNode($1, $2, $3);
                  }

block: labels types variables functions body
     {
      $$ = createBlockNode($1, $2, $3, $4, $5);
     }

labels: LABELS identifier_list SEMI_COLON { $$ = $2; }
      | { $$ = 0;};

types: TYPES types_assigLoop { $$ = $2; } | { $$ = 0; };

types_assigLoop: IDENTIFIER ASSIGN type SEMI_COLON { $$ = createTypeList($1, $3); }
               | types_assigLoop IDENTIFIER ASSIGN type SEMI_COLON 
               {
                insertTypeList($1, $2, $4);
                $$ = $1;
               }

variables: VARS variablesLoop { $$ = $2; } | { $$ = 0; };

variablesLoop: identifier_list COLON type SEMI_COLON
             {
              $$ = createVariableList($1, $3);
             }
             | variablesLoop identifier_list COLON type SEMI_COLON 
             {
              insertVariableList($1, $2, $4);
              $$ = $1;
             };

functions: FUNCTIONS functionLoop { $$ = $2; } | { $$ = 0; };

functionLoop: function { $$ = createFunctionList($1); }
            | functionLoop function { insertFunctionList($1, $2); $$ = $1; }

body: OPEN_BRACE CLOSE_BRACE { $$ = 0; }
    | OPEN_BRACE statementLoop CLOSE_BRACE { $$ = $2; };

statementLoop: statementLoop statement { insertStatementList($1, $2); $$ = $1; }
             | statement { $$ = createStatementList($1); };

type: IDENTIFIER { $$ = createTypeNode($1); }
    | IDENTIFIER bracketLoop {$$ = createArrayTypeNode($1, $2); };

bracketLoop: OPEN_BRACKET INTEGER CLOSE_BRACKET { $$ = createIntList($2); }
           | bracketLoop OPEN_BRACKET INTEGER CLOSE_BRACKET 
           {
            insertIntList($1, $3);
            $$ = $1;
           };

formal_parameters: OPEN_PAREN formal_parameterLoop CLOSE_PAREN 
                 {
                    $$ = $2;
                 }
                 | OPEN_PAREN CLOSE_PAREN  { $$ = 0; }

formal_parameterLoop: formal_parameter { $$ = createFormalParamList($1); }
                    | formal_parameterLoop SEMI_COLON formal_parameter
                    {
                      insertFormalParamList($1, $3);
                      $$ = $1;
                    };

formal_parameter: expression_parameter { $$ = $1; } | function_parameter { $$ = $1; };

expression_parameter: identifier_list COLON IDENTIFIER
                    {
                      $$ = createExpParamNode(0, $1, $3);
                    }
                    | VAR identifier_list COLON IDENTIFIER
                    {
                      $$ = createExpParamNode(1, $2, $4);
                    }

function_parameter: IDENTIFIER IDENTIFIER formal_parameters
                  {
                    $$ = createFuncParamNode($1, $2, $3);
                  }
                 | VOID IDENTIFIER formal_parameters
                  {
                    $$ = createFuncParamNode(0, $2, $3);
                  };

statement: IDENTIFIER COLON unlabeled_statement
         {
          $$ = createLabeledStatementNode($1, $3);
         }
         | unlabeled_statement { $$ = $1; }
         | compound { $$ = createCompoundNode($1); };

variable: IDENTIFIER { $$ = createVariableNode($1); }
        | IDENTIFIER varBracketLoop { $$ = createArrayVariableNode($1, $2); };

varBracketLoop: OPEN_BRACKET expression CLOSE_BRACKET
              {
                $$ = createVarBracketList($2);
              }
              | varBracketLoop OPEN_BRACKET expression CLOSE_BRACKET
              {
                insertVarBracketList($1, $3);
                $$ = $1;
              };

unlabeled_statement: assignment { $$ = $1; }
                   | function_call_statement { $$ = $1; }
                   | goto { $$ = $1; } | return { $$ = $1; }
                   | conditional { $$ = $1; } | repetitive { $$ = $1; }
                   | empty_statement { $$ = $1; };

assignment: variable ASSIGN expression SEMI_COLON
          {
            $$ = createAssignmentNode($1, $3);
          };

function_call_statement: function_call SEMI_COLON { $$ = $1; };

goto: GOTO IDENTIFIER SEMI_COLON { $$ = createGotoNode($2); };

return: RETURN SEMI_COLON { $$ = createReturnNode(); }
      | RETURN expression SEMI_COLON { $$ = createReturnValueNode($2); };

compound: OPEN_BRACE unlabeled_statementLoop CLOSE_BRACE { $$ = $2; };

unlabeled_statementLoop: unlabeled_statement { $$ = createUnlabeledStmList($1); }
                       | unlabeled_statementLoop unlabeled_statement 
                       {
                        insertUnlabeledStmList($1, $2);
                        $$ = $1;
                       }

conditional: IF OPEN_PAREN expression CLOSE_PAREN compound
           {
            $$ = createIfNode($3, $5);
           }
           | IF OPEN_PAREN expression CLOSE_PAREN compound ELSE compound 
           {
            $$ = createIfElseNode($3, $5, $7);
           };

repetitive: WHILE OPEN_PAREN expression CLOSE_PAREN compound
          {
            $$ = createWhileNode($3, $5);
          };

empty_statement: SEMI_COLON { $$ = 0; };

expression: simple_expression { $$ = $1; }
          | simple_expression relational_operator simple_expression
          {
            $$ = createRelationalExpNode($1, $2, $3);
          };

relational_operator: EQUAL { $$ = $1; } | DIFFERENT { $$ = $1; } | LESS { $$ = $1; } 
                   | LESS_OR_EQUAL { $$ = $1; } | GREATER_OR_EQUAL { $$ = $1; } 
                   | GREATER { $$ = $1; };

plus_or_minus: PLUS { $$ = $1; } | MINUS { $$ = $1; } | { $$ = 0; };

simple_expression: plus_or_minus term additiveLoop
                 {
                  $$ = createSimpleExpNode($1, $2, $3);
                 }
                 | plus_or_minus term
                 {
                  $$ = createSimpleExpNode($1, $2, 0);
                 }


additiveLoop: additive_operator term { $$ = createAdditiveList($1, $2); }
            | additiveLoop additive_operator term
            {
              insertAdditiveList($1,$2,$3);
              $$ = $1;
            }

additive_operator: PLUS { $$ = $1; } | MINUS { $$ = $1; } | OR { $$ = $1; };

term: factor multiplicativeLoop
    {
      $$ = createMultTermNode($1, $2);
    }
    | factor
    {
      $$ = createMultTermNode($1, 0);
    };

multiplicativeLoop: multiplicative_operator factor
                  {
                    $$ = createMultiplicativeList($1, $2);
                  }
                  | multiplicativeLoop multiplicative_operator factor
                  {
                    insertMultiplicativeList($1, $2, $3);
                  }

multiplicative_operator: MULTIPLY { $$ = $1; } | DIV { $$ = $1; } | AND { $$ = $1; };

factor:  variable { $$ = $1; } | INTEGER { $$ = createIntNode($1); }
       | function_call { $$ = $1; } | OPEN_PAREN expression CLOSE_PAREN { $$ = $2; }
       | NOT factor { $$ = createNegationNode($2); };

function_call: IDENTIFIER OPEN_PAREN expression_list CLOSE_PAREN { $$ = createCallNode($1, $3); }
             | IDENTIFIER OPEN_PAREN CLOSE_PAREN { $$ = createCallNode($1, 0); };

identifier_list: IDENTIFIER { $$ = createIdentifierList($1); }
               | identifier_list COMMA IDENTIFIER
               {
                insertIdentifierList($1, $3);
                $$ = $1;
               };

expression_list: expression { $$ = createExpList($1); }
               | expression_list COMMA expression { insertExpList($1, $3); $$ = $1; };
