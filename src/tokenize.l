%{
#include<string>
#include<stdio.h>
#include "parser.hpp"
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

"+"                 {return ADD;}
"-"                 {return SUB;}
"*"                 {return MUL;}
"/"                 {return DIV;}
"%"                 {return MOD;}
"++"                {return INC;}
"--"                {return DEC;}

"=="                {return EQ;}
"!="                {return NE;}
">"                 {return GT;}
"<"                 {return LT;}
">="                {return GE;}
"<="                {return LE;}

"&&"                {return AND;}
"||"                {return OR;}
"!"                 {return NOT;}
"&"                 {return BAND;}
"|"                 {return BOR;}
"^"                 {return BXOR;}
"~"                 {return BNOT;}
"<<"                {return SHL;}
">>"                {return SHR;}

"="                 {return ASSIGN;}
"+="                {return ADDAS;}
"-="                {return SUBAS;}
"*="                {return MULAS;}
"/="                {return DIVAS;}
"%="                {return MODAS;}
"&="                {return BANDAS;}
"|="                {return BORAS;}
"^="                {return BXORAS;}
"<<="               {return SHLAS;}
">>="               {return SHRAS;}

"?"                 {return CONDITION;}
"."                 {return DOT;}
"->"                {return ARROW;}
","                 {return COMMA;}
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
                        yylval.CHAR_value=&c;
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
                        yylval.sVal = new std::string(yytext, yyleng);
                        return IDENTIFER;
                    }

[0-9]+\.[0=9]+       {
                        double tmp=0;
                        sscanf(yytext,"%lf",&tmp);
                        yylval.REAL_value=&tmp;
                        return REAL_VAR;
                    }

0|([1-9][0-9]*)     {
                        int tmp=0;
                        sscanf(yytext,"%d",&tmp);
                        yylval.INT_value=&tmp;
                        return INTEGER_VAR;
                    }



%%