%{
#include<string>
#include<iostream>
#include "ast.h"
_AST_H_

%}

%union{
    int* INT_value;
    double* REAl_value;
    std::string* STRING_value;
    char* CHAR_value;
    std::string* IDENTIFER_value;
    Node* AST_NODE_value;
}

%token CHAR,DOUBLE,FLOAT,INT,SHORT,LONG,VOID,ENUM,UNION,STRUCT,TRUE,FALSE
       FOR,DO,WHILE,BREAK,CONTINUE,IF,ELSE,GOTO,SWITCH,CASE,DEFAULT,RETURN,
       STATIC,CONST,SIZEOF,TYPEDEF,
       ADD,SUB,MUL,DIV,MOD,INC,DEC,
       EQ,NE,GT,LT,GE,LE,AND,OR,NOT,
       BAND,BOR,BXOR,BNOT,SHL,SHR,
       ASSIGN,ADDAS,SUBAS,MULAS,DIVAS,MODAS,
       BANDAS,BORAS,BXORAS,SHLAS,SHRAS,
       CONDITION,DOT,ARROW,COMMA,SEMICOLON,COLON,
       LPAREN,RPAREN,LBRACKET,RBRACKET,LBRACE,RBRACE
       
%token <INT_value> INTEGER_VAR
%token <REAL_value> REAL_VAR
%token <STRING_value> STRING_VAR
%token <CHAR_value> CHAR_VAR
%token <IDENTIFER_value> IDENTIFER;

%type <AST_NODE_value> PROGRAM;

%type <> DNDs


%type <> EXPR
%type <> Decl
%type <> Define

%type <> STMT
%type <> CtrlSTMT

%type <> BINOP
%type <> UNAOP
%type <> SUFOP
%type <> CONSTANT
%type <> TYPE

%type <> FunDECL
%type <> StructDECL
%type <> UnionDECL

%type <>  FunDEF
%type <>  VarDEF
%type <>  StructDEF
%type <>  UnionDEF
%type <>  EnumDEF
%type <>  TypeDEF



%start PROGRAM

%%
PROGRAM:    GlobalSTMT
            ;


// top level statements of the program, including defines and declares of func and global var
GlobalSTMT: GlobalSTMT FunDECL
            | GlobalSTMT FunDEF
            | GlobalSTMT TypeDEF
            | GlobalSTMT VarDEF
            | GlobalSTMT FieldDECL
            |
            ;

//types
TYPE:       _TYPE
            | CONST _TYPE
            | STATIC _TYPE
            ;

_TYPE:      BuiltinTYPE
            | FieldTYPE
            | _TYPE PTR
            | _TYPE ARRAY
            | IDENTIFER
            ;


FieldTYPE:  STRUCT IDENTIFER LBRACE SUSTMT RBRACE
            | UNION IDENTIFER LBRACE SUSTMT RBRACE
            | ENUM IDENTIFER LBRACE EnmLIST RBRACE
            ;

BuiltinTYPE: CHAR
            |DOUBLE
            |FLOAT
            |INT
            |SHORT
            |LONG
            |VOID
            ;


//ptr and array
PTR:        MUL PTR
            |
            ;

ARRAY:      LBRACKET INT RBRACKET ARRAY
            | 
            ;


// function declare and define
FunDECL:    TYPE IDENTIFER LPAREN ArgLIST RPAREN SEMICOLON
            ;

FunDEF:     TYPE IDENTIFER LPAREN ArgLIST RPAREN LBRACE STMT RBRACE
            ;

ArgLIST:	_ArgLIST COMMA TYPE IDENTIFER
			| TYPE IDENTIFER
			|
			;

_ArgLIST:	_ArgLIST COMMA TYPE IDENTIFER
			| TYPE IDENTIFER
			;

//variable define and declare
FieldDECL:  FieldTYPE SEMICOLON
            ;

VarDEF:     TYPE InitIDList SEMICOLON
            ;

SUVarDEF:   TYPE IdList SEMICOLON
            ;


IdList      _IdList COMMA IDENTIFER
            | IDENTIFER
            ;

_IdList     _IdList COMMA IDENTIFER
            | IDENTIFER 
            ;

InitIDList: _InitIDList COMMA Init
            | Init
            ;

_InitIDList: _InitIDList COMMA Init
            | Init
            ;

