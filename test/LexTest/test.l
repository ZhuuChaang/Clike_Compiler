%{
#include<string.h>
#include<stdio.h>
// #include "testlex.h"
%}

%option outfile="testlex.cpp"

%%
"char"              {printf("CHAR\n");}
"double"            {printf("DOUBLE\n");}
"float"             {printf("FLOAT\n");}
"int"               {printf("INT\n");}
"short"             {printf("SHORT\n");}
"long"              {printf("LONG\n");}
"void"              {printf("VOID\n");}
"enum"              {printf("ENUM\n");}
"union"             {printf("UNION\n");}
"struct"            {printf("STRUCT\n");}

"true"              {printf("TRUE\n");}
"false"             {printf("FALSE\n");}

"for"               {printf("FOR\n");}
"do"                {printf("DO\n");}
"while"             {printf("WHILE\n");}
"break"             {printf("BREAK\n");}
"continue"          {printf("CONTINUE\n");}
"if"                {printf("IF\n");}
"else"              {printf("ELSE\n");}
"goto"              {printf("GOTO\n");}
"switch"            {printf("SWITCH\n");}
"case"              {printf("CASE\n");}
"default"           {printf("DEFAULT\n");}
"return"            {printf("RETURN\n");}

"static"            {printf("STATIC\n");}
"const"             {printf("CONST\n");}
"sizeof"            {printf("SIZEOF\n");}
"typedef"           {printf("TYPEDEF\n");}

"+"                 {printf("ADD\n");}
"-"                 {printf("SUB\n");}
"*"                 {printf("MUL\n");}
"/"                 {printf("DIV\n");}
"%"                 {printf("MOD\n");}
"++"                {printf("INC\n");}
"--"                {printf("DEC\n");}

"=="                {printf("EQ\n");}
"!="                {printf("NE\n");}
">"                 {printf("GT\n");}
"<"                 {printf("LT\n");}
">="                {printf("GE\n");}
"<="                {printf("LE\n");}

"&&"                {printf("AND\n");}
"||"                {printf("OR\n");}
"!"                 {printf("NOT\n");}
"&"                 {printf("BAND\n");}
"|"                 {printf("BOR\n");}
"^"                 {printf("BXOR\n");}
"~"                 {printf("BNOT\n");}
"<<"                {printf("SHL\n");}
">>"                {printf("SHR\n");}

"="                 {printf("ASSIGN\n");}
"+="                {printf("ADDAS\n");}
"-="                {printf("SUBAS\n");}
"*="                {printf("MULAS\n");}
"/="                {printf("DIVAS\n");}
"%="                {printf("MODAS\n");}
"&="                {printf("BANDAS\n");}
"|="                {printf("BORAS\n");}
"^="                {printf("BXORAS\n");}
"<<="               {printf("SHLAS\n");}
">>="               {printf("SHRAS\n");}

"?"                 {printf("CONDITION\n");}
"."                 {printf("DOT\n");}
"->"                {printf("ARROW\n");}
","                 {printf("COMMA\n");}
";"                 {printf("SEMICOLON\n");}
":"                 {printf("COLON\n");}
"("                 {printf("LPAREN\n");}
")"                 {printf("RPAREN\n");}
"["                 {printf("LBRACKET\n");}
"]"                 {printf("RBRACKET\n");}
"{"                 {printf("LBRACE\n");}
"}"                 {printf("RBRACE\n");}

[ \t\n]             {;}
\/\/[^\n]*          {printf("comment %s\n",yytext);}
"\*".*"*/"          {printf("comment %s\n",yytext);} 

\'(.|\\.)\'         {
                        // std::string s(yytext);
                        // s=s.substr(1,s.length()-1);
                        // s=s.substr(0,s.length()-1);                        
                        // char c=s[0];
                        printf("CHAR_VAR %s\n",yytext);
                    }


"\"".*"\""              {
                        // std::string s(yytext);
                        // s=s.substr(1,s.length()-1);
                        // s=s.substr(0,s.length()-1);
                        printf("STRING_VAR %s\n",yytext);
                    }


[a-zA-Z_][a-zA-Z_0-9]* {
                        // std::string s(yytext);
                        printf("IDENTIFER %s\n",yytext);
                    }

[0-9]+\.[0=9]+       {
                        // double tmp=0;
                        // sscanf(yytext,"%lf",&tmp);
                        printf("REAL_VAR %s\n",yytext);
                    }

0|([1-9][0-9]*)     {
                        // int tmp=0;
                        // sscanf(yytext,"%d",&tmp);
                        printf("INTEGER_VAR %s\n",yytext);
                    }




%%

int main(){
    FILE* f=fopen("test.c","r");
    yyrestart(f);
    yylex();
    // printf("\n%d \n",l_cnt);

    fclose(f);
    return 0;
}

int yywrap(){
    return 1;
}