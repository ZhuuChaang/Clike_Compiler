#include"ast.hpp"
#include"parser.hpp"
#include <iostream>
#include <map>
#include "CodeGen.hpp"
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
        this->stmtlist[i]->DrawNode(depth);
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

int Structtype::DrawNode(int depth){
    Indentation(depth);
    cout << "Structtype: "  << this->structName << endl;
    map<std::string,Type*>::iterator iter;
    for(iter = this->structMembers.begin(); iter != this->structMembers.end(); iter++){
        (*iter).second->DrawNode(depth + 1);
        cout << " " << (*iter).first << endl;
    }
    return 0;
}



int Uniontype::DrawNode(int depth){
    Indentation(depth);
    cout << "Uniontype: " << this->UnionName << endl;
    map<std::string,Type*>::iterator iter;
    for(iter = this->unionMembers.begin(); iter != this->unionMembers.end(); iter++){
        (*iter).second->DrawNode(depth + 1);
        cout << " " << (*iter).first << endl;
    }
    return 0;
}

int SUmemdec::DrawNode(int depth){
    Indentation(depth);
    cout << "SUmemdec:" << endl;
    this->type->DrawNode(depth + 1);
    vector<std::string>::iterator iter;
    for(iter = this->id->begin(); iter != this->id->end(); iter++){
        Indentation(depth + 1);
        cout << (*iter) << endl;
    }
    return 0;
}

int Enumtype::DrawNode(int depth){
    Indentation(depth);
    cout << "Enumtype: " << this->enumname << endl;
    std::map<std::string,int>::iterator iter;
    for(iter = this->enumMembers.begin(); iter != this->enumMembers.end(); iter++){
        Indentation(depth + 1);
        cout << (*iter).first << " " << (*iter).second << endl;
    }
    return 0;
}

int Definedtype::DrawNode(int depth){
    Indentation(depth);
    cout << "Definedtype: " << this->deftypeName << endl;
    this->type->DrawNode(depth + 1);
    return 0;
}

int Pointertype::DrawNode(int depth){
    Indentation(depth);
    cout << "Pointertype: " << endl;
    this->basetype->DrawNode(depth + 1);
    return 0;
}

int Arraytype::DrawNode(int depth){
    Indentation(depth);
    cout << "Arraytype: " << endl;
    Indentation(depth+1);
    cout << "size: " << this->size <<endl;
    this->basetype->DrawNode(depth + 1);
    return 0;
}

//statement
int Fundefine::DrawNode(int depth) {
    Indentation(depth);
    cout << "Fundefine: ";\
    //name
    cout << this->Funname << endl;
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
    cout << endl;
    vector<InitID*>::iterator iter;
    for(iter = this->list->begin(); iter != this->list->end(); iter++){
        (*iter)->DrawNode(depth + 1);
    }
    cout << endl;
    return 0;
}


int Fundeclare::DrawNode(int depth) {
    Indentation(depth);
    cout << "Fundeclare: ";
    //name
    cout << this->Funname << endl;
    //return type
    this->retType->DrawNode(depth + 1);
    cout << endl;
    //argment list
    map<std::string,Type*>::iterator iter;
    for(iter = this->Arglist.begin(); iter != this->Arglist.end(); iter++){
        (*iter).second->DrawNode(depth + 1);
        cout << " " << (*iter).first << endl;
    }
    return 0;
}

int InitID::DrawNode(int depth){
    Indentation(depth);
    cout << "InitID: " << this->VarName << endl;
    if(this->is_initiallized)
        this->eInit->DrawNode(depth + 1);
    return 0;
}

int Scope::DrawNode(int depth){
    this->Scopestmt->DrawNode(depth);
    return 0;
}

int TypeDefine::DrawNode(int depth){
    Indentation(depth);
    cout << "TypeDefine: " << endl;
    this->defined_type->DrawNode(depth + 1);
    return 0;
}

int Fielddeclare::DrawNode(int depth){
    Indentation(depth);
    cout << "Fielddeclare:" << endl;
    this->type->DrawNode(depth + 1);
    return 0;
}

int Exprstmt::DrawNode(int depth){
    Indentation(depth);
    cout << "Exprstmt: " << endl;
    this->expr->DrawNode(depth + 1);
    return 0;
}

int Returnstmt::DrawNode(int depth){
    Indentation(depth);
    if(!withvalue){
        cout << "Returnstmt without value" << endl;
    }
    else{
        cout << "Returnstmt:" << endl;
        this->ret->DrawNode(depth + 1);
    }
    return 0;
}

int Breakstmt::DrawNode(int depth){
    Indentation(depth);
    cout << "Breakstmt: " << endl;
    return 0;
}

int Continuestmt::DrawNode(int depth){
    Indentation(depth);
    cout << "Continuestmt:" << endl;
    return 0;
}

int Ifflow::DrawNode(int depth){
    Indentation(depth);
    cout << "Ifflow: " << endl;
    this->condition->DrawNode(depth + 1);
    if(this->has_body){
        this->ifbody->DrawNode(depth + 1);
        this->Elseif->DrawNode(depth);
        this->Else->DrawNode(depth);
    }
    return 0;
}

int Elseifflow::DrawNode(int depth){
    Indentation(depth);
    cout << "Elseifflow:" << endl;
    std::vector<Expr*>::iterator iter_condition;
    std::vector<Scope*>::iterator iter_body;
    for(iter_condition = this->conditions.begin(), iter_body = this->bodies.begin();
        iter_condition != this->conditions.end() && iter_body != this->bodies.end();
        iter_condition++ , iter_body++){
        (*iter_condition)->DrawNode(depth + 1);
        (*iter_body)->DrawNode(depth + 1);
    }
    return 0;
}

int Elseflow::DrawNode(int depth){
    Indentation(depth);
    cout << "Elseflow: " << endl;
    if(has_body){
        this->Elsebody->DrawNode(depth + 1);
    }
    return 0;
}

int Forflow::DrawNode(int depth){
    Indentation(depth);
    cout << "Forflow: " << endl;
    this->init->DrawNode(depth + 1);
    this->limit->DrawNode(depth + 1);
    this->step->DrawNode(depth + 1);
    if(this->has_body){
        this->Forbody->DrawNode(depth + 1);
    }
    return 0;
}

int Whileflow::DrawNode(int depth){
    Indentation(depth);
    cout << "Whileflow: " << endl;
    this->limit->DrawNode(depth + 1);
    if(this->has_body){
        this->whilebody->DrawNode(depth + 1);
    }
    return 0;
}

int Dowhileflow::DrawNode(int depth){
    Indentation(depth);
    cout << "Dowhileflow: " << endl;
    this->limit->DrawNode(depth + 1);
    this->whilebody->DrawNode(depth + 1);
    return 0;
}

int Switchflow::DrawNode(int depth){
    Indentation(depth);
    cout << "Switchflow: " << endl;
    this->switchExpr->DrawNode(depth + 1);
    std::vector<Case*>::iterator iter;
    for(iter = this->list->begin(); iter !=this->list->end(); iter++){
        (*iter)->DrawNode(depth + 1);
    }
    return 0;
}

int Case::DrawNode(int depth){
    Indentation(depth);
    cout << "Case: " << endl;
    if(this->caseExpr != nullptr){
        this->caseExpr->DrawNode(depth + 1);
    }
    this->casebody->DrawNode(depth + 1);
    return 0;
}

//expression
int Constant::DrawNode(int depth){
    Indentation(depth);
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
int Variable::DrawNode(int depth){
    Indentation(depth);
    cout << "Variable: " << this->_name << endl;
    return 0;
}

int FuncCall::DrawNode(int depth){
    Indentation(depth);
    cout << "FuncCall: " << this->_func_name << endl;
    std::vector<Expr*>::iterator iter;
    for(iter = this->_arg_list->begin(); iter != _arg_list->end(); iter++){
        (*iter)->DrawNode(depth + 1);
    }
    return 0;
}

int BinopExpr::DrawNode(int depth){
    Indentation(depth);
    cout << "BinopExpr: " << _op << endl;
    _lhs->DrawNode(depth + 1);
    _rhs->DrawNode(depth + 1);
    return 0;
}

int UnaopExpr::DrawNode(int depth){
    Indentation(depth);
    cout << "UnaopExpr: " << _op << endl;
    _operand->DrawNode(depth + 1);
    return 0;
}

int SufopExpr::DrawNode(int depth){
    Indentation(depth);
    cout << "SufopExpr:" << _op << endl;
    _operand->DrawNode(depth + 1);
    return 0;
}

int SizeofExpr::DrawNode(int depth){
    Indentation(depth);
    cout << "SizeofExpr: " << endl;
    _expr->DrawNode(depth + 1);
    return 0;
}

int SizeofType::DrawNode(int depth){
    Indentation(depth);
    cout << "SizeofType: " << endl;
    _type->DrawNode(depth + 1);
    return 0;
}

int TernaryCondition::DrawNode(int depth){
    Indentation(depth);
    cout << "TernaryCondition: " << endl;
    _condition->DrawNode(depth + 1);
    _if_then->DrawNode(depth + 1);
    _else_then->DrawNode(depth + 1);
    return 0;
}

int TypeCast::DrawNode(int depth){
    Indentation(depth);
    cout << "TypeCast: " << endl;
    _type->DrawNode(depth + 1);
    _expr->DrawNode(depth + 1);
    return 0;
}

int Subscript::DrawNode(int depth){
    Indentation(depth);
    cout << "Subscript: " << endl;
    _array->DrawNode(depth + 1);
    _index->DrawNode(depth + 1);
    return 0;
}

int MemAccessPtr::DrawNode(int depth){
    Indentation(depth);
    cout << "MemAccessPtr: " << _member << endl;
    _struct_ptr->DrawNode(depth + 1);
    return 0;
}

int MemAccessObj::DrawNode(int depth){
    Indentation(depth);
    cout << "MemAccessObj: " << _member << endl;
    _struct->DrawNode(depth + 1);
    return 0;
}


/////////////////////////////////////////////////////////////////////////////
llvm::Value* Program::CodeGen(CodeGenerator &Gen){
    this->Stmtlist->CodeGen(Gen);
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

//types 
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



//stmt
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

llvm::Value * TypeDefine::CodeGen(CodeGenerator &Gen){
    return NULL;
}

llvm::Value* Fielddeclare::CodeGen(CodeGenerator &Gen){
    return NULL;
}


llvm::Value* Vardefine::CodeGen(CodeGenerator &Gen){
    llvm::Type* ty=this->type->TypeGen(Gen);
    
    for(auto it: *(this->list)){
        if(Gen.curf==NULL){//global
            Gen.TheModule->getOrInsertGlobal(it->getname(),ty);
            llvm::GlobalVariable* gvar=Gen.TheModule->getNamedGlobal(it->getname());
            Gen.addVarSymtable(it->getname(),gvar);

            if(it->hasinit()){
                llvm::Value* inite=it->getexpr()->CodeGen(Gen);
                Gen.TheBuilder.CreateStore(inite,gvar);
            }

        }else{
            llvm::Function* FUN=Gen.curf;
            llvm::IRBuilder<> tmp(&FUN->getEntryBlock(),FUN->getEntryBlock().begin());
            llvm::AllocaInst* def=tmp.CreateAlloca(ty,0,it->getname());
            Gen.addVarSymtable(it->getname(),def);

            if(it->hasinit()){
                llvm::Value* inite=it->getexpr()->CodeGen(Gen);
                Gen.TheBuilder.CreateStore(inite,def);
            }
        }
    }
    return NULL;
}

llvm::Value* Stmt::CodeGen(CodeGenerator &Gen){
    for(auto it: this->stmtlist){
        it->CodeGen(Gen);
    }
    return NULL;
}

llvm::Value* Scope::CodeGen(CodeGenerator &Gen){
    Gen.symTable.enterScope();

    for(auto it: this->Scopestmt->stmtlist){
        if(Gen.TheBuilder.GetInsertBlock()->getTerminator()){
            break;
        }else{
            it->CodeGen(Gen);
        }
    }

    if(this->isfun){
        if(!Gen.TheBuilder.GetInsertBlock()->getTerminator()){
            llvm::Type* retty=Gen.curf->getReturnType();
            if(retty->isVoidTy()){
                Gen.TheBuilder.CreateRetVoid();
            }else{
                Gen.TheBuilder.CreateRet(llvm::UndefValue::get(retty));
            }
        }
    }

    Gen.symTable.leaveScope();

    return NULL;
}


llvm::Value* Exprstmt::CodeGen(CodeGenerator &Gen){
    this->expr->CodeGen(Gen);
    return NULL;
}


//expr
////////////////////////////////////////////////////////////
llvm::Value* Constant::CodeGen(CodeGenerator &Gen){
    return NULL;
}


llvm::Value* Variable::CodeGen(CodeGenerator &Gen){
    return NULL;
}


llvm::Value* FuncCall::CodeGen(CodeGenerator &Gen){
    return NULL;
}

llvm::Value* BinopExpr::CodeGen(CodeGenerator &Gen){
    return NULL;
}

llvm::Value* UnaopExpr::CodeGen(CodeGenerator &Gen){
    return NULL;
}

llvm::Value* SufopExpr::CodeGen(CodeGenerator &Gen){
    return NULL;
}

llvm::Value* SizeofExpr::CodeGen(CodeGenerator &Gen){
    return NULL;
}

llvm::Value* SizeofType::CodeGen(CodeGenerator &Gen){
    return NULL;
}

llvm::Value* TernaryCondition::CodeGen(CodeGenerator &Gen){
    return NULL;
}

llvm::Value* TypeCast::CodeGen(CodeGenerator &Gen){
    return NULL;
}

llvm::Value* Subscript::CodeGen(CodeGenerator &Gen){
    return NULL;
}

llvm::Value* MemAccessPtr::CodeGen(CodeGenerator &Gen){
    return NULL;
}

llvm::Value* MemAccessObj::CodeGen(CodeGenerator &Gen){
    return NULL;
}

//////////////////
llvm::Value* Constant::LeftValueGen(CodeGenerator &Gen){
    return NULL;
}


llvm::Value* Variable::LeftValueGen(CodeGenerator &Gen){
    return NULL;
}



llvm::Value* FuncCall::LeftValueGen(CodeGenerator &Gen){
    return NULL;
}

llvm::Value* BinopExpr::LeftValueGen(CodeGenerator &Gen){
    return NULL;
}

llvm::Value* UnaopExpr::LeftValueGen(CodeGenerator &Gen){
    return NULL;
}

llvm::Value* SufopExpr::LeftValueGen(CodeGenerator &Gen){
    return NULL;
}

llvm::Value* SizeofExpr::LeftValueGen(CodeGenerator &Gen){
    return NULL;
}

llvm::Value* SizeofType::LeftValueGen(CodeGenerator &Gen){
    return NULL;
}

llvm::Value* TernaryCondition::LeftValueGen(CodeGenerator &Gen){
    return NULL;
}

llvm::Value* TypeCast::LeftValueGen(CodeGenerator &Gen){
    return NULL;
}

llvm::Value* Subscript::LeftValueGen(CodeGenerator &Gen){
    return NULL;
}

llvm::Value* MemAccessPtr::LeftValueGen(CodeGenerator &Gen){
    return NULL;
}

llvm::Value* MemAccessObj::LeftValueGen(CodeGenerator &Gen){
    return NULL;
}