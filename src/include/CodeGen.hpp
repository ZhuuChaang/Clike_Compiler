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
    llvm::Function* curf=NULL;
    
    
    Symbol_Table symTable;    
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
};

#endif