#include <iostream>
#include <fstream>
#include "ast.hpp"
#include "astprinter.hpp"
#include "CodeGen.hpp"
#include "LLVMlibs.hpp"

extern FILE *yyin;
extern int yyparse();
extern Program* Root;

int main(int argc, const char* argv[]){
    bool print_ast=false;
    std::string optlevel;
    if(argc==1){
        yyin=fopen(argv[1], "r");
    }else if(argc==2){
        std::string s1(argv[1]);
        if(s1=="-p"){
            print_ast=true;
        }else if(s1.find("-O")==0){
            optlevel=s1;
        }
        yyin = fopen(argv[2], "r");
    }else if(argc==3){
        std::string s1(argv[1]);
        std::string s2(argv[2]);
        if(s1=="-p"){
            print_ast=true;
        }
        if(s2.find("-O")==0){
            optlevel=s2;
        }
        yyin = fopen(argv[2], "r");
    }else{
        std::cout<<"wrong number of value"<<std::endl;
    }
    assert(yyin);
    yyparse();
    if(print_ast){
        Root->DrawNode(0);
    }
    CodeGenerator Gen(optlevel);
    Gen.CodeGenerate(*Root);
    Gen.OutputIRcode();
    Gen.ObjGenerate();
    return 0;
}
