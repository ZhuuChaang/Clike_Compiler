#include"ast.hpp"
#include <iostream>
#include <map>
using namespace std;

int Program::DrawNode() {
    cout << "Program: " << endl;
    this->Stmtlist->DrawNode();
    return 0;
}

int Globalstmt::DrawNode() {
    cout << "Globalstmt: " << endl;
    for(int i = 0; i < this->stmtlist.size(); i++){
        cout << "Stmt " << i << ":" << endl;
        this->stmtlist[i]->DrawNode();
    }
    cout << endl;
    return 0;
}

int Stmt::DrawNode(){
    vector<Basestmt*>::iterator iter;
    for(iter = stmtlist.begin(); iter != stmtlist.end(); iter++){
        (*iter)->DrawNode();
    }
    return 0;
}

//type

int Builtintype::DrawNode() {
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
int Fundefine::DrawNode() {
    cout << "Fundefine: " << endl;
    this->retType->DrawNode();
    cout << this->Funname;
    map<std::string,Type*>::iterator iter;
    for(iter = this->Arglist.begin(); iter != this->Arglist.end(); iter++){
        (*iter).second->DrawNode();
        cout << (*iter).first << " ";
        cout << ", ";
    }
    cout << endl;
    this->Funbody->DrawNode();
    cout << endl;
    return 0;
}


int Scope::DrawNode(){
    this->Scopestmt->DrawNode();
    return 0;
}

int Returnstmt::DrawNode(){
    if(!withvalue){
        cout << "Return without value" << endl;
    }
    else{
        cout << "Return: ";
        this->ret->DrawNode();
    }
    return 0;
}

//expression
int Constant::DrawNode(){
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
}

llvm::Type* Uniontype::TypeGen(CodeGenerator &Gen){

}

llvm::Type* Enumtype::TypeGen(CodeGenerator &Gen){
    
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