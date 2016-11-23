/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_PARSER_H_INCLUDED
# define YY_YY_PARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    VOID = 258,
    LABELS = 259,
    TYPES = 260,
    VARS = 261,
    FUNCTIONS = 262,
    VAR = 263,
    GOTO = 264,
    RETURN = 265,
    IF = 266,
    WHILE = 267,
    ELSE = 268,
    IDENTIFIER = 269,
    OPEN_PAREN = 270,
    OPEN_BRACKET = 271,
    CLOSE_PAREN = 272,
    CLOSE_BRACKET = 273,
    EQUAL = 274,
    ASSIGN = 275,
    DIFFERENT = 276,
    LESS_OR_EQUAL = 277,
    LESS = 278,
    GREATER_OR_EQUAL = 279,
    GREATER = 280,
    PLUS = 281,
    MINUS = 282,
    MULTIPLY = 283,
    DIV = 284,
    AND = 285,
    OR = 286,
    CLOSE_BRACE = 287,
    OPEN_BRACE = 288,
    COLON = 289,
    COMMA = 290,
    NOT = 291,
    SEMI_COLON = 292,
    INTEGER = 293,
    UNFINISHED_COMMENT = 294,
    LEXICAL_ERROR = 295,
    END_OF_FILE = 296
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 5 "parser.y" /* yacc.c:1909  */

  char *strval;
  int intval;
  TreeNode* nodeval;
  List* listval;

#line 103 "parser.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_H_INCLUDED  */
