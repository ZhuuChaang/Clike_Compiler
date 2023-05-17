#ifndef _CODEGEN_H_
#define _CODEGEN_H_
#include "LLVMlibs.h"
#include "ast.h"
#include "SymbolTable.h"
#include <string>

class CodeGenerator{
    llvm::Module * TheModule;
    llvm::IRBuilder<> * TheBuilder;
    llvm::LLVMContext CodeContent;
    Symbol_Table symTable;

public:
    CodeGenerator();
    ~CodeGenerator();
    void CodeGenerate(Node& root);
    int ObjGenerate();

    llvm::Value * Error(std::string error_info);
};

#endif