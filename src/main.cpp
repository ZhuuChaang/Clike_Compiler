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
    Root->DrawNode(0);
    CodeGenerator Gen("");
    Gen.CodeGenerate(*Root);
    Gen.OutputIRcode();
    Gen.ObjGenerate();
    return 0;
}