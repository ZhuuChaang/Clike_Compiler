#ifndef _CODEGEN_H_
#define _CODEGEN_H_
#include "LLVMlibs.h"
#include "ast.h"
class CodeGenerator{
    llvm::Module * TheModule;

public:
    void CodeGenerate(Node& root);
    int ObjGenerate();
};

#endif