/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_H_INCLUDED
# define YY_YY_PARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    PLUS = 258,                    /* PLUS  */
    MULT = 259,                    /* MULT  */
    MINUS = 260,                   /* MINUS  */
    DIV = 261,                     /* DIV  */
    O_PAREN = 262,                 /* O_PAREN  */
    C_PAREN = 263,                 /* C_PAREN  */
    SEMICOLON = 264,               /* SEMICOLON  */
    LESS = 265,                    /* LESS  */
    LESS_EQUALS = 266,             /* LESS_EQUALS  */
    GREATER = 267,                 /* GREATER  */
    GREATER_EQUALS = 268,          /* GREATER_EQUALS  */
    EQUALS = 269,                  /* EQUALS  */
    EQUALS_EQUALS = 270,           /* EQUALS_EQUALS  */
    NOT_EQUALS = 271,              /* NOT_EQUALS  */
    COMMA = 272,                   /* COMMA  */
    O_BRACE = 273,                 /* O_BRACE  */
    C_BRACE = 274,                 /* C_BRACE  */
    O_BRACK = 275,                 /* O_BRACK  */
    C_BRACK = 276,                 /* C_BRACK  */
    IF = 277,                      /* IF  */
    WHILE = 278,                   /* WHILE  */
    ELSE = 279,                    /* ELSE  */
    INT = 280,                     /* INT  */
    RETURN = 281,                  /* RETURN  */
    VOID = 282,                    /* VOID  */
    NUM = 283,                     /* NUM  */
    ID = 284,                      /* ID  */
    ERROR = 285                    /* ERROR  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 13 "myParser.y"

    struct decl *decl;
    struct param * param;
    struct comp_stmt * compStmt;
    struct stmt * stmt;
    struct expr *expr;
    struct var * var;
    struct simple_expr * simple_expr;
    struct add_expr * add_expr;
    struct term * term;
    struct factor * factor;
    struct call * call;
    struct argsList * argsList;
    struct args * args;

    char *id;
    int num;

#line 113 "parser.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_H_INCLUDED  */
