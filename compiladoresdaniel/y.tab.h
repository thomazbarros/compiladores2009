/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     TK_INT = 258,
     TK_STRING = 259,
     TK_DOUBLE = 260,
     TK_BOOL = 261,
     TK_CHAR = 262,
     TK_ID = 263,
     TK_TIPO_INT = 264,
     TK_TIPO_STRING = 265,
     TK_TIPO_DOUBLE = 266,
     TK_TIPO_BOOL = 267,
     TK_TIPO_CHAR = 268,
     TK_ATRIBUICAO = 269,
     TK_ERR = 270,
     TK_MAIN = 271,
     TK_INI = 272,
     TK_FIM = 273,
     TK_LER = 274,
     TK_ESCREVER = 275,
     TK_DESVIO = 276,
     TK_DESVIO_2 = 277,
     TK_LACO = 278,
     TK_LACO_2 = 279,
     TK_ACAO = 280,
     TK_DE = 281,
     TK_PARA = 282,
     TK_FACA = 283,
     TK_CONST = 284,
     TK_RET = 285,
     TK_DIFF = 286,
     TK_L_OR_E = 287,
     TK_G_OR_E = 288
   };
#endif
/* Tokens.  */
#define TK_INT 258
#define TK_STRING 259
#define TK_DOUBLE 260
#define TK_BOOL 261
#define TK_CHAR 262
#define TK_ID 263
#define TK_TIPO_INT 264
#define TK_TIPO_STRING 265
#define TK_TIPO_DOUBLE 266
#define TK_TIPO_BOOL 267
#define TK_TIPO_CHAR 268
#define TK_ATRIBUICAO 269
#define TK_ERR 270
#define TK_MAIN 271
#define TK_INI 272
#define TK_FIM 273
#define TK_LER 274
#define TK_ESCREVER 275
#define TK_DESVIO 276
#define TK_DESVIO_2 277
#define TK_LACO 278
#define TK_LACO_2 279
#define TK_ACAO 280
#define TK_DE 281
#define TK_PARA 282
#define TK_FACA 283
#define TK_CONST 284
#define TK_RET 285
#define TK_DIFF 286
#define TK_L_OR_E 287
#define TK_G_OR_E 288




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

