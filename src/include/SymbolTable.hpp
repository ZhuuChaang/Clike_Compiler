#ifndef _SYMBOL_TABLE_
#define _SYMBOL_TABLE_
#include <map>
#include <string>
#include <vector>




enum ValueTypes{
    INT_type,
    FLOAT_type,
    DOUBLE_type,
    STRING_type,
    ENUM_type,
    CONSTANT_type,
    STRUCT_type
};

class symValue{
    ValueTypes type;
    void* value; //make sure the value is newed from the heap
    bool marked=false; 

public:
    symValue(ValueTypes t,void* v,bool m):type(t),value(v),marked(m){}
    ~symValue(){
        delete this->value;
    }

    void mark(){
        this->marked=true;
    }

    void unmark(){
        this->marked=false;
    }

    bool ismarked(){
        return marked;
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

public:
    void newValue(std::string varName,ValueTypes t,void* v,bool m);//insert a new value into the symbol table
    void newValueSym(std::string varName, symValue s);
    void enterScope();//mark the table when enter a scope
    void leaveScope();//delete local variables and recover the table
    symValue find(std::string varName);//return symvalue of some variable according to it's name
    ValueTypes findType(std::string varName);//return the type of some variable according to it's type
    void* findValue(std::string varName);//return the value of some variable according to it's type

};
#endif