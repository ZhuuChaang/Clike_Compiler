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