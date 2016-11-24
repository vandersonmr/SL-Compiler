%{
#include "tree.h"
#include "parser.h"

int line_num = 1;

%}

%x comment


%%
[ \t] ; /* Blank Spaces */
[\n]  ++line_num;

"//".*  ; /* One line comment */
"/*"    BEGIN(comment);

<comment>[^*\n]*        ;
<comment>"*"+[^*/\n]*   ;
<comment>\n             ++line_num;
<comment>"*"+"/"        BEGIN(INITIAL);
<comment><<EOF>>        return UNFINISHED_COMMENT;

void      return VOID;
labels    return LABELS;
types     return TYPES;
vars      return VARS;
functions return FUNCTIONS;
var       return VAR;
goto      return GOTO;
return    return RETURN;
if        return IF;
while     return WHILE;
else      return ELSE;

"="  return ASSIGN; 

"==" { yylval.intval = '='; return EQUAL; }
"!=" { yylval.intval = '#'; return DIFFERENT; }
"<=" { yylval.intval = '('; return LESS_OR_EQUAL; }
"<"  { yylval.intval = '<'; return LESS; }
">=" { yylval.intval = ')'; return GREATER_OR_EQUAL; }
">"  { yylval.intval = '>'; return GREATER; }

"+"  { yylval.intval = '+'; return PLUS; };
"-"  { yylval.intval = '-'; return MINUS; };

"*"  { yylval.intval = '*'; return MULTIPLY; };
"/"  { yylval.intval = '/'; return DIV; }

"&&" { yylval.intval = '&'; return AND; }
"||" { yylval.intval = '|'; return OR; }
"}"  return CLOSE_BRACE;
"]"  return CLOSE_BRACKET;
")"  return CLOSE_PAREN;
":"  return COLON;
","  return COMMA;
"!"  return NOT;
"{"  return OPEN_BRACE;
"["  return OPEN_BRACKET;
"("  return OPEN_PAREN;
";"  return SEMI_COLON;

"true"|"false"|"integer"|"boolean"|"read"|"write"|[a-zA-Z]+[a-zA-Z0-9]* {
  yylval.strval = malloc(strlen(yytext));
  strcpy(yylval.strval, yytext);
  return IDENTIFIER;
}

[0-9]+ {
  yylval.intval = atoi(yytext);
  return INTEGER;
}

<<EOF>> return END_OF_FILE;

. return LEXICAL_ERROR;

%%

int yywrap() {
  return 1;
}
