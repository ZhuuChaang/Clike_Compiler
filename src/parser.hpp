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

#ifndef YY_YY_PARSER_HPP_INCLUDED
# define YY_YY_PARSER_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 1 "parser.y"

    #include "ast.hpp"
    #include <string>
    #include<iostream>

#line 55 "parser.hpp"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    CHAR = 258,                    /* CHAR  */
    DOUBLE = 259,                  /* DOUBLE  */
    FLOAT = 260,                   /* FLOAT  */
    INT = 261,                     /* INT  */
    SHORT = 262,                   /* SHORT  */
    LONG = 263,                    /* LONG  */
    VOID = 264,                    /* VOID  */
    ENUM = 265,                    /* ENUM  */
    UNION = 266,                   /* UNION  */
    STRUCT = 267,                  /* STRUCT  */
    TRUE = 268,                    /* TRUE  */
    FALSE = 269,                   /* FALSE  */
    FOR = 270,                     /* FOR  */
    DO = 271,                      /* DO  */
    WHILE = 272,                   /* WHILE  */
    BREAK = 273,                   /* BREAK  */
    CONTINUE = 274,                /* CONTINUE  */
    IF = 275,                      /* IF  */
    ELSE = 276,                    /* ELSE  */
    GOTO = 277,                    /* GOTO  */
    SWITCH = 278,                  /* SWITCH  */
    CASE = 279,                    /* CASE  */
    DEFAULT = 280,                 /* DEFAULT  */
    RETURN = 281,                  /* RETURN  */
    STATIC = 282,                  /* STATIC  */
    CONST = 283,                   /* CONST  */
    SIZEOF = 284,                  /* SIZEOF  */
    TYPEDEF = 285,                 /* TYPEDEF  */
    CONDITION = 286,               /* CONDITION  */
    DOT = 287,                     /* DOT  */
    ARROW = 288,                   /* ARROW  */
    SEMICOLON = 289,               /* SEMICOLON  */
    COLON = 290,                   /* COLON  */
    LPAREN = 291,                  /* LPAREN  */
    RPAREN = 292,                  /* RPAREN  */
    LBRACKET = 293,                /* LBRACKET  */
    RBRACKET = 294,                /* RBRACKET  */
    LBRACE = 295,                  /* LBRACE  */
    RBRACE = 296,                  /* RBRACE  */
    PTRDEC = 297,                  /* PTRDEC  */
    ARRAYTAG = 298,                /* ARRAYTAG  */
    ADD = 299,                     /* ADD  */
    SUB = 300,                     /* SUB  */
    MUL = 301,                     /* MUL  */
    DIV = 302,                     /* DIV  */
    MOD = 303,                     /* MOD  */
    INC = 304,                     /* INC  */
    DEC = 305,                     /* DEC  */
    EQ = 306,                      /* EQ  */
    NE = 307,                      /* NE  */
    GT = 308,                      /* GT  */
    LT = 309,                      /* LT  */
    GE = 310,                      /* GE  */
    LE = 311,                      /* LE  */
    AND = 312,                     /* AND  */
    OR = 313,                      /* OR  */
    NOT = 314,                     /* NOT  */
    BAND = 315,                    /* BAND  */
    BOR = 316,                     /* BOR  */
    BXOR = 317,                    /* BXOR  */
    BNOT = 318,                    /* BNOT  */
    SHL = 319,                     /* SHL  */
    SHR = 320,                     /* SHR  */
    ASSIGN = 321,                  /* ASSIGN  */
    ADDAS = 322,                   /* ADDAS  */
    SUBAS = 323,                   /* SUBAS  */
    MULAS = 324,                   /* MULAS  */
    DIVAS = 325,                   /* DIVAS  */
    MODAS = 326,                   /* MODAS  */
    BANDAS = 327,                  /* BANDAS  */
    BORAS = 328,                   /* BORAS  */
    BXORAS = 329,                  /* BXORAS  */
    SHLAS = 330,                   /* SHLAS  */
    SHRAS = 331,                   /* SHRAS  */
    COMMA = 332,                   /* COMMA  */
    INTEGER_VAR = 333,             /* INTEGER_VAR  */
    REAL_VAR = 334,                /* REAL_VAR  */
    STRING_VAR = 335,              /* STRING_VAR  */
    CHAR_VAR = 336,                /* CHAR_VAR  */
    IDENTIFER = 337,               /* IDENTIFER  */
    FUNC_CALL_ARG_LIST = 338,      /* FUNC_CALL_ARG_LIST  */
    UMINUS = 339                   /* UMINUS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 27 "parser.y"

    int INT_value;
    double REAL_value;
    std::string* STRING_value;
    char CHAR_value;

    std::string* IDENTIFER_value;

    Node* AST_NODE_value;
    Program* AST_PROG_value;
    Type* AST_TYPE_value;
    Builtintype* AST_BUILTinTYPE_value;
    IdentifierList* AST_IDLIST_value;
    Enum* AST_ENUM_value;
    Enumlist* AST_ENUMLIST_value;
    SUmemdec* AST_SUDEC_value;
    SUdecllist* AST_SUDECLIST_value;
    funArgList* AST_FUNARGLIST_value;

    Stmt* AST_STMT_value;
    Globalstmt* AST_GSTMT_value;
    Basestmt* AST_BSTMT_value;
    Scope* AST_SCOPE_value;
    InitID * AST_IID_value;
    InitIDList* AST_IIDLIST_value;
    Elseifflow* AST_ELIF_value;
    Elseflow* AST_ELSE_value;
    Caselist* AST_CASELIST_value;
    Case* AST_CASE_value;

    Constant* AST_CONSTANT_value;
    Expr* AST_EXPR_value;
    int int_value;
    CallArgList* AST_CALLARGLIST_value;
    FuncCall* AST_FUNCALL_value;
    int token;

#line 194 "parser.hpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_HPP_INCLUDED  */