Init:       IDENTIFER
            | IDENTIFER ASSIGN EXPR
            ;


EnmLIST:    _EnmLIST COMMA Enm
            | Enm
            |
            ;

_EnmLIST:   _EnmLIST COMMA Enm
            | Enm
            ;

Enm:        IDENTIFER
            | IDENTIFER ASSIGN INT
            ;

//type defination
TypeDEF:    TYPEDEF TYPE IDENTIFER SEMICOLON



SCOPE:      LBRACE STMT RBRACE
            ;

// ctrl flow 
CtrlFLOW:   IfFLOW
            | ElseFLOW
            | ElseifFLOW
            | ForFLOW
            | DowhileFLOW
            | WhileFLOW
            | SwitchFLOW
            ;

IfFLOW:     IF LPAREN EXPR RPAREN SCOPE ElseifFLOW ElseFLOW
            | IF LPAREN EXPR RPAREN SEMICOLON
            ;

ElseFLOW:   ELSE SCOPE
            ELSE SEMICOLON

ElseifFLOW: ELSE IF LPAREN EXPR RPAREN SCOPE ElseifFLOW
            |
            ;


ForFLOW:    FOR LPAREN EXPR SEMICOLON EXPR SEMICOLON EXPR RPAREN SEMICOLON
            | FOR LPAREN EXPR SEMICOLON EXPR SEMICOLON EXPR RPAREN LBRACE CtrlSTMT RBRACE
            ;

WhileFLOW:  WHILE LPAREN EXPR RPAREN LBRACE CtrlSTMT RBRACE
            | WHILE LPAREN EXPR RPAREN SEMICOLON
            ;

DowhileFLOW: DO LBRACE CtrlSTMT RBRACE WHILE LPAREN EXPR RPAREN SEMICOLON
            ;      


SwitchFLOW: SWITCH LPAREN EXPR RPAREN LBRACE CaseLIST RBRACE
            ;

CaseLIST:   CaseLIST CaseSTMT
            |
            ;

CaseSTMT:   CASE EXPR COLON STMT BREAK SEMICOLON
            | CASE EXPR COLON STMT
            | DEFAULT EXPR COLON STMT BREAK SEMICOLON
            | DEFAULT EXPR COLON STMT
            ;             

CtrlSTMT:   STMT CtrlSTMT
            | BREAK SEMICOLON
            | CONTINUE SEMICOLON
            |
            ;

// statements
STMT:       STMT SEMICOLON STMT 
            | STMT SEMICOLON
            | CtrlFLOW
            | EXPR SEMICOLON
            | SCOPE
            | TypeDEF
            | VarDEF
            | FieldDECL
            | 
            ;



SUSTMT:     SUSTMT SEMICOLON SUSTMT
            | SUSTMT SEMICOLON
            | SUVarDEF
            |
            ;




//expr            

EXPR:       IDENTIFER
            | FUNCALL
            | CONSTANT
            | EXPR BINOP EXPR
            | UNAOP EXPR
            | EXPR SUFOP
            | LPAREN EXPR RPAREN
            | SIZEOF LPAREN EXPR RPAREN
            | SIZEOF LPAREN TYPE RPAREN
            | EXPR CONDITION EXPR COLON EXPR 
            | LPAREN TYPE RPAREN EXPR
            | EXPR LBRACKET EXPR RBRACKET
            | EXPR ARROW IDENTIFER
            | EXPR DOT IDENTIFER
            ;  

UNAOP       INC
            | DEC
            | NOT
            | BNOT
            | MUL 
            | BAND
            ;

SUFOP       INC
            |DEC            
            ;

BINOP       ADD
            |SUB
            |MUL
            |DIV
            |MOD
            |EQ
            |NE
            |GT
            |LT
            |GE
            |LE
            |AND
            |OR
            |BAND
            |BOR
            |BXOR
            |SHL
            |SHR
            |ASSIGN
            |ADDAS
            |SUBAS
            |MULAS
            |DIVAS
            |MODAS
            |BANDAS
            |BORAS
            |BXORAS
            |SHLAS
            |SHRAS
            |COMMA
            ;



CONSTANT:   TRUE
            | FALSE
            | CHAR_VAR
            | INTEGER_VAR
            | REAL_VAR
            | STRING_VAR
            ;


%%