#include "CodeGen.hpp"
_CODEGEN_H_

CodeGenerator::CodeGenerator():
    CodeContent(),
    TheBuilder(CodeContent)
{}


void CodeGenerator::addStruct(llvm::StructType* lt, Structtype* at){
    // if(this->structTable.find(lt)!=this->structTable.end()){
        this->structTable[lt]=at;
    // }
}

void CodeGenerator::addUnion(llvm::StructType* lt, Uniontype* at){
    this->unionTable[lt]=at;
}

llvm::TypeSize CodeGenerator::getTypesize(llvm::Type* t){
    return this->thedatalayout->getTypeAllocSize(t);
}

void CodeGenerator::addFunSymtable(std::string fname, llvm::Function* fun){
    this->symTable.newValue(fname,FUNC_type,(void*)fun);
}

void CodeGenerator::addVarSymtable(std::string vname, llvm::AllocaInst* var){
    this->symTable.newValue(vname,VAR_type,(void*)var);
}


bool CodeGenerator::findIDSymtable(std::string name){
    return this->symTable.findhave(name);
}