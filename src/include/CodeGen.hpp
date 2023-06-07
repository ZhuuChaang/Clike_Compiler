#ifndef _CODEGEN_H_
#define _CODEGEN_H_
#include "LLVMlibs.hpp"
#include "SymbolTable.hpp"
#include <string>
#include <map>
#include <ast.hpp>

class Node;

class CodeGenerator{
public:
    llvm::LLVMContext CodeContent;
    llvm::IRBuilder<>  TheBuilder;
    llvm::Module * TheModule;
    llvm::DataLayout* thedatalayout;
    Symbol_Table symTable;    
    std::map<llvm::StructType*,Structtype*> structTable;
    std::map<llvm::StructType*,Uniontype*> unionTable;
    llvm::Function* curf=NULL;




    CodeGenerator();
    ~CodeGenerator();
    void CodeGenerate(Node& root);
    int ObjGenerate();

    void addStruct(llvm::StructType* lt, Structtype* at);
    void addUnion(llvm::StructType* lt, Uniontype* at);
    void addFunSymtable(std::string fname, llvm::Function* fun);
    void addVarSymtable(std::string vname, llvm::AllocaInst* var);
    bool findIDSymtable(std::string name);

    llvm::TypeSize getTypesize(llvm::Type* t);
    llvm::Value * Error(std::string error_info);
};

#endif