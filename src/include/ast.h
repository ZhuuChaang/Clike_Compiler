#ifndef _AST_H_
#define _AST_H_

#include <string>
#include <vector>
#include <memory>
#include <map>
#include "LLVMlibs.h"
#include "CodeGen.h"

enum Csttype{
     cstty_int,
     cstty_real,
     cstty_str,
     cstty_char,
     cstty_bool
};
//all AST node structures definition
class Node;
class Program; //the starting node of AST

class Globalstmt;

class Expr;

class Constant;


class Node{
public:
    Node(void);
    ~Node(void);
    virtual llvm::Value * CodeGen(CodeGenerator &Gen)=0;
    virtual int DrawNode()=0;
};

class Program: public Node{
public:
    Globalstmt * StmtHead;
    Program(Globalstmt* head) :StmtHead(head) {}
	~Program(void) {}

	llvm::Value * CodeGen(CodeGenerator &Gen);
	int DrawNode();
};


class Globalstmt:public Node{
    Globalstmt* Next;
public: 
    Globalstmt(){}
    ~Globalstmt(){}
    Globalstmt* getNext(){
        return Next;
    }
};

// class Decl : public Node {
// public:
//     Decl(void) {}
//     ~Decl(void) {}
//     virtual llvm::Value* CodeGen(CodeGenerator& __Generator) = 0;
//     virtual std::string astJson() = 0;
// };



// start your part at here
class Expr : public Node{
public:
    bool RHvalue; //is this expression only can be used as a right hand side value
                  // optional you can decide whether to use or not

    Expr(){}
    ~Expr(){}

// leave them be for now
    virtual llvm::Value * CodeGenPTR(CodeGenerator &Gen)=0;
	virtual llvm::Value * CodeGen(CodeGenerator &Gen)=0;
	virtual int DrawNode();  

};

class Constant: public Expr{
public:
    int _integer;
    double _double;
    std::string _str;
    char c;
    bool b;

    enum Csttype type;

    Constant(int v, enum Csttype t) : _integer(v), type(t){}
    Constant(double v, enum Csttype t) : _double(v), type(t){}
    Constant(std::string v, enum Csttype t) : _str(v), type(t){}
    Constant(char v, enum Csttype t) : c(v), type(t){}
    Constant(bool v, enum Csttype t) : b(v), type(t){}
    ~Constant(){}
    enum Csttype getType(){
        return type;
    }

	llvm::Value * CodeGen(CodeGenerator &Gen);
	int DrawNode();  
};





#endif