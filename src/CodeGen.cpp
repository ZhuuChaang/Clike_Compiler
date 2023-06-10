#include "CodeGen.hpp"
_CODEGEN_H_



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

void CodeGenerator::addVarSymtable(std::string vname, llvm::Value* var){
    this->symTable.newValue(vname,VAR_type,(void*)var);
}


bool CodeGenerator::findIDSymtable(std::string name){
    return this->symTable.findhave(name);
}


CodeGenerator::CodeGenerator(std::string o):
    CodeContent(),
    TheBuilder(CodeContent),
    Opt(o)
{
    this->TheModule=new llvm::Module("program",this->CodeContent);
    this->thedatalayout=new llvm::DataLayout(this->TheModule);
    this->curf=NULL;
    this->addprintfdec();
}

//declare i32 @printf(i8*, ...)
void CodeGenerator::addprintfdec(){
    std::vector<llvm::Type*> ArgTY;
    llvm::Type* retty=this->TheBuilder.getInt32Ty();
    llvm::Type* argty=this->TheBuilder.getInt8PtrTy();
    ArgTY.push_back(argty);

    llvm::FunctionType* FunTY=llvm::FunctionType::get(retty,ArgTY,true);
    llvm::Function* FUN=llvm::Function::Create(FunTY,llvm::GlobalValue::ExternalLinkage,"printf",this->TheModule);
    this->addFunSymtable("printf",FUN);
}

void CodeGenerator::CodeGenerate(Node& root){
    root.CodeGen(*this);

    if(this->Opt!=""){
		llvm::LoopAnalysisManager loopmng;
		llvm::FunctionAnalysisManager funcmng;
		llvm::CGSCCAnalysisManager CGSCmng;
		llvm::ModuleAnalysisManager modulemng;
		llvm::PassBuilder PB;
	
		PB.registerModuleAnalyses(modulemng);
		PB.registerCGSCCAnalyses(CGSCmng);
		PB.registerFunctionAnalyses(funcmng);
		PB.registerLoopAnalyses(loopmng);
		PB.crossRegisterProxies(loopmng, funcmng, CGSCmng, modulemng);

        llvm::OptimizationLevel llvmopt;
        if(this->Opt=="O"||this->Opt=="O0"){
            llvmopt=llvm::OptimizationLevel::O0;
        }else if(this->Opt=="O1"){
            llvmopt=llvm::OptimizationLevel::O1;
        }else if(this->Opt=="O2"){
            llvmopt=llvm::OptimizationLevel::O2;
        }else if(this->Opt=="O3"){
            llvmopt=llvm::OptimizationLevel::O3;
        }
        llvm::ModulePassManager mpassmng = PB.buildPerModuleDefaultPipeline(llvmopt);
        mpassmng.run(*this->TheModule, modulemng);
    }
}

void CodeGenerator::OutputIRcode(){
    std::string filename="ircode.txt";
    std::error_code ecode;
    llvm::raw_fd_ostream outf(filename,ecode);
    this->TheModule->print(outf,NULL);
}