#ifndef _AST_H_
#define _AST_H_

#include "LLVMlibs.h"
#include "CodeGen.h"

class Node;
class Program; //the starting node of AST

class Expression; 

class Statement;



//all AST node structures



class Node{
public:
    Node();
    ~Node();
    virtual llvm::Value * CodeGen(CodeGenerator &Gen)=0;
};

class Program: public Node{

};

#endif