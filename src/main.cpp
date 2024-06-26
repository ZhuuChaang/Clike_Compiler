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
    std::string fname;
    if(argc==2){
        yyin=fopen(argv[1], "r");
        fname=(std::string)argv[1];
    }else if(argc==3){
        std::string s1(argv[1]);
        if(s1=="-p"){
            print_ast=true;
        }else if(s1.find("-O")==0){
            optlevel=s1;
        }
        yyin = fopen(argv[2], "r");
        fname=(std::string)argv[2];

    }else if(argc==4){
        std::string s1(argv[1]);
        std::string s2(argv[2]);
        if(s1=="-p"){
            print_ast=true;
        }
        if(s2.find("-O")==0){
            optlevel=s2;
        }
        yyin = fopen(argv[3], "r");
        fname=(std::string)argv[3];
    }else{
        std::cout<<"wrong number of value"<<std::endl;
    }
    int start=fname.rfind("/");
    if(start!=-1){
        fname=fname.substr(start+1,fname.size());
    }


    fname=fname.substr(0,fname.find("."));
    assert(yyin);
    yyparse();
    if(print_ast){
        Root->DrawNode(0);
    }
    CodeGenerator Gen(optlevel);
    Gen.CodeGenerate(*Root);
    Gen.OutputIRcode();
    Gen.ObjGenerate(fname);
    return 0;
}
