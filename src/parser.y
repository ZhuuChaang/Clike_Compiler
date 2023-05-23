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
    Program* AST_PROG_value;
    Type* AST_TYPE_value;
    IdentifierList* AST_IDLIST_value;
    Enum* AST_ENUM_value;
    Enumlist* AST_ENUMLIST_value;
    SUmemdec* AST_SUDEC_value;
    SUdecllist* AST_SUDECLIST_value;

    funArgList* AST_FUNARGLIST_Value;

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


%type <AST_TYPE_value> _TYPE TYPE FieldTYPE BuiltinTYPE
%type <AST_IDLIST_value> IdList
%type <AST_ENUM_value> Enm
%type <AST_ENUMLIST_value> _EnmLIST EnmLIST
%type <AST_SUDEC_value> SUVarDEF
%type <AST_SUDECLIST_value> SUSTMT

%type <AST_FUNARGLIST_Value> ArgLIST _ArgLIST


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
GlobalSTMT: GlobalSTMT FunDECL      {$$->Addstmt($2);}
            | GlobalSTMT FunDEF     {$$->Addstmt($2);}
            | GlobalSTMT TypeDEF    {$$->Addstmt($2);}
            | GlobalSTMT VarDEF     {$$->Addstmt($2);}      
            | GlobalSTMT FieldDECL  {$$->Addstmt($2);}
            |                       {$$=new Globalstmt();}
            ;

//types
TYPE:       _TYPE           {$$=$1;}
            | CONST _TYPE   {$1->set_const();$$=$1;}
            | STATIC _TYPE  {$1->set_static();$$=$1;}
            ;

_TYPE:      BuiltinTYPE     {$$=$1;}
            | FieldTYPE     {$$=$1;}
            | _TYPE PTR     {$$=new Pointertype($1);}
            | _TYPE ARRAY   {$$=new Arraytype($1,*($2));}
            | IDENTIFER     {$$=new Definedtype(*$1);}
            ;


FieldTYPE:  STRUCT IDENTIFER LBRACE SUSTMT RBRACE   {$$=new Structtype(*$2,$4);}
            | UNION IDENTIFER LBRACE SUSTMT RBRACE  {$$=new Uniontype(*$2,$4);}
            | ENUM IDENTIFER LBRACE EnmLIST RBRACE  {$$=new Enumtype(*$2,$4);}
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
FunDECL:    TYPE IDENTIFER LPAREN ArgLIST RPAREN SEMICOLON  {$$=new Fundeclare($1,*$2,$4);}
            ;

FunDEF:     TYPE IDENTIFER LPAREN ArgLIST RPAREN LBRACE STMT RBRACE
            ;

ArgLIST:	_ArgLIST COMMA TYPE IDENTIFER   {$$=$1; $$->push_back(new funArg($3,$4));}
            | TYPE IDENTIFER                {$$->push_back(new funArg($1,$2));}
            |                               {$$=new funArgList();}
			;

_ArgLIST:	_ArgLIST COMMA TYPE IDENTIFER   {$$=$1; $$->push_back(new funArg($3,$4));}
            TYPE IDENTIFER                  {$$->push_back(new funArg($1,$2));}
            ;

//variable define and declare
FieldDECL:  FieldTYPE SEMICOLON     {$$=new Fielddeclare($1);}
            ;

VarDEF:     TYPE InitIDLIST SEMICOLON   {$$=new Vardefine($1,$2);}
            ;

SUVarDEF:   TYPE IdList SEMICOLON   {$$=new SUmemdec($1,$2);}
            ;


IdList      IdList COMMA IDENTIFER {$$=$1; $$->push_back(*$3);}
            | IDENTIFER             {$$=new IdentifierList(); $$->push_back(*$1);}
            ;


InitIDLIST: InitIDLIST COMMA Init  {$$=$1;$$->push_back($3);}
            | Init                 {$$=new InitIDList();$$->push_back($1);}         
            ;

Init:       IDENTIFER               {$$=new InitID(*$1);}
            | IDENTIFER ASSIGN EXPR {$$=new InitID(*$1,$3);}
            ;


EnmLIST:    _EnmLIST COMMA Enm  {$1->push_back($3);$$=$1;}
            | Enm               {$$->push_back($1);}
            |                   {$$=new Enumlist();}
            ;

_EnmLIST:   _EnmLIST COMMA Enm  {$1->push_back($3);$$=$1;}
            | Enm               {$$->push_back($1);}
            ;

Enm:        IDENTIFER                       {$$=new Enum(*$1);}
            | IDENTIFER ASSIGN INTEGER_VAR  {$$=new Enum(*$1,*$3);}
            ;

//type defination
TypeDEF:    TYPEDEF TYPE IDENTIFER SEMICOLON    {$$=new Definedtype($2,*$3);}



SCOPE:      LBRACE STMT RBRACE  {$$=new Scope($2);}
            ;

// ctrl flow 
CtrlFLOW:   IfFLOW          {$$=$1;}
            | ForFLOW       {$$=$1;}
            | DowhileFLOW   {$$=$1;}
            | WhileFLOW     {$$=$1;}
            | SwitchFLOW    {$$=$1;}
            ;

CtrlSCOPE:  LBRACE CtrlSTMT RBRACE  {$$=new Scope($2);}

IfFLOW:     IF LPAREN EXPR RPAREN CtrlSCOPE ElseifFLOW ElseFLOW {$$=new Ifflow($3,$5,$6,$7);}
            | IF LPAREN EXPR RPAREN SEMICOLON                   {$$=new Ifflow($3);}
            ;

ElseFLOW:   ELSE CtrlSCOPE        {$$=new Elseflow($2);}
            | ELSE SEMICOLON      {$$=new Elseflow();}
            ;

ElseifFLOW: ElseifFLOW ELSE IF LPAREN EXPR RPAREN CtrlSCOPE {$$=$1;$$->Addelseif($5,$7);}
            |                                               {$$=new Elseifflow();}   
            ;


ForFLOW:    FOR LPAREN EXPR SEMICOLON EXPR SEMICOLON EXPR RPAREN SEMICOLON      {$$=new Forflow($3,$5,$7);}
            | FOR LPAREN EXPR SEMICOLON EXPR SEMICOLON EXPR RPAREN CtrlSCOPE    {$$=new Forflow($3,$5,$7,$9);}
            ;

WhileFLOW:  WHILE LPAREN EXPR RPAREN CtrlSCOPE      {$$=new Whileflow($3,$5);}
            | WHILE LPAREN EXPR RPAREN SEMICOLON    {$$=new Whileflow($3);}
            ;

DowhileFLOW: DO CtrlSCOPE WHILE LPAREN EXPR RPAREN SEMICOLON    {$$=new Dowhileflow($5,$2);}
            ;      


SwitchFLOW: SWITCH LPAREN EXPR RPAREN LBRACE CaseLIST RBRACE    {$$=new Switchflow($3,$6);}
            ;

CaseLIST:   CaseLIST CaseSTMT   {$$->push_back($2);}
            |                   {$$=new Caselist();}
            ;

// statements
CaseSTMT:   CASE EXPR COLON STMT BREAK SEMICOLON    {$$=new Case($2,$4);$$->set_break();}
            | CASE EXPR COLON STMT                  {$$=new Case($2,$4);}
            | DEFAULT COLON STMT BREAK SEMICOLON    {$$=new Case($3);$$->set_break();$$->set_default();}
            | DEFAULT COLON STMT                    {$$=new Case($3);$$->set_default();}
            ;             

CtrlSTMT:   CtrlSTMT CtrlFLOW               {$$=$1; $$->Addstmt($2);}
            | CtrlSTMT BREAK SEMICOLON      {$$=$1; $$->Addstmt(new Breakstmt($2));}
            | CtrlSTMT CONTINUE SEMICOLON   {$$=$1; $$->Addstmt(new Continuestmt($2));}
            | CtrlSTMT EXPR SEMICOLON       {$$=$1; $$->Addstmt(new Exprstmt($2));}
            | CtrlSTMT SCOPE                {$$=$1; $$->Addstmt($2);}
            | CtrlSTMT TypeDEF              {$$=$1; $$->Addstmt($2);}
            | CtrlSTMT VarDEF               {$$=$1; $$->Addstmt($2);}
            | CtrlSTMT FieldDECL            {$$=$1; $$->Addstmt($2);}
            | CtrlSTMT ReturnSTMT           {$$=$1; $$->Addstmt($2);}
            |                               {$$=new Stmt();}
            ;


STMT:       STMT CtrlFLOW           {$$=$1; $$->Addstmt($2);}
            | STMT EXPR SEMICOLON   {$$=$1; $$->Addstmt(new Exprstmt($2));}
            | STMT SCOPE            {$$=$1; $$->Addstmt($2);}
            | STMT TypeDEF          {$$=$1; $$->Addstmt($2);}
            | STMT VarDEF           {$$=$1; $$->Addstmt($2);}
            | STMT FieldDECL        {$$=$1; $$->Addstmt($2);}
            | STMT ReturnSTMT       {$$=$1; $$->Addstmt($2);}
            |                       {$$=new Stmt();}
            ;

ReturnSTMT: RETURN SEMICOLON        {$$=new ReturnSTMT();}
            | RETURN EXPR SEMICOLON {$$=new ReturnSTMT($2);}
            ;

SUSTMT:     SUSTMT SUVarDEF SEMICOLON   {$$=$1;$$->push_back($2);}
            | SUVarDEF SEMICOLON        {$$->push_back($1);}    
            |                           {$$=new SUdecllist(); }
            ;




//expr            

EXPR:       IDENTIFER                       {$$ = new Variable($1);}
            | FUNCALL                       {$$ = $1;}
            | CONSTANT                      {$$ = $1;}
            | EXPR BINOP EXPR               {$$ = new BinopExpr($1, $2, $3);}
            | UNAOP EXPR                    {$$ = new UnaopExpr($1, $2);}
            | EXPR SUFOP                    {$$ = new SufopExpr($1, $2);}
            | LPAREN EXPR RPAREN            {$$ = $2;}
            | SIZEOF LPAREN EXPR RPAREN     {$$ = new SizeofExpr($3);}
            | SIZEOF LPAREN TYPE RPAREN     {$$ = new SizeofExpr($3);}
            | EXPR CONDITION EXPR COLON EXPR {$$ = new TernaryCondition($1, $3, $5);}
            | LPAREN TYPE RPAREN EXPR       {$$ = new TypeCast($2, $4);}
            | EXPR LBRACKET EXPR RBRACKET   {$$ = new Subscript($1, $3);}
            | EXPR ARROW IDENTIFER          {$$ = new MemAccessPtr($1, $3);}
            | EXPR DOT IDENTIFER            {$$ = new MemAccessObj($1, $3);}
            ;  

UNAOP       INC     {$$ = $1;}
            | DEC   {$$ = $1;}
            | NOT   {$$ = $1;}
            | BNOT  {$$ = $1;}
            | MUL   {$$ = $1;}
            | BAND  {$$ = $1;}
            | ADD   {$$ = $1;}
            | SUB   {$$ = $1;}
            ;

SUFOP       INC     {$$ = $1;}
            | DEC   {$$ = $1;}
            ;

BINOP       ADD     {$$ = $1;}
            | SUB   {$$ = $1;}
            | MUL   {$$ = $1;}
            | DIV   {$$ = $1;}
            | MOD   {$$ = $1;}
            | EQ    {$$ = $1;}
            | NE    {$$ = $1;}
            | GT    {$$ = $1;}
            | LT    {$$ = $1;}
            | GE    {$$ = $1;}
            | LE    {$$ = $1;}
            | AND   {$$ = $1;}
            | OR    {$$ = $1;}
            | BAND  {$$ = $1;}
            | BOR   {$$ = $1;}
            | BXOR  {$$ = $1;}
            | SHL   {$$ = $1;}
            | SHR   {$$ = $1;}
            | ASSIGN {$$ = $1;}
            | ADDAS {$$ = $1;}
            | SUBAS {$$ = $1;}
            | MULAS {$$ = $1;}
            | DIVAS {$$ = $1;}
            | MODAS {$$ = $1;}
            | BANDAS {$$ = $1;}
            | BORAS {$$ = $1;}
            | BXORAS {$$ = $1;}
            | SHLAS {$$ = $1;}
            | SHRAS {$$ = $1;}
            | COMMA {$$ = $1;}
            ;

FUNCALL:    IDENTIFER LPAREN CallArgLIST RPAREN
                {$$ = new FuncCall(*$1, $2);}
            ;

CallArgLIST: _CallArgLIST COMMA EXPR    {$$ = $1; $$->push_back($3);}
            | EXPR                      {$$ = new CallArgList(); $$->push_back($1);}
            |                           {$$ = new CallArgList();}
            ;

_CallArgLIST: _CallArgLIST COMMA EXPR   {$$ = $1; $$->push_back($3);}
            | EXPR                      {$$ = new CallArgList(); $$->push_back($1);}
            ;            

CONSTANT:   TRUE    {enum Csttype t=cstty_bool; $$=new Constant(true,t);}
            | FALSE {enum Csttype t=cstty_bool; $$=new Constant(false,t);}
            | CHAR_VAR  {enum Csttype t=cstty_char; $$=new Constant(*($1),t);}
            | INTEGER_VAR   {enum Csttype t=cstty_int; $$=new Constant(*($1),t);}
            | REAL_VAR  {enum Csttype t=cstty_real; $$=new Constant(*($1),t);}
            | STRING_VAR    {enum Csttype t=cstty_str; $$=new Constant(*($1),t);} 
            ;


%%