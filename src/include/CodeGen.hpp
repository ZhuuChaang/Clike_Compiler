#ifndef _CODEGEN_H_
#define _CODEGEN_H_
#include "LLVMlibs.hpp"
#include "SymbolTable.hpp"
#include <string>
#include <map>
#include <ast.hpp>

class Node;

class CodeGenerator{
    llvm::Module * TheModule;
    Symbol_Table symTable;
    std::map<llvm::StructType*,Structtype*> structTable;

public:
    llvm::LLVMContext CodeContent;
    llvm::IRBuilder<>  TheBuilder;



    CodeGenerator();
    ~CodeGenerator();
    void CodeGenerate(Node& root);
    int ObjGenerate();

    void addStruct(llvm::StructType* lt, Structtype* at);
    

    llvm::Value * Error(std::string error_info);
};

#endif