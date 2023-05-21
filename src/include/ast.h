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

class Type;
    class Builtintype;
    class Structtype;
    class Uniontype;
    class Enumtype;
    class Definedtype;
    class Pointertype;
    class Arraytype;


class Basestmt;
    

class Expr;
    class Constant;
    class Fundeclare;


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

//types
class Type:public Node{
    bool is_static=false;
    bool is_const =false;
public:
    Type(){}
    ~Type(){}
    
    void set_static(){
        is_static=true;
    }

    void set_const(){
        is_const=true;
    }

    virtual llvm::Value * CodeGen(CodeGenerator &Gen)=0;
    virtual int DrawNode()=0;
};

class Builtintype: public Type{
public:
    enum Btinty{
        undefined_ty,
        int_ty,
        short_ty,
        long_ty,
        void_ty,
        char_ty,
        double_ty,
        float_ty
    } Ty;

    Builtintype(){Ty=undefined_ty;}
    ~Builtintype(){}

    void set_int(){Ty=int_ty;}
    void set_short(){Ty=short_ty;}
    void set_long(){Ty=long_ty;}
    void set_void(){Ty=void_ty;}
    void set_char(){Ty=char_ty;}
    void set_double(){Ty=double_ty;}
    void set_float(){Ty=float_ty;}

    virtual llvm::Value * CodeGen(CodeGenerator &Gen)=0;
    virtual int DrawNode()=0;
};

class Structtype: public Type{
    std::string structName;
    std::map<Type*,std::string> structMembers;
public:
    
};

class Uniontype: public Type{
    std::string structName;
    std::map<Type*,std::string> unionMembers;
public:
};

class Enumtype: public Type{
    std::map<std::string,int> enumMembers;
};

class Definedtype: public Type{
    std::string deftypeName;
    Type* type;
public:
    Definedtype(std::string name){deftypeName=name;type=NULL;}
    Definedtype(std::string name, Type* t): deftypeName(name), type(t){}
    ~Definedtype(){}

	llvm::Value * CodeGen(CodeGenerator &Gen);
	int DrawNode();
};


//
class Globalstmt:public Node{
    std::vector<Basestmt*> stmtlist;
public: 
    Globalstmt(){
        std::vector<Basestmt*> t;
        stmtlist=t;
    }
    ~Globalstmt(){}
    void Addstmt(Basestmt* s){
        stmtlist.push_back(s);
    }

	llvm::Value * CodeGen(CodeGenerator &Gen);
	int DrawNode();
};

//base class for all stmt
class Basestmt: public Node{
public:
    Basestmt(){}
    ~Basestmt(){}
    
    virtual llvm::Value * CodeGen(CodeGenerator &Gen)=0;
    virtual int DrawNode()=0;
};



class Fundeclare: public Basestmt{
    std::string  Funname;
public:

};





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