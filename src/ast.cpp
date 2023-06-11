#include"ast.hpp"
#include"parser.hpp"
#include <iostream>
#include <map>
#include "CodeGen.hpp"
using namespace std;

//provide: 
//int to bool
//int between different size
// float to int
llvm::Value* CodeGen_TypeCast(llvm::Value* v, llvm::Type* toty, CodeGenerator& Gen){
    llvm::Type* fromty=v->getType();
    if(fromty==toty){
        return v;
    }else if(toty==Gen.TheBuilder.getInt1Ty()){
        if(fromty->isIntegerTy()){
            return Gen.TheBuilder.CreateICmpNE(v,llvm::ConstantInt::get((llvm::IntegerType*)v->getType(), 0, true));
        }else{
            return NULL;
        }
    }else if(fromty->isFloatingPointTy()&&toty->isIntegerTy()){
        return Gen.TheBuilder.CreateFPToSI(v,toty);
    }else{
        return NULL;
    }
}

//int to double
//int16 to int32 to int64
bool AutoTypeUpgrade(llvm::Value*& lhs, llvm::Value*& rhs, CodeGenerator& Gen){
    llvm::Type* lhs_type = lhs->getType();
    llvm::Type* rhs_type = rhs->getType();
    if(lhs_type->isIntegerTy() && rhs_type->isIntegerTy()){
        size_t width_l = ((llvm::IntegerType*)lhs_type)->getBitWidth();
        size_t width_r = ((llvm::IntegerType*)rhs_type)->getBitWidth();
        if(width_l < width_r)
            lhs = Gen.TheBuilder.CreateIntCast(lhs, rhs_type, width_l != 1);
        else if(width_l > width_r)
            rhs = Gen.TheBuilder.CreateIntCast(rhs, lhs_type, width_r != 1);
        return true;
    }
    else if(lhs_type->isFloatingPointTy() && rhs_type->isFloatingPointTy()){
        if(lhs_type->isFloatTy() && rhs_type->isDoubleTy())
            lhs = Gen.TheBuilder.CreateFPCast(lhs, Gen.TheBuilder.getDoubleTy());
        else if(rhs_type->isFloatTy() && lhs_type->isDoubleTy())
            rhs = Gen.TheBuilder.CreateFPCast(rhs, Gen.TheBuilder.getDoubleTy());
        return true;
    }
    else if(lhs_type->isIntegerTy() && rhs_type->isFloatingPointTy()){
        lhs = lhs_type->isIntegerTy(1) ?
            Gen.TheBuilder.CreateUIToFP(lhs, rhs_type) : Gen.TheBuilder.CreateSIToFP(lhs, rhs_type);
        return true;
    }
    else if(rhs_type->isIntegerTy() && lhs_type->isFloatingPointTy()){
        rhs = rhs_type->isIntegerTy(1) ?
            Gen.TheBuilder.CreateUIToFP(rhs, lhs_type) : Gen.TheBuilder.CreateSIToFP(rhs, lhs_type);
        return true;
    }
    else return false;
}


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
    cout << endl;
    return 0;
}

int Structtype::DrawNode(int depth){
    Indentation(depth);
    cout << "Structtype: "  << this->structName << endl;
    map<std::string,Type*>::iterator iter;
    for(iter = this->structMembers.begin(); iter != this->structMembers.end(); iter++){
        (*iter).second->DrawNode(depth + 1);
        Indentation(depth + 1);
        cout << (*iter).first << endl;
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
    if(this->type!=NULL){
        this->type->DrawNode(depth + 1);
    }
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
    vector<InitID*>::iterator iter;
    for(iter = this->list->begin(); iter != this->list->end(); iter++){
        (*iter)->DrawNode(depth + 1);
    }
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
    cout << "Constant: ";
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
    cout << endl;
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
    if(this->type==NULL){
        this->gettype(Gen);
    }
    return this->type->TypeGen(Gen);
}

void Definedtype::gettype(CodeGenerator &Gen){
    Type* ty=(Type*)Gen.symTable.findValue(this->deftypeName);
    this->type=ty;
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
    Gen.symTable.newValue(this->defined_type->getname(),TYPE_type,this->defined_type->getoriginty());
    return NULL;
}

llvm::Value* Fielddeclare::CodeGen(CodeGenerator &Gen){
    llvm::Type* ty=this->type->TypeGen(Gen);
    std::string name=type->getname();
    Gen.symTable.newValue(name,SUE_type,this->type);
    return NULL;
}


llvm::Value* Vardefine::CodeGen(CodeGenerator &Gen){
    llvm::Type* ty=this->type->TypeGen(Gen);
    
    for(auto it: *(this->list)){
        if(Gen.curf==NULL){//global
            Gen.TheModule->getOrInsertGlobal(it->getname(),ty);
            llvm::GlobalVariable* gvar=Gen.TheModule->getNamedGlobal(it->getname());
            gvar->setLinkage(llvm::GlobalValue::PrivateLinkage);
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


llvm::Value* Ifflow::CodeGen(CodeGenerator &Gen){
    std::vector<llvm::Value*> conlist;
    std::vector<Scope*> scopelist;
    conlist.push_back(CodeGen_TypeCast(this->condition->CodeGen(Gen),Gen.TheBuilder.getInt1Ty(),Gen));
    scopelist.push_back(this->ifbody);
    if(this->Elseif!=NULL&&this->Elseif->conditions.size()!=0){
        for(int i=0;i<this->Elseif->conditions.size();i++){
            llvm::Value* tmpcon=this->Elseif->conditions[i]->CodeGen(Gen);
            conlist.push_back(CodeGen_TypeCast(tmpcon,Gen.TheBuilder.getInt1Ty(),Gen));
            scopelist.push_back(this->Elseif->bodies[i]);
        }
    }

    llvm::Function* FUN=Gen.curf;

    llvm::BasicBlock* ifend=llvm::BasicBlock::Create(Gen.CodeContent,"ifend");

    for(int i=0;i<conlist.size();i++){
        llvm::BasicBlock* ifbeginI=llvm::BasicBlock::Create(Gen.CodeContent,std::string("ifbegin").append(std::to_string(i)));
        llvm::BasicBlock* elsebeginI=llvm::BasicBlock::Create(Gen.CodeContent,std::string("elsebegin").append(std::to_string(i)));
        Gen.TheBuilder.CreateCondBr(conlist[i],ifbeginI,elsebeginI);

        FUN->getBasicBlockList().push_back(ifbeginI);
        Gen.TheBuilder.SetInsertPoint(ifbeginI);

        scopelist[i]->CodeGen(Gen);

        if(Gen.TheBuilder.GetInsertBlock()->getTerminator()==NULL){
            Gen.TheBuilder.CreateBr(ifend);
        }

        FUN->getBasicBlockList().push_back(elsebeginI);
        Gen.TheBuilder.SetInsertPoint(elsebeginI);        
    }

    if(this->Else!=NULL&&this->Else->has_body){
        this->Else->Elsebody->CodeGen(Gen);
    }
    if(Gen.TheBuilder.GetInsertBlock()->getTerminator()==NULL){
        Gen.TheBuilder.CreateBr(ifend);
    }


    if(ifend->hasNPredecessorsOrMore(1)){
        FUN->getBasicBlockList().push_back(ifend);
        Gen.TheBuilder.SetInsertPoint(ifend);
    }

//old version for reservation
/////////////////////////////////////////
    // llvm::Value* condition=this->condition->CodeGen(Gen);
    //  condition=CodeGen_TypeCast(condition,Gen.TheBuilder.getInt1Ty(),Gen);

    // llvm::Function* FUN=Gen.curf;
    // llvm::BasicBlock* ifbegin=llvm::BasicBlock::Create(Gen.CodeContent,"ifbegin");
    // llvm::BasicBlock* elsebegin=llvm::BasicBlock::Create(Gen.CodeContent,"elsebegin");
    // llvm::BasicBlock* ifend=llvm::BasicBlock::Create(Gen.CodeContent,"ifend");
    
    // Gen.TheBuilder.CreateCondBr(condition,ifbegin,elsebegin);

    // FUN->getBasicBlockList().push_back(ifbegin);
    // Gen.TheBuilder.SetInsertPoint(ifbegin);
    // if(has_body){
    //     this->ifbody->CodeGen(Gen);
    // }
    // if(Gen.TheBuilder.GetInsertBlock()->getTerminator()==NULL){
    //     Gen.TheBuilder.CreateBr(ifend);
    // }

    // FUN->getBasicBlockList().push_back(elsebegin);
    // Gen.TheBuilder.SetInsertPoint(elsebegin);
    // if(this->Else!=NULL&&this->Else->has_body){
    //     this->Else->Elsebody->CodeGen(Gen);
    // }
    // if(Gen.TheBuilder.GetInsertBlock()->getTerminator()==NULL){
    //     Gen.TheBuilder.CreateBr(ifend);
    // }

    // if(ifend->hasNPredecessorsOrMore(1)){
    //     FUN->getBasicBlockList().push_back(ifend);
    //     Gen.TheBuilder.SetInsertPoint(ifend);
    // }
    return NULL;
}

llvm::Value* Elseflow::CodeGen(CodeGenerator &Gen){
    return NULL;
}

llvm::Value* Elseifflow::CodeGen(CodeGenerator &Gen){
    return NULL;
}


llvm::Value* Forflow::CodeGen(CodeGenerator &Gen){
    llvm::Function* FUN=Gen.curf;
    llvm::BasicBlock* forcon=llvm::BasicBlock::Create(Gen.CodeContent,"condition");
    llvm::BasicBlock* forscope=llvm::BasicBlock::Create(Gen.CodeContent,"body");
    llvm::BasicBlock* forend=llvm::BasicBlock::Create(Gen.CodeContent,"leave");

    this->init->CodeGen(Gen);
    if(Gen.TheBuilder.GetInsertBlock()->getTerminator()==NULL){
        Gen.TheBuilder.CreateBr(forcon);
    }

    FUN->getBasicBlockList().push_back(forcon);
    Gen.TheBuilder.SetInsertPoint(forcon);

    llvm::Value* condvalue=this->limit->CodeGen(Gen);
    condvalue=CodeGen_TypeCast(condvalue,Gen.TheBuilder.getInt1Ty(),Gen);
    Gen.TheBuilder.CreateCondBr(condvalue,forscope,forend);

    FUN->getBasicBlockList().push_back(forscope);
    Gen.TheBuilder.SetInsertPoint(forscope);

    if(this->has_body){
        Gen.nextblockstack.push_back(forcon);
        Gen.endblockstack.push_back(forend);
        this->Forbody->CodeGen(Gen);
        Gen.nextblockstack.pop_back();
        Gen.endblockstack.pop_back();
    }

    this->step->CodeGen(Gen);

    Gen.TheBuilder.CreateBr(forcon);

    if(forend->hasNPredecessorsOrMore(1)){
        FUN->getBasicBlockList().push_back(forend);
        Gen.TheBuilder.SetInsertPoint(forend);
    }


    return NULL;
}


llvm::Value* Whileflow::CodeGen(CodeGenerator &Gen){
    llvm::Value* condition=this->limit->CodeGen(Gen);
     condition=CodeGen_TypeCast(condition,Gen.TheBuilder.getInt1Ty(),Gen);

    llvm::Function* FUN=Gen.curf;
    llvm::BasicBlock* con=llvm::BasicBlock::Create(Gen.CodeContent,"con");
    llvm::BasicBlock* whilebegin=llvm::BasicBlock::Create(Gen.CodeContent,"whilebegin");
    llvm::BasicBlock* whileend=llvm::BasicBlock::Create(Gen.CodeContent,"whileend");

    Gen.TheBuilder.CreateBr(con);
    FUN->getBasicBlockList().push_back(con);
    Gen.TheBuilder.SetInsertPoint(con);

    Gen.TheBuilder.CreateCondBr(condition,whilebegin,whileend);
    FUN->getBasicBlockList().push_back(whilebegin);
    Gen.TheBuilder.SetInsertPoint(whilebegin);
    if(this->has_body){
        Gen.nextblockstack.push_back(con);
        Gen.endblockstack.push_back(whileend);
        this->whilebody->CodeGen(Gen);
        Gen.nextblockstack.pop_back();
        Gen.endblockstack.pop_back();
    }

    if(Gen.TheBuilder.GetInsertBlock()->getTerminator()==NULL){
        Gen.TheBuilder.CreateBr(con);
    }
    
    FUN->getBasicBlockList().push_back(whileend);
    Gen.TheBuilder.SetInsertPoint(whileend);
    return NULL;
}

llvm::Value* Dowhileflow::CodeGen(CodeGenerator &Gen){
    return NULL;
}

llvm::Value* Returnstmt::CodeGen(CodeGenerator &Gen){
    llvm::Function* FUN=Gen.curf;
    if(this->ret==NULL){
        if(FUN->getReturnType()->isVoidTy()){
            Gen.TheBuilder.CreateRetVoid();
        }
    }else{
        //remember to add typecast
        llvm::Value* ret=this->ret->CodeGen(Gen);
        if(ret->getType()!=FUN->getReturnType()){
            ret=CodeGen_TypeCast(ret,FUN->getReturnType(),Gen);
        }
        Gen.TheBuilder.CreateRet(ret);
    }
    return NULL;
}

llvm::Value* Breakstmt::CodeGen(CodeGenerator &Gen){
    llvm::BasicBlock* toblock=Gen.endblockstack.back();
    Gen.TheBuilder.CreateBr(toblock);
    return NULL;
}

llvm::Value* Continuestmt::CodeGen(CodeGenerator &Gen){
    llvm::BasicBlock* toblock=Gen.nextblockstack.back();
    Gen.TheBuilder.CreateBr(toblock);
    return NULL;
}



//expr
////////////////////////////////////////////////////////////
llvm::Value* Constant::CodeGen(CodeGenerator& Gen){
    switch (this->getType())
    {
    case Csttype::cstty_bool :
        return Gen.TheBuilder.getInt1(this->b);
        break;
    case Csttype::cstty_char :
        return Gen.TheBuilder.getInt8(this->c);
        break;
    case Csttype::cstty_int :
        return Gen.TheBuilder.getInt32(this->_integer);
        break;
    case Csttype::cstty_real :
        return llvm::ConstantFP::get(llvm::Type::getDoubleTy(Gen.CodeContent), this->_double);
        break;
    case Csttype::cstty_str :
        return Gen.TheBuilder.CreateGlobalStringPtr(this->_str);
    }
    return NULL;
}


llvm::Value* Variable::CodeGen(CodeGenerator &Gen){
    llvm::Value* var_ptr = (llvm::Value*) Gen.symTable.findValue(this->_name);
    llvm::Value* value;
    if(var_ptr){
        if(var_ptr->getType()->getNonOpaquePointerElementType()->isArrayTy()){
            llvm::PointerType* ty=var_ptr->getType()->getNonOpaquePointerElementType()->getArrayElementType()->getPointerTo();
            value=Gen.TheBuilder.CreatePointerCast(var_ptr,ty);
        }else{
            value=Gen.TheBuilder.CreateLoad(var_ptr->getType()->getPointerElementType(), var_ptr);
        }   

        return value;
    }
    else std::cout << "Variable not define." << std::endl;
    return NULL;
}


llvm::Value* FuncCall::CodeGen(CodeGenerator &Gen){
    llvm::Function* func = (llvm::Function*) Gen.symTable.findValue(this->_func_name);
    if(!func){
        cout << "func have not been define." << endl;
        return NULL;
    }
    //number of args
    if(func->isVarArg() && this->_arg_list->size() < func->arg_size() ||
    !func->isVarArg() && this->_arg_list->size() != func->arg_size()){
        cout << "func args do not match define." << endl;
        return NULL;
    }
    //type of args
    std::vector<llvm::Value*> arg_list;
    int index = 0;
    for(auto iter = func->arg_begin(); iter < func->arg_end();iter++, index++){
        llvm::Value* arg = this->_arg_list->at(index)->CodeGen(Gen);
        arg = CodeGen_TypeCast(arg, iter->getType(), Gen);
        if(arg == NULL){
            cout << "arg type does not match." << endl;
            return nullptr;
        }
        arg_list.push_back(arg);
    }

    if(func->isVarArg()){
        for(int i=index;i<this->_arg_list->size();i++){
            llvm::Value* arg=this->_arg_list->at(i)->CodeGen(Gen);
            arg_list.push_back(arg);
        }
    }
    return Gen.TheBuilder.CreateCall(func, arg_list);
}

llvm::Value* BinopExpr::CodeGen(CodeGenerator &Gen){
    switch (this->_op){
    llvm::Value* lhs;
    llvm::Value* rhs;
    case ASSIGN:
        lhs = this->LeftValueGen(Gen);
        if(lhs->getType()->getNonOpaquePointerElementType()->isArrayTy()){
            return Gen.TheBuilder.CreatePointerCast(lhs,
                lhs->getType()->getNonOpaquePointerElementType()->getArrayElementType()->getPointerTo());
        }
        else
            return Gen.TheBuilder.CreateLoad(lhs->getType()->getNonOpaquePointerElementType(), lhs);
    case ADD:
        lhs = this->_lhs->CodeGen(Gen);
        rhs = this->_rhs->CodeGen(Gen);
        if(AutoTypeUpgrade(lhs, rhs, Gen)){
            if(lhs->getType()->isIntegerTy())
                return Gen.TheBuilder.CreateAdd(lhs, rhs);
            else
                return Gen.TheBuilder.CreateFAdd(lhs, rhs);
        }
        else{
            cout << "fail to auto type cast in addition." << endl;
            return NULL;
        }
    case SUB:
        lhs = this->_lhs->CodeGen(Gen);
        rhs = this->_rhs->CodeGen(Gen);
        if(AutoTypeUpgrade(lhs, rhs, Gen)){
            if(lhs->getType()->isIntegerTy())
                return Gen.TheBuilder.CreateSub(lhs, rhs);
            else
                return Gen.TheBuilder.CreateFSub(lhs, rhs);
        }
        else{
            cout << "fail to auto type cast in subtraction." << endl;
            return NULL;
        }
    case MUL:
        lhs = this->_lhs->CodeGen(Gen);
        rhs = this->_rhs->CodeGen(Gen);
        if(AutoTypeUpgrade(lhs, rhs, Gen)){
            if(lhs->getType()->isIntegerTy())
                return Gen.TheBuilder.CreateMul(lhs, rhs);
            else
                return Gen.TheBuilder.CreateFMul(lhs, rhs);
        }
        else{
            cout << "fail to auto type cast in multiplication." << endl;
            return NULL;
        }
    case DIV:
        lhs = this->_lhs->CodeGen(Gen);
        rhs = this->_rhs->CodeGen(Gen);
        if(AutoTypeUpgrade(lhs, rhs, Gen)){
            if(lhs->getType()->isIntegerTy())
                return Gen.TheBuilder.CreateSDiv(lhs, rhs);
            else
                return Gen.TheBuilder.CreateFDiv(lhs, rhs);
        }
        else{
            cout << "fail to auto type cast in division." << endl;
            return NULL;
        }
    case MOD:
        lhs = this->_lhs->CodeGen(Gen);
        rhs = this->_rhs->CodeGen(Gen);
        if(!lhs->getType()->isIntegerTy() || !lhs->getType()->isIntegerTy()){
            cout << "modulo apply only to integer." << endl;
            return NULL;
        }
        AutoTypeUpgrade(lhs, rhs, Gen);
        return Gen.TheBuilder.CreateSRem(lhs, rhs);
    case EQ:
        lhs = this->_lhs->CodeGen(Gen);
        rhs = this->_rhs->CodeGen(Gen);
        if(AutoTypeUpgrade(lhs, rhs, Gen)){
            if(lhs->getType()->isIntegerTy()){
                return Gen.TheBuilder.CreateICmpEQ(lhs, rhs);
            }
            else{
                return Gen.TheBuilder.CreateFCmpOEQ(lhs, rhs);
            }
        }
        cout << "typecast error in logical equal." << endl;
        return NULL;
    case NE:
        lhs = this->_lhs->CodeGen(Gen);
        rhs = this->_rhs->CodeGen(Gen);
        if(AutoTypeUpgrade(lhs, rhs, Gen)){
            if(lhs->getType()->isIntegerTy()){
                return Gen.TheBuilder.CreateICmpNE(lhs, rhs);
            }
            else{
                return Gen.TheBuilder.CreateFCmpONE(lhs, rhs);
            }
        }
        cout << "typecast error in logical not equal." << endl;
        return NULL;
    case GT:
        lhs = this->_lhs->CodeGen(Gen);
        rhs = this->_rhs->CodeGen(Gen);
        if(AutoTypeUpgrade(lhs, rhs, Gen)){
            if(lhs->getType()->isIntegerTy()){
                return Gen.TheBuilder.CreateICmpSGT(lhs, rhs);
            }
            else{
                return Gen.TheBuilder.CreateFCmpOGT(lhs, rhs);
            }
        }
        cout << "typecast error in logical greater than." << endl;
        return NULL;
    case LT:
        lhs = this->_lhs->CodeGen(Gen);
        rhs = this->_rhs->CodeGen(Gen);
        if(AutoTypeUpgrade(lhs, rhs, Gen)){
            if(lhs->getType()->isIntegerTy()){
                return Gen.TheBuilder.CreateICmpSLT(lhs, rhs);
            }
            else{
                return Gen.TheBuilder.CreateFCmpOLT(lhs, rhs);
            }
        }
        cout << "typecast error in logical less than." << endl;
        return NULL;
    case GE:
        lhs = this->_lhs->CodeGen(Gen);
        rhs = this->_rhs->CodeGen(Gen);
        if(AutoTypeUpgrade(lhs, rhs, Gen)){
            if(lhs->getType()->isIntegerTy()){
                return Gen.TheBuilder.CreateICmpSGE(lhs, rhs);
            }
            else{
                return Gen.TheBuilder.CreateFCmpOGE(lhs, rhs);
            }
        }
        cout << "typecast error in logical greater equal." << endl;
        return NULL;
    case LE:
        lhs = this->_lhs->CodeGen(Gen);
        rhs = this->_rhs->CodeGen(Gen);
        if(AutoTypeUpgrade(lhs, rhs, Gen)){
            if(lhs->getType()->isIntegerTy()){
                return Gen.TheBuilder.CreateICmpSLE(lhs, rhs);
            }
            else{
                return Gen.TheBuilder.CreateFCmpOLE(lhs, rhs);
            }
        }
        cout << "typecast error in logical less equal." << endl;
        return NULL;
    case AND:
        lhs = this->_lhs->CodeGen(Gen);
        rhs = this->_rhs->CodeGen(Gen);
        if(lhs->getType() != Gen.TheBuilder.getInt1Ty()){
            if(lhs->getType()->isIntegerTy()){
                lhs = Gen.TheBuilder.CreateICmpNE(lhs, llvm::ConstantInt::get((llvm::IntegerType*)lhs->getType(), 0, true));
            }
            else{
                cout << "operators of logical and must be boolean." << endl;
                return NULL;
            }
        }
        if(rhs->getType() != Gen.TheBuilder.getInt1Ty()){
            if(rhs->getType()->isIntegerTy()){
                rhs = Gen.TheBuilder.CreateICmpNE(rhs, llvm::ConstantInt::get((llvm::IntegerType*)rhs->getType(), 0, true));
            }
            else{
                cout << "operators of logical and must be boolean." << endl;
                return NULL;
            }
        }
        return Gen.TheBuilder.CreateLogicalAnd(lhs, rhs);
    case OR:
        lhs = this->_lhs->CodeGen(Gen);
        rhs = this->_rhs->CodeGen(Gen);
        if(lhs->getType() != Gen.TheBuilder.getInt1Ty()){
            if(lhs->getType()->isIntegerTy()){
                lhs = Gen.TheBuilder.CreateICmpNE(lhs, llvm::ConstantInt::get((llvm::IntegerType*)lhs->getType(), 0, true));
            }
            else{
                cout << "operators of logical and must be boolean." << endl;
                return NULL;
            }
        }
        if(rhs->getType() != Gen.TheBuilder.getInt1Ty()){
            if(rhs->getType()->isIntegerTy()){
                rhs = Gen.TheBuilder.CreateICmpNE(rhs, llvm::ConstantInt::get((llvm::IntegerType*)rhs->getType(), 0, true));
            }
            else{
                cout << "operators of logical and must be boolean." << endl;
                return NULL;
            }
        }
        return Gen.TheBuilder.CreateLogicalOr(lhs, rhs);
    case COMMA:
        
    default:
        break;
    }
    return NULL;
}

llvm::Value* UnaopExpr::CodeGen(CodeGenerator &Gen){
    switch (this->_op){
    case 1 :
        /* code */
        break;
    
    default:
        break;
    }
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
    llvm::Value* casted = CodeGen_TypeCast(this->_expr->CodeGen(Gen), this->_type->TypeGen(Gen), Gen);
    if(!casted){
        cout << "fail to cast type." << endl;
        return nullptr;
    }
    return casted;
}

llvm::Value* Subscript::CodeGen(CodeGenerator &Gen){
    llvm::Value* subscript_ptr = this->LeftValueGen(Gen);
    return Gen.TheBuilder.CreateLoad(
        subscript_ptr->getType()->getNonOpaquePointerElementType(), 
        subscript_ptr);
}

llvm::Value* MemAccessPtr::CodeGen(CodeGenerator &Gen){
    return NULL;
}

llvm::Value* MemAccessObj::CodeGen(CodeGenerator &Gen){
    return NULL;
}

//////////////////
llvm::Value* Constant::LeftValueGen(CodeGenerator &Gen){
    cout << "constant cannot be leftvalue" << endl;
    return NULL;
}


llvm::Value* Variable::LeftValueGen(CodeGenerator &Gen){
    llvm::Value* var_ptr = (llvm::Value*) Gen.symTable.findValue(this->_name);
    if(var_ptr){
        return var_ptr;
    }
    else{
        cout << "Variable not define." << endl;
        return NULL;
    }
}



llvm::Value* FuncCall::LeftValueGen(CodeGenerator &Gen){
    cout << "funccall cannot be leftvalue." << endl;
    return NULL;
}

llvm::Value* BinopExpr::LeftValueGen(CodeGenerator &Gen){
    switch (this->_op){
        llvm::Value* lhs;
        llvm::Value* rhs;
    case ASSIGN:
        lhs = this->_lhs->LeftValueGen(Gen);
        rhs = this->_rhs->CodeGen(Gen);
        rhs = CodeGen_TypeCast(rhs, lhs->getType()->getNonOpaquePointerElementType(), Gen);
        if(!rhs){
            cout << "cannot cast value type in assignment." << endl;
            return nullptr;
        }
        Gen.TheBuilder.CreateStore(rhs, lhs);
        return lhs;
    case ADD:
        cout << "addition cannot be leftvalue." << endl;
        return NULL;
    case SUB:
        cout << "subtraction cannot be leftvalue." << endl;
        return NULL;
    case MUL:
        cout << "multiplication cannot be leftvalue." << endl;
        return NULL;
    case DIV:
        cout << "division cannot be leftvalue." << endl;
        return NULL;
    case MOD:
        cout << "modulo cannot be leftvalue." << endl;
        return NULL;
    case EQ:
        cout << "logical eq cannot be leftvalue." << endl;
        return NULL;
    case NE:
        cout << "logical ne cannot be leftvalue." << endl;
        return NULL;
    case GT:
        cout << "logical GT cannot be leftvalue." << endl;
        return NULL;
    case LT:
        cout << "logical LT cannot be leftvalue." << endl;
        return NULL;
    case GE:
        cout << "logical GE cannot be leftvalue." << endl;
        return NULL;
    case LE:
        cout << "logical le cannot be leftvalue." << endl;
        return NULL;
    case AND:
        cout << "logical and cannot be leftvalue." << endl;
        return NULL;
    case OR:
        cout << "logical or cannot be leftvalue." << endl;
        return NULL;
    default:
        break;
    }
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
    cout << "type cast cannot be leftvalue." << endl;
    return NULL;
}

llvm::Value* Subscript::LeftValueGen(CodeGenerator &Gen){
    //array
    llvm::Value* array_ptr = this->_array->CodeGen(Gen);
    if(!array_ptr->getType()->isPointerTy()){
        cout << "not a array type." << endl;
    }
    llvm::Value* index = this->_index->CodeGen(Gen);
    if(!index->getType()->isIntegerTy()){
        cout << "array index is supposed to be integer." << endl;
    }
    return Gen.TheBuilder.CreateGEP(
        array_ptr->getType()->getNonOpaquePointerElementType(),
        array_ptr, index);
}

llvm::Value* MemAccessPtr::LeftValueGen(CodeGenerator &Gen){
    return NULL;
}

llvm::Value* MemAccessObj::LeftValueGen(CodeGenerator &Gen){
    return NULL;
}