#ifndef _CODEGEN_H_
#define _CODEGEN_H_
#include "LLVMlibs.h"
#include "ast.h"
#include <string>
class CodeGenerator{
    llvm::Module * TheModule;
    llvm::IRBuilder<> * TheBuilder;
    llvm::LLVMContext CodeContent;

public:
    CodeGenerator();
    ~CodeGenerator();
    void CodeGenerate(Node& root);
    int ObjGenerate();

    llvm::Value * Error(std::string error_info);
};

#endif