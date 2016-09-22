%{
#define YYSTYPE double
#include "test/test_parser.h"
%}

%token VOID LABELS TYPES VARS FUNCTIONS VAR GOTO RETURN IF WHILE ELSE 
IDENTIFIER OPEN_PAREN OPEN_BRACKET CLOSE_PAREN CLOSE_BRACKET EQUAL ASSIGN
DIFFERENT LESS_OR_EQUAL LESS GREATER_OR_EQUAL GREATER PLUS MINUS MULTIPLY
DIV AND OR CLOSE_BRACE OPEN_BRACE COLON COMMA NOT SEMI_COLON INTEGER 
UNFINISHED_COMMENT LEXICAL_ERROR END_OF_FILE

%start program

%%

program: function END_OF_FILE { return 0; }
        ;

function: VOID function_declaration
        | IDENTIFIER function_declaration
        ;

function_declaration: IDENTIFIER formal_parameters block;

block: labels types variables functions body

labels: LABELS identifier_list SEMI_COLON | %empty;

types: TYPES types_assigLoop | %empty;

types_assigLoop: IDENTIFIER ASSIGN type SEMI_COLON
               | types_assigLoop IDENTIFIER ASSIGN type SEMI_COLON

variables: VARS variablesLoop | %empty;

variablesLoop: identifier_list COLON type SEMI_COLON 
             | variablesLoop identifier_list COLON type SEMI_COLON;

functions: FUNCTIONS functionLoop | %empty;

functionLoop: function
            | functionLoop function

body: OPEN_BRACE CLOSE_BRACE
    | OPEN_BRACE statementLoop CLOSE_BRACE;

statementLoop: statementLoop statement
             | statement;

type: IDENTIFIER
    | IDENTIFIER bracketLoop;

bracketLoop: OPEN_BRACKET INTEGER CLOSE_BRACKET
           | bracketLoop OPEN_BRACKET INTEGER CLOSE_BRACKET;

formal_parameters: OPEN_PAREN formal_parameterLoop CLOSE_PAREN
                 | OPEN_PAREN CLOSE_PAREN;

formal_parameterLoop: formal_parameter
                    | formal_parameterLoop SEMI_COLON formal_parameter;

formal_parameter: expression_parameter | function_parameter;

expression_parameter: identifier_list COLON IDENTIFIER
                    | VAR identifier_list COLON IDENTIFIER;

function_parameter: IDENTIFIER IDENTIFIER formal_parameters
                 | VOID IDENTIFIER formal_parameters;

statement: IDENTIFIER COLON unlabeled_statement
         | unlabeled_statement
         | compound;

variable: IDENTIFIER 
        | IDENTIFIER varBracketLoop;

varBracketLoop: OPEN_BRACKET expression CLOSE_BRACKET
              | varBracketLoop OPEN_BRACKET expression CLOSE_BRACKET;

unlabeled_statement: assignment | function_call_statement | goto | return
                   | conditional | repetitive | empty_statement;

assignment: variable ASSIGN expression SEMI_COLON;

function_call_statement: function_call SEMI_COLON;

goto: GOTO IDENTIFIER SEMI_COLON;

return: RETURN SEMI_COLON
      | RETURN expression SEMI_COLON;

compound: OPEN_BRACE unlabeled_statementLoop CLOSE_BRACE;

unlabeled_statementLoop: unlabeled_statement
                       | unlabeled_statementLoop unlabeled_statement

conditional: IF OPEN_PAREN expression CLOSE_PAREN compound
           | IF OPEN_PAREN expression CLOSE_PAREN compound ELSE compound;

repetitive: WHILE OPEN_PAREN expression CLOSE_PAREN compound;

empty_statement: SEMI_COLON;

expression: simple_expression 
          | simple_expression relational_operator simple_expression;

relational_operator: EQUAL | DIFFERENT | LESS | LESS_OR_EQUAL 
                   | GREATER_OR_EQUAL | GREATER;

plus_or_minus: PLUS | MINUS;

simple_expression: plus_or_minus term additive_operator term
                 | plus_or_minus term
                 | term
                 | term additive_operator term;

additive_operator: PLUS | MINUS | OR;

term: factor
    | factor multiplicative_operator factor;

multiplicative_operator: MULTIPLY | DIV | AND;

factor: variable | INTEGER | function_call | OPEN_PAREN expression CLOSE_PAREN
       | NOT factor;

function_call: IDENTIFIER OPEN_PAREN expression_list CLOSE_PAREN
             | IDENTIFIER OPEN_PAREN CLOSE_PAREN;

identifier_list: IDENTIFIER
               | identifier_list COMMA IDENTIFIER;

expression_list: expression
               | expression_list COMMA expression; 
