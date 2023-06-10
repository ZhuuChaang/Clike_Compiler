#ifndef _CODEGEN_H_
#define _CODEGEN_H_
#include "LLVMlibs.hpp"
#include "SymbolTable.hpp"
#include "ast.hpp"
#include <string>
#include <map>



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
    std::vector<llvm::BasicBlock*> nextblockstack;
    std::vector<llvm::BasicBlock*> endblockstack;
    std::string Opt;


    CodeGenerator(std::string o);
    ~CodeGenerator(){}
    void CodeGenerate(Node& root);
    void ObjGenerate();
    void OutputIRcode();

    void addStruct(llvm::StructType* lt, Structtype* at);
    void addUnion(llvm::StructType* lt, Uniontype* at);
    void addFunSymtable(std::string fname, llvm::Function* fun);
    void addVarSymtable(std::string vname, llvm::Value* var);
    bool findIDSymtable(std::string name);

    void addprintfdec();

    llvm::TypeSize getTypesize(llvm::Type* t);
    llvm::Value * Error(std::string error_info);
};

#endif