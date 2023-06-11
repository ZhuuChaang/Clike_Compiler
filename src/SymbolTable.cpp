#include "SymbolTable.hpp"

void Symbol_Table::newValue(std::string varName,ValueTypes t,void* v){
    symValue s(t,v,this->scopelevel);
    this->newValueSym(varName,s);
}

void Symbol_Table::newValueSym(std::string varName, symValue s){
    if(Table.find(varName)==Table.end()){
        std::vector<symValue> Vstack;
        Table.insert(std::pair<std::string,std::vector<symValue>>(varName,Vstack));
        Table[varName].push_back(s);
    }else{
        int end=this->Table[varName].size()-1;
        int toplevel=this->Table[varName][end].getmark();
        if(toplevel<s.getmark()){
            Table[varName].push_back(s);
        }else{
            std::string errormsg="redefine of some identifier: ";
            errormsg=errormsg.append(varName);
            errormsg=errormsg.append("\n");
            std::__throw_logic_error(errormsg.data());
        }
    }
}

void Symbol_Table::enterScope(){
    this->scopelevel++;
}

void Symbol_Table::leaveScope(){
    std::vector<std::string> localVs;
    for(auto& it:Table){
        int end=it.second.size()-1;
        for(int i=end;i>=0;i--){
            if(it.second[i].getmark()<=this->scopelevel){
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

bool Symbol_Table::findhave(std::string varName){
    if(this->Table.find(varName)==Table.end()){
        return false;
    }else{
        return true;
    }
}