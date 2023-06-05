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