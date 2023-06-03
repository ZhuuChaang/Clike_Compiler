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