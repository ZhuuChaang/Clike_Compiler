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
    Node* AST_value;
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

%type <INT_value> Number;
%type <AST_value> ;




%%
Program:    Decls
            ;
Decls:      Decls Decl
            |
            ;
Decl:       VarDecl
            | FuncDecl
            ;
VarDecl:    VarType VarDefs SEMICOLON
            ;
VarDefs:    VarDefs COMMA VarDef
            | VarDef
            ;
VarDef:     IDENTIFER
            | IDENTIFER ASSIGN Expr
            ;
VarType:    BuildInType
            | CONST BuildInType
            ;
BuildInType: CHAR
            | SHORT
            | INT
            | LONG
            | FLOAT
            | DOUBLE
            ;
FuncDecl:   VarType IDENTIFER LPAREN FuncFParams RPAREN SEMICOLON
            | VarType IDENTIFER LPAREN FuncFParams RPAREN Block
            ;
FuncFParams: FuncFParams COMMA FuncFParam
            | FuncFParam
            |
            ;
FuncFParam: VarType IDENTIFER
            ;
Block:      LBRACE Stmts RBRACE
            ;
Stmts:      Stmts Stmt
            | Stmts VarDecl
            |
            ;
Stmt:       Expr SEMICOLON
            | AssignStmt
            | IfStmt
            | WhileStmt
            | BreakStmt
            | ContinueStmt
            | ReturnStmt
            | Block
            | SEMICOLON
            ;
Expr:       OrExpr
            ;
PrimaryExpr: LPAREN Expr RPAREN
            | Number
            ;
UnaryExpr:  PrimaryExpr
            | IDENTIFER LPAREN FuncRParams RPAREN
            | UnaryOp UnaryExpr
            ;
UnaryOp:    ADD | SUB | NOT
            ;
FuncRParams: FuncRParams COMMA Expr
            | Expr
            |
            ;
MulExpr:    UnaryExpr
            | MulExpr MUL UnaryExpr;
            | MulExpr DIV UnaryExpr;
            | MulExpr MOD UnaryExpr;
            ;
AddExpr:    MulExpr
            | AddExpr ADD MulExpr;
            | AddExpr SUB MulExpr;
            ;
RelExpr:    AddExpr
            | RelExpr LT AddExpr
            | RelExpr GT AddExpr
            | RelExpr LE AddExpr
            | RelExpr GE AddExpr
            ;
EqExpr:     RelExpr
            | RelExpr EQ EqExpr
            | RelExpr NE EqExpr
            ;
AndExpr:    EqExpr
            | AndExpr AND Expr
            ;
OrExpr:     AndExpr
            | OrExpr OR AndExpr
            ;







%%