%{
#include<string>
#include<stdio.h>
#include "parser.hpp"
#include<iostream>
%}

%option outfile="tokenize.cpp"

%%
"char"              {return CHAR;}
"double"            {return DOUBLE;}
"float"             {return FLOAT;}
"int"               {return INT;}
"short"             {return SHORT;}
"long"              {return LONG;}
"void"              {return VOID;}
"enum"              {return ENUM;}
"union"             {return UNION;}
"struct"            {return STRUCT;}

"true"              {return TRUE;}
"false"             {return FALSE;}

"for"               {return FOR;}
"do"                {return DO;}
"while"             {return WHILE;}
"break"             {return BREAK;}
"continue"          {return CONTINUE;}
"if"                {return IF;}
"else"              {return ELSE;}
"goto"              {return GOTO;}
"switch"            {return SWITCH;}
"case"              {return CASE;}
"default"           {return DEFAULT;}
"return"            {return RETURN;}

"static"            {return STATIC;}
"const"             {return CONST;}
"sizeof"            {return SIZEOF;}
"typedef"           {return TYPEDEF;}

"+"                 {return yylval.token = ADD;}
"-"                 {return yylval.token = SUB;}
"*"                 {return yylval.token = MUL;}
"/"                 {return yylval.token = DIV;}
"%"                 {return yylval.token = MOD;}
"++"                {return yylval.token = INC;}
"--"                {return yylval.token = DEC;}

"=="                {return yylval.token = EQ;}
"!="                {return yylval.token = NE;}
">"                 {return yylval.token = GT;}
"<"                 {return yylval.token = LT;}
">="                {return yylval.token = GE;}
"<="                {return yylval.token = LE;}

"&&"                {return yylval.token = AND;}
"||"                {return yylval.token = OR;}
"!"                 {return yylval.token = NOT;}
"&"                 {return yylval.token = BAND;}
"|"                 {return yylval.token = BOR;}
"^"                 {return yylval.token = BXOR;}
"~"                 {return yylval.token = BNOT;}
"<<"                {return yylval.token = SHL;}
">>"                {return yylval.token = SHR;}

"="                 {return yylval.token = ASSIGN;}
"+="                {return yylval.token = ADDAS;}
"-="                {return yylval.token = SUBAS;}
"*="                {return yylval.token = MULAS;}
"/="                {return yylval.token = DIVAS;}
"%="                {return yylval.token = MODAS;}
"&="                {return yylval.token = BANDAS;}
"|="                {return yylval.token = BORAS;}
"^="                {return yylval.token = BXORAS;}
"<<="               {return yylval.token = SHLAS;}
">>="               {return yylval.token = SHRAS;}

"?"                 {return yylval.token = CONDITION;}
"."                 {return yylval.token = DOT;}
"->"                {return yylval.token = ARROW;}
","                 {return yylval.token = COMMA;}
";"                 {return SEMICOLON;}
":"                 {return COLON;}
"("                 {return LPAREN;}
")"                 {return RPAREN;}
"["                 {return LBRACKET;}
"]"                 {return RBRACKET;}
"{"                 {return LBRACE;}
"}"                 {return RBRACE;}

[ \t\n]             {;}
\/\/[^\n]*          {;}
"\*".*"*/"           {;} 

\'(.|\\.)\'         {
                        std::string s(yytext);
                        s=s.substr(1,s.length()-1);
                        s=s.substr(0,s.length()-1);                        
                        char c=s[0];
                        yylval.CHAR_value=c;
                        return CHAR_VAR;
                    }


"\"".*"\""              {
                        std::string s(yytext);
                        s=s.substr(1,s.length()-1);
                        s=s.substr(0,s.length()-1);
                        yylval.STRING_value=&s;
                        return STRING_VAR;
                    }


[a-zA-Z_][a-zA-Z_0-9]* {
                        //std::string s(yytext);
                        //yylval.IDENTIFER_value=&s;
                        yylval.IDENTIFER_value = new std::string(yytext, yyleng);
                        return IDENTIFER;
                    }

[0-9]+\.[0=9]+       {
                        double tmp=0;
                        sscanf(yytext,"%lf",&tmp);
                        yylval.REAL_value=tmp;
                        return REAL_VAR;
                    }

0|([1-9][0-9]*)     {
                        int tmp=0;
                        sscanf(yytext,"%d",&tmp);
                        yylval.INT_value=tmp;
                        return INTEGER_VAR;
                    }



%%