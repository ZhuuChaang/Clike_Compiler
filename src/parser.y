%{
#include<string>
#include<iostream>
#include "ast.h"
_AST_H_

void yyerror(const char *s) {
    std::printf("Error: %s\n", s);
    std::exit(1); 
}

int yylex(void);



%}

%union{
    int* INT_value;
    double* REAl_value;
    std::string* STRING_value;
    char* CHAR_value;

    std::string* IDENTIFER_value;

    Node* AST_NODE_value;
    Constant* AST_CONSTANT_value; 
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
%token <IDENTIFER_value> IDENTIFER

%type <AST_NODE_value> PROGRAM



%type <AST_CONSTANT_value> CONSTANT

%nonassoc IF
%nonassoc ELSE

%left   COMMA
%right  ASSIGN ADDAS SUBAS MULAS DIVAS MODAS SHLAS SHRAS BANDAS BORAS BXORAS
%right  CONDITION COLON
%left   OR
%left   AND
%left   BOR
%left   BXOR
%left   BAND
%left   EQ NE
%left   GE GT LE LT
%left   SHL SHR
%left   ADD SUB
%left   MUL DIV MOD
%left   INC DEC NOT BNOT SIZEOF
%left   DOT ARROW

%start PROGRAM

%%
PROGRAM:    GlobalSTMT
            ;


// top level statements of the program, including defines and declares of func and global var
GlobalSTMT: GlobalSTMT FunDECL 
            | GlobalSTMT FunDEF 
            | GlobalSTMT TypeDEF
            | GlobalSTMT VarDEF
            | GlobalSTMT FieldDECL  {}
            |                       {$$=new Globalstmt();}
            ;

//types
TYPE:       _TYPE
            | CONST _TYPE
            | STATIC _TYPE
            ;

_TYPE:      BuiltinTYPE     {$$=$1;}
            | FieldTYPE     {$$=$1;}
            | _TYPE PTR     {$$=new Pointertype($1);}
            | _TYPE ARRAY   {$$=new Arraytype($1,*($2));}
            | IDENTIFER     {$$=new Definedtype($1);}
            ;


FieldTYPE:  STRUCT IDENTIFER LBRACE SUSTMT RBRACE
            | UNION IDENTIFER LBRACE SUSTMT RBRACE
            | ENUM IDENTIFER LBRACE EnmLIST RBRACE
            ;

BuiltinTYPE: CHAR   {$$=new Builtintype();$$->set_char();}
            |DOUBLE {$$=new Builtintype();$$->set_double();}
            |FLOAT  {$$=new Builtintype();$$->set_float();}
            |INT    {$$=new Builtintype();$$->set_int();}
            |SHORT  {$$=new Builtintype();$$->set_short();}
            |LONG   {$$=new Builtintype();$$->set_long();}
            |VOID   {$$=new Builtintype();$$->set_void();}
            ;


//ptr and array
PTR:        MUL {;}
            ;

ARRAY:      LBRACKET INTEGER_VAR RBRACKET {$$=S2;}
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
            TYPE IDENTIFER
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
            | IDENTIFER ASSIGN INTEGER_VAR
            ;

//type defination
TypeDEF:    TYPEDEF TYPE IDENTIFER SEMICOLON    {$$=new Definedtype($2,$1);}



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

// statements
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


STMT:       STMT SEMICOLON STMT 
            | STMT SEMICOLON
            | CtrlFLOW
            | EXPR SEMICOLON
            | SCOPE
            | TypeDEF
            | VarDEF
            | FieldDECL
            | ReturnSTMT
            | 
            ;

ReturnSTMT: RETURN SEMICOLON
            | RETURN EXPR SEMICOLON
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
            | ADD
            | SUB
            ;

SUFOP       INC
            | DEC            
            ;

BINOP       ADD
            | SUB
            | MUL
            | DIV
            | MOD
            | EQ
            | NE
            | GT
            | LT
            | GE
            | LE
            | AND
            | OR
            | BAND
            | BOR
            | BXOR
            | SHL
            | SHR
            | ASSIGN
            | ADDAS
            | SUBAS
            | MULAS
            | DIVAS
            | MODAS
            | BANDAS
            | BORAS
            | BXORAS
            | SHLAS
            | SHRAS
            | COMMA
            ;

FUNCALL:    IDENTIFER LPAREN CallArgLIST RPAREN
            ;

CallArgLIST: _CallArgLIST COMMA EXPR
            | EXPR 
            |
            ;

_CallArgLIST: _CallArgLIST COMMA EXPR
            | EXPR
            ;            

CONSTANT:   TRUE    {enum Csttype t=cstty_bool; $$=new Constant(true,t);}
            | FALSE {enum Csttype t=cstty_bool; $$=new Constant(false,t);}
            | CHAR_VAR  {enum Csttype t=cstty_char; $$=new Constant(*($1),t);}
            | INTEGER_VAR   {enum Csttype t=cstty_int; $$=new Constant(*($1),t);}
            | REAL_VAR  {enum Csttype t=cstty_real; $$=new Constant(*($1),t);}
            | STRING_VAR    {enum Csttype t=cstty_str; $$=new Constant(*($1),t);} 
            ;


%%