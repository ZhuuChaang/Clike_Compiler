#include"ast.hpp"
#include <iostream>
#include <map>
using namespace std;

void Indentation(int ind){
    for(int i = 0; i < ind; i++){
        cout << '\t';
    }
}

int Program::DrawNode(int depth) {
    Indentation(depth);
    cout << "Program:" << endl;
    this->Stmtlist->DrawNode(depth);
    return 0;
}

int Globalstmt::DrawNode(int depth) {
    Indentation(depth);
    cout << "Globalstmt:" << endl;
    for(int i = 0; i < this->stmtlist.size(); i++){
        this->stmtlist[i]->DrawNode(depth + 1);
    }
    cout << endl;
    return 0;
}

int Stmt::DrawNode(int depth){
    vector<Basestmt*>::iterator iter;
    for(iter = stmtlist.begin(); iter != stmtlist.end(); iter++){
        (*iter)->DrawNode(depth);
    }
    return 0;
}

//type

int Builtintype::DrawNode(int depth) {
    Indentation(depth);
    cout << "BuiltinType: ";
    switch (Ty){
    case int_ty:
        cout << "int";
        break;
    case short_ty:
        cout << "short";
        break;
    case long_ty:
        cout << "long";
        break;
    case void_ty:
        cout << "void";
        break;
    case float_ty:
        cout << "float";
        break;
    case double_ty:
        cout << "double";
        break;
    case char_ty:
        cout << "char";
        break;
    default:
        cout << "undefined";
        break;
    }
    return 0;
}

//statement
int Fundefine::DrawNode(int depth) {
    Indentation(depth);
    cout << "Fundefine: ";\
    //name
    cout << this->Funname;
    //return type
    this->retType->DrawNode(depth + 1);
    cout << endl;
    //argment list
    map<std::string,Type*>::iterator iter;
    for(iter = this->Arglist.begin(); iter != this->Arglist.end(); iter++){
        (*iter).second->DrawNode(depth + 1);
        cout << " " << (*iter).first << endl;
    }
    //body
    this->Funbody->DrawNode(depth + 1);
    return 0;
}

int Vardefine::DrawNode(int depth) {
    Indentation(depth);
    cout << "Vardefine: " << endl;
    this->type->DrawNode(depth + 1);
    for(int i = 0; i < this->list->size(); i++){
        cout << endl;
        this->list[i].DrawNode();
    }
    cout << endl;
    return 0;
}

int InitID::DrawNode(int depth){

}

int Scope::DrawNode(int depth){
    this->Scopestmt->DrawNode(depth);
    return 0;
}

int Returnstmt::DrawNode(int depth){
    if(!withvalue){
        cout << "Return without value" << endl;
    }
    else{
        cout << "Return: ";
        this->ret->DrawNode(depth);
    }
    return 0;
}

//expression
int Constant::DrawNode(int depth){
    switch (this->type)    {
    case Csttype::cstty_bool:
        cout << b;
        break;
    case Csttype::cstty_char:
        cout << c;
        break;
    case Csttype::cstty_int:
        cout << _integer;
        break;
    case Csttype::cstty_real:
        cout << _double;
        break;
    case Csttype::cstty_str:
        cout << _str;
        break;
    }
    return 0;
}


/////////////////////////////////////////////////////////////////////////////
llvm::Value* Program::CodeGen(CodeGenerator &Gen){
    this->Stmtlist->CodeGen(Gen);
    return NULL;
}



llvm::Value* Globalstmt::CodeGen(CodeGenerator &Gen){
    for(Basestmt* it:this->stmtlist){
        it->CodeGen(Gen);
    }
    return NULL;
}

llvm::Value* Fundeclare::CodeGen(CodeGenerator &Gen){
    std::vector<llvm::Type*> ArgTY;
    for(auto it:this->Arglist){
        llvm::Type* ty=it.second->TypeGen(Gen);
        if(ty->isArrayTy()){
            ty=ty->getArrayElementType()->getPointerTo();
        }
        ArgTY.push_back(ty);
    }

    llvm::Type* RetTY=this->retType->TypeGen(Gen);
    llvm::FunctionType* FunTY=llvm::FunctionType::get(RetTY,ArgTY,false);
    llvm::Function* FUN=llvm::Function::Create(FunTY,llvm::GlobalValue::ExternalLinkage,this->Funname,Gen.TheModule);
    if(Gen.findIDSymtable(this->Funname)==false){
        Gen.addFunSymtable(this->Funname,FUN);
    }

    return NULL;
}

llvm::Value* Fundefine::CodeGen(CodeGenerator &Gen){
    std::vector<llvm::Type*> ArgTY;
    std::vector<std::string> ArgNames;
    for(auto it:this->Arglist){
        llvm::Type* ty=it.second->TypeGen(Gen);
        if(ty->isArrayTy()){
            ty=ty->getArrayElementType()->getPointerTo();
        }
        ArgTY.push_back(ty);
        ArgNames.push_back(it.first);
    }

    llvm::Type* RetTY=this->retType->TypeGen(Gen);
    llvm::FunctionType* FunTY=llvm::FunctionType::get(RetTY,ArgTY,false);
    llvm::Function* FUN=llvm::Function::Create(FunTY,llvm::GlobalValue::ExternalLinkage,this->Funname,Gen.TheModule);
    if(Gen.findIDSymtable(this->Funname)==false){
        Gen.addFunSymtable(this->Funname,FUN);
    }
    
    llvm::BasicBlock* FunBlock=llvm::BasicBlock::Create(Gen.CodeContent,"entry",FUN);
    Gen.TheBuilder.SetInsertPoint(FunBlock);
    Gen.symTable.enterScope();
    Gen.curf=FUN;
   
    int i=0; 
    for(auto it=FUN->arg_begin();it!=FUN->arg_end();it++,i++){
        llvm::IRBuilder<> tmp(&FUN->getEntryBlock(),FUN->getEntryBlock().begin());
        llvm::AllocaInst* Varalloc=tmp.CreateAlloca(ArgTY[i],0,ArgNames[i]);
        Gen.TheBuilder.CreateStore(it,Varalloc);
        Gen.addVarSymtable(ArgNames[i],Varalloc);
    }
    this->Funbody->CodeGen(Gen);
    Gen.symTable.leaveScope();
    Gen.curf=NULL;
    return NULL;
}

llvm::Value* Vardefine::CodeGen(CodeGenerator &Gen){
    llvm::Type* ty=this->type->TypeGen(Gen);
    
    for(auto it: *(this->list)){
        if(Gen.curf==NULL){//global

        }else{
            
        }
    }
    return NULL;
}


llvm::Type* Builtintype::TypeGen(CodeGenerator &Gen){
    llvm::Type* ret;
    switch (this->Ty)
    {
        case undefined_ty : break;
        case int_ty : ret=Gen.TheBuilder.getInt32Ty(); break;
        case short_ty : ret=Gen.TheBuilder.getInt16Ty(); break;
        case long_ty : ret=Gen.TheBuilder.getInt64Ty(); break;
        case void_ty : ret=Gen.TheBuilder.getVoidTy(); break;
        case char_ty : ret=Gen.TheBuilder.getInt8Ty(); break;
        case double_ty : ret=Gen.TheBuilder.getDoubleTy(); break;
        case float_ty : ret=Gen.TheBuilder.getFloatTy(); break;
        default:break;
    }
    return ret;
}

llvm::Type* Structtype::TypeGen(CodeGenerator &Gen){
    llvm::StructType* sty=llvm::StructType::create(Gen.CodeContent,"struct." + this->structName);
    Gen.addStruct(sty,this);
    std::vector<llvm::Type*> Mems;
    for(auto it: this->structMembers){
        Mems.push_back(it.second->TypeGen(Gen));
    }
    sty->setBody(Mems);
    llvm::Type* ret=sty;
    return ret;
}

llvm::Type* Uniontype::TypeGen(CodeGenerator &Gen){
    llvm::StructType* uty=llvm::StructType::create(Gen.CodeContent,"union." + this->UnionName);
    Gen.addUnion(uty,this);
    llvm::Type* maxty=this->getMaxtype();
    if(maxty==NULL){
        this->findMaxtype(Gen);
        maxty=this->getMaxtype();
    }
    uty->setBody(std::vector<llvm::Type*>{maxty});
    llvm::Type* ret=uty;
    return ret;

}

void Uniontype::findMaxtype(CodeGenerator &Gen){
    size_t maxsize=0;
    llvm::Type* maxty=NULL;
    for(auto it: this->unionMembers){
        size_t tmp=Gen.getTypesize(it.second->TypeGen(Gen));
        if(tmp>maxsize){
            maxsize=tmp;
            maxty=it.second->TypeGen(Gen);
        }
    }
    this->maxtype=maxty;
}


llvm::Type* Enumtype::TypeGen(CodeGenerator &Gen){
    return llvm::IntegerType::getInt32Ty(Gen.CodeContent);
}

llvm::Type* Definedtype::TypeGen(CodeGenerator &Gen){
    return this->type->TypeGen(Gen);
}

llvm::Type* Pointertype::TypeGen(CodeGenerator &Gen){
    llvm::Type* bty=this->basetype->TypeGen(Gen);
    return llvm::PointerType::get(bty,0U);
}

llvm::Type* Arraytype::TypeGen(CodeGenerator &Gen){
    llvm::Type* bty=this->basetype->TypeGen(Gen);
    return llvm::ArrayType::get(bty,this->size);    
}