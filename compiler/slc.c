/*
   Test of the SL compiler.
   
   Returns code execution 0 even in case of errors so as not to
   confuse SuSy.
   
*/

/* Last update: "slc.c: 2016-07-29 (Fri)  15:21:32 BRT (tk)" */

#define MAIN

#include <stdio.h>
#include <stdlib.h>
#include "slc.h"
#include "tree.h"
#include "codegen.h"

extern int line_num;
extern char *yytext;

void SemanticError(char *s) {
  printf("Semantic error.\n");
  printf("%s", s);
  exit(0);
}

int yyerror(char *s) {
  printf("Lexical or syntactical error.\n");
  exit(0);
}

int main(int argc, char **argv) {
  int sh;
  int error;

  error = yyparse();
  if (error!=0) 
    return 0;  // error message printed already

  sh = stackHeight();
  if (sh>1) {
    printf("Stack hight: %d; execution aborted\n",sh);
  } else 
    processProgram(getTree()); // generates code
  return 0;
} // main
