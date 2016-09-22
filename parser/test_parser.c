/*
   Test of the parser for SL.
   
   Prints only correctness or error messages.

   Returns code execution 0 even in case of errors so as not to
   confuse SuSy.
*/

/* Last update: "test_parser.c: 2015-07-22 (Wed)  17:41:14 BRT (tk)" */

#include <stdio.h>
#include <stdlib.h>
#include "test_parser.h"

extern char *yytext;
#ifdef YYDEBUG
   extern int yydebug; /* debug */
#endif

extern int line_num;

int yyerror(char *s) {
  
  printf("Error detected on line %d.\n",line_num);
  printf("Last token read: '%s'\n\n",yytext);
  return 0;
  
}


int main(int argc, char ** argv){

  int error;
#ifdef YYDEBUG
  yydebug = 1; /* debug */
#endif  
  error = yyparse();
        
  if (error==0)
    printf("Program syntactically correct\n\n");
        
  return 0;
        
}

