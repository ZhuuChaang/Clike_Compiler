#ifndef _AST_H_
#define _AST_H_

#include <string>
#include <vector>
#include <map>
#include "LLVMlibs.h"
#include "CodeGen.h"



//all AST node structures definition
class Node;
class Program; //the starting node of AST

class Expression; 

class Statement;
class StmtList;
    class DeclareStmt;
    class ControlStmt;
    class CallStmt;

class Function;
class FunctionList;

class Variable;
class VariableList;

class DefinedTypes;
class DefinedTypeList;



class Node{
public:
    Node();
    ~Node();
    virtual llvm::Value * CodeGen(CodeGenerator &Gen)=0;
    virtual int DrawNode()=0;
};

class Program: public Node{
    FunctionList* Functions;
    VariableList* GlobalVars;
    DefinedTypeList* GlobalDefines;
    
    
};

class Function: public Node{

};

#endif