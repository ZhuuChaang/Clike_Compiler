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

    llvm::Function* curf=NULL;
    std::vector<llvm::BasicBlock*> nextblockstack;
    std::vector<llvm::BasicBlock*> endblockstack;
    std::string Opt;

    std::map<std::string,std::string> suelist;


    CodeGenerator(std::string o);
    ~CodeGenerator(){}
    void CodeGenerate(Node& root);
    void ObjGenerate(std::string outname);
    void OutputIRcode();

    void addFunSymtable(std::string fname, llvm::Function* fun);
    void addVarSymtable(std::string vname, llvm::Value* var);
    bool findIDSymtable(std::string name);

    void addprintfdec();

    llvm::TypeSize getTypesize(llvm::Type* t);
    // llvm::Value * Error(std::string error_info);
};

#endif