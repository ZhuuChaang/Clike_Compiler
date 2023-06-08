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
    yyin = fopen(argv[2], "r");
    assert(yyin);
    yyparse();
    std::cout << "dddd" << std::endl;
    Root->DrawNode(0);
    std::cout<<"haha\n";
    return 0;
}