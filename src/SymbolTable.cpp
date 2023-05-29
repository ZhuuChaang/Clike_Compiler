#include "SymbolTable.hpp"

void Symbol_Table::newValue(std::string varName,ValueTypes t,void* v,bool m){
    symValue s(t,v,m);
    this->newValueSym(varName,s);
}

void Symbol_Table::newValueSym(std::string varName, symValue s){
    if(Table.find(varName)==Table.end()){
        std::vector<symValue> Vstack;
        Table.insert(std::pair<std::string,std::vector<symValue>>(varName,Vstack));
    }
    Table[varName].push_back(s);
}

void Symbol_Table::enterScope(){
    for(auto& it:Table){
        int end=it.second.size()-1;
        it.second[end].mark();
    }
}

void Symbol_Table::leaveScope(){
    std::vector<std::string> localVs;
    for(auto& it:Table){
        int end=it.second.size()-1;
        for(int i=end;i>=0;i--){
            if(it.second[i].ismarked()){
                it.second[i].unmark();
                break;
            }
            it.second.pop_back();
        }
        if(it.second.size()==0){
            localVs.push_back(it.first);
        }
    }

    for(auto it:localVs){
        Table.erase(it);
    }
    
}

symValue Symbol_Table::find(std::string varName){
    auto it=Table.find(varName);
    int end=it->second.size()-1;
    return it->second[end];
}

ValueTypes Symbol_Table::findType(std::string varName){
    symValue s=this->find(varName);
    return s.getType();
}

void* Symbol_Table::findValue(std::string varName){
    symValue s=this->find(varName);
    return s.getValue();
}

