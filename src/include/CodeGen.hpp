#ifndef _CODEGEN_H_
#define _CODEGEN_H_
#include "LLVMlibs.hpp"
#include "SymbolTable.hpp"
#include <string>

class Node;

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