#ifndef _SYMBOL_TABLE_
#define _SYMBOL_TABLE_
#include <map>
#include <string>
#include <vector>




enum ValueTypes{
    FUNC_type,
    TYPE_type,
    VAR_type,
    CONST_type,
    UNDEF_type,
    SUE_type
};

class symValue{
    ValueTypes type;
    void* value; //make sure the value is newed from the heap
    int mark=0; 

public:
    symValue(ValueTypes t,void* v,int level):type(t),value(v),mark(level){}
    ~symValue(){}

    // void mark(){
    //     this->marked=true;
    // }

    // void unmark(){
    //     this->marked=false;
    // }

    int getmark(){
        return mark;
    }

    void* getValue(){
        return value;
    }

    ValueTypes getType(){
        return type;
    }
};


class Symbol_Table{
    std::map<std::string,std::vector<symValue>> Table; 
    int scopelevel=0;

public:
    void newValue(std::string varName,ValueTypes t,void* v);//insert a new value into the symbol table
    void newValueSym(std::string varName, symValue s);
    void enterScope();//mark the table when enter a scope
    void leaveScope();//delete local variables and recover the table
    symValue find(std::string varName);//return symvalue of some variable according to it's name
    ValueTypes findType(std::string varName);//return the type of some variable according to it's type
    void* findValue(std::string varName);//return the value of some variable according to it's type
    bool findhave(std::string varName);
};
#endif