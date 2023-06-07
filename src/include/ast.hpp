#ifndef _AST_H_
#define _AST_H_

#include <string>
#include <vector>
#include <memory>
#include <map>
#include "LLVMlibs.hpp"
#include "CodeGen.hpp"
#include <iostream>

enum Csttype{
     cstty_int,
     cstty_real,
     cstty_str,
     cstty_char,
     cstty_bool
};

typedef std::vector<std::string> IdentifierList;

//all AST node structures definition
class Node;
    class Program; //the starting node of AST
    class Globalstmt;
    class Stmt;

class Type;
    class Builtintype;
    class Structtype;
    class Uniontype;
    class SUmemdec;
        typedef std::vector<SUmemdec*> SUdecllist;
    class Enumtype;
    class Enum;
    class Definedtype;
    class Pointertype;
    class Arraytype;

class Basestmt;
    class Fundeclare;
    class Fielddeclare;
    class funArg;
        typedef std::vector<funArg*> funArgList;
    class InitID;
        typedef std::vector<InitID*> InitIDList;
    class Vardefine;
    class TypeDefine;
    class Scope;
    class Exprstmt;
    class Returnstmt;
    class Breakstmt;
    class Continuestmt;
    class Ifflow;
    class Elseifflow;
    class Elseflow;
    class Forflow;
    class Whileflow;
    class Dowhileflow;
    class Switchflow;
    class Case;
    typedef std::vector<Case*> Caselist;



class Expr;
    class Constant;
    class Variable;
    class FuncCall;
        typedef std::vector<Expr*> CallArgList;
    class BinopExpr;
    //class Binop;
    class UnaopExpr;
    //class Unaop;
    class SufopExpr;
    //class Sufop;
    class SizeofExpr;
    class SizeofType;
    class TernaryCondition;
    class TypeCast;
    class Subscript;
    class MemAccessPtr;
    class MemAccessObj;

class Node{
public:
    Node(void) {}
    ~Node(void) {}
    // virtual llvm::Value * CodeGen(CodeGenerator &Gen)=0;
    // virtual int DrawNode(int depth)=0;
    virtual llvm::Value * CodeGen(CodeGenerator &Gen) {return nullptr;}
    virtual int DrawNode(int depth) {return 0;}
};

class Program: public Node{
public:
    Globalstmt * Stmtlist;
    Program(Globalstmt* l) :Stmtlist(l) {}
	~Program(void) {}

	llvm::Value * CodeGen(CodeGenerator &Gen) {}
	int DrawNode();
};


//base class for all stmt
class Basestmt: public Node{
public:
    Basestmt(){}
    ~Basestmt(){}
    
    virtual llvm::Value * CodeGen(CodeGenerator &Gen) {}
    virtual int DrawNode(int depth) {return 0;}
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

    virtual llvm::Value * CodeGen(CodeGenerator &Gen) {}
    virtual int DrawNode() {}
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

    virtual llvm::Value * CodeGen(CodeGenerator &Gen) {}
    virtual int DrawNode();
};

class SUmemdec{
public:
    Type* type;
    std::vector<std::string>* id;

    SUmemdec(Type* t, std::vector<std::string>* i):type(t),id(i){}
    ~SUmemdec(){}
    int DrawNode(int depth);
};

class Structtype: public Type{
    std::string structName;
    std::map<std::string,Type*> structMembers;
public:
    Structtype(std::string s,std::vector<SUmemdec*> *list): structName(s){
        int size=list->size();
        for(int i=0;i<size;i++){
            Type* t=(*list)[i]->type;
            int num=(*list)[i]->id->size();
            for(int j=0;j<num;j++){
                structMembers.insert(std::pair<std::string,Type*>((*(*list)[i]->id)[j],t));
            }
        }
    }
    ~Structtype(){}

    llvm::Value * CodeGen(CodeGenerator &Gen) {}
    int DrawNode() {}
};

class Uniontype: public Type{
    std::string UnionName;
    std::map<std::string,Type*> unionMembers;
    llvm::Type* maxtype=NULL;
public:
    Uniontype(std::string s,std::vector<SUmemdec*> *list): UnionName(s){
        int size=list->size();
        for(int i=0;i<size;i++){
            Type* t=(*list)[i]->type;
            int num=(*list)[i]->id->size();
            for(int j=0;j<num;j++){
                unionMembers.insert(std::pair<std::string,Type*>((*(*list)[i]->id)[j],t));
            }
        }
    }

    llvm::Value * CodeGen(CodeGenerator &Gen) {}
    int DrawNode() {}
};



class Enum{
public:
    std::string name;
    int number=-1;

    Enum(std::string n):name(n){}
    Enum(std::string n, int num):name(n),number(num){}
    ~Enum(){}

};


class Enumtype: public Type{
    std::string enumname;
    std::map<std::string,int> enumMembers;
    
public:
    Enumtype(std::string s,std::vector<Enum*> List):enumname(s){
        int present=0;
        for(int i=0;i<List.size();i++){
            if(List[i]->number!=-1){
                present=List[i]->number;
            }
            enumMembers.insert(std::pair<std::string,int>(List[i]->name,present++));
        }
    }

    ~Enumtype(){}

    llvm::Value * CodeGen(CodeGenerator &Gen){}
    int DrawNode(){}
};



typedef std::vector<Enum*> Enumlist;

class Definedtype: public Type{
    std::string deftypeName;
    Type* type;
public:
    Definedtype(std::string name){deftypeName=name;type=NULL;}
    Definedtype(Type* t, std::string name): deftypeName(name), type(t){}
    ~Definedtype(){}

	llvm::Value * CodeGen(CodeGenerator &Gen){}
	int DrawNode(){}
};

class Pointertype:public Type{
    Type* basetype;

public:
    Pointertype(Type* t): basetype(t){}
    ~Pointertype(){};

	llvm::Value * CodeGen(CodeGenerator &Gen){}
	int DrawNode(){}
};


class Arraytype: public Type{
    Type* basetype;
    int size;
public:
    Arraytype(Type* t, int s): basetype(t), size(s) {}
    ~Arraytype(){}

	llvm::Value * CodeGen(CodeGenerator &Gen){}
	int DrawNode(){}       
};





/////////////////////////////////////////////////////////////////////


//
class Globalstmt:public Node{
    std::vector<Basestmt*> stmtlist;
public: 
    Globalstmt(){}
    ~Globalstmt(){}
    void Addstmt(Basestmt* s){
        stmtlist.push_back(s);
    }

	llvm::Value * CodeGen(CodeGenerator &Gen){}
	int DrawNode(int depth);
};



class funArg{
public:
    std::string argName;
    Type* type;

    funArg(Type* t, std::string s): argName(s), type(t){}
    ~funArg(){}
};

class Fundeclare: public Basestmt{
    Type* retType;
    std::string  Funname;
    std::map<std::string,Type*> Arglist;
public:
    Fundeclare(Type* t,std::string s, funArgList* l):retType(t),Funname(s){
        int size=l->size();
        for(int i=0;i<size;i++){
            funArg* a=(*l)[i];
            Arglist.insert(std::pair<std::string,Type*>(a->argName,a->type));
        }
    }
    ~Fundeclare(){}

    llvm::Value * CodeGen(CodeGenerator &Gen);
    int DrawNode(){}
};

class Fundefine: public Basestmt{
    Type* retType;
    std::string  Funname;
    std::map<std::string,Type*> Arglist;
    Scope* Funbody;
public:
    Fundefine(Type* t,std::string s, funArgList* l, Scope* b):retType(t),Funname(s),Funbody(b){
        int size=l->size();
        for(int i=0;i<size;i++){
            funArg* a=(*l)[i];
            Arglist.insert(std::pair<std::string,Type*>(a->argName,a->type));
        }
    }
    ~Fundefine(){}

    llvm::Value * CodeGen(CodeGenerator &Gen) {}
	int DrawNode();
};

class Fielddeclare: public Basestmt{
    Type* type;
public:
    Fielddeclare(Type* t):type(t){}
    ~Fielddeclare(){}

    llvm::Value * CodeGen(CodeGenerator &Gen){}
    int DrawNode(int depth);
};


class InitID{
    std::string VarName;
    Expr* eInit=NULL;
    bool is_initiallized=false;
public:
    InitID(std::string s):VarName(s){}
    InitID(std::string s,Expr* e):VarName(s),eInit(e){is_initiallized=true;}
    ~InitID(){}
    int DrawNode(int depth);
    bool testinit(){return is_initiallized;}
};

class Vardefine: public Basestmt{
    Type* type;
    InitIDList* list;

public:
    Vardefine(Type* t, InitIDList* l): type(t), list(l){}
    ~Vardefine(){}
    llvm::Value * CodeGen(CodeGenerator &Gen);
    int DrawNode(int depth);
};

//////////////////////////////////////////////////////////////////

class Stmt: public Node{
    std::vector<Basestmt*> stmtlist;
public:
    Stmt(){}
    ~Stmt(){}

    void Addstmt(Basestmt* s){
        stmtlist.push_back(s);
    }
    virtual int DrawNode(int depth);
};


class Scope: public Basestmt{
    Stmt* Scopestmt; 
    bool isfun=false;   

public:
    Scope(Stmt* s):Scopestmt(s){}
    ~Scope(){}

    void setfun(){isfun=true;}

    virtual llvm::Value * CodeGen(CodeGenerator &Gen) {}
    virtual int DrawNode(int depth);
};

class TypeDefine: public Basestmt{
public:
    Definedtype* defined_type;
    TypeDefine(Definedtype* defined_type): defined_type(defined_type) {}
    ~TypeDefine() {}
    virtual int DrawNode(int depth);
};

class Exprstmt: public Basestmt{
    Expr* expr;

public: 
    Exprstmt(Expr* e):expr(e){}
    ~Exprstmt(){}
    virtual int DrawNode(int depth);
};

class Returnstmt: public Basestmt{
    Expr* ret=NULL;
    bool withvalue=false;
public:
    Returnstmt(){ret=NULL; withvalue=false;}
    Returnstmt(Expr* e): ret(e) {withvalue=true;}
    ~Returnstmt(){}
    virtual int DrawNode(int depth);
};

class Breakstmt: public Basestmt{
public:
    Breakstmt(){}
    ~Breakstmt(){}
    virtual int DrawNode(int depth);
};

class Continuestmt: public Basestmt{
public:
    Continuestmt(){}
    ~Continuestmt(){}
    virtual int DrawNode(int depth);
};

class Ifflow: public Basestmt{
    bool has_body;

    Expr* condition;
    Scope* ifbody;

    Elseifflow* Elseif;
    Elseflow* Else;

public:
    Ifflow(Expr* e):condition(e),ifbody(NULL){
        has_body=false;
    }

    Ifflow(Expr* e,Scope* b, Elseifflow* elf, Elseflow* el):
        condition(e), ifbody(b), Elseif(elf), Else(el)
    {
        has_body=true;
    }

    ~Ifflow(){}
    virtual int DrawNode(int depth);
};

class Elseifflow: public Basestmt{
    std::vector<Expr*> conditions;
    std::vector<Scope*> bodies;

public:
    Elseifflow(){}
    ~Elseifflow(){}

    void Addelseif(Expr* e, Scope* b){
        conditions.push_back(e);
        bodies.push_back(b);
    }
    virtual int DrawNode(int depth);
};

class Elseflow: public Basestmt{
    bool has_body;
    Scope* Elsebody;

public:
    Elseflow():has_body(false), Elsebody(NULL){}
    Elseflow(Scope* b):has_body(true), Elsebody(b){}
    ~Elseflow(){}

    bool test_body(){return has_body;}
    virtual int DrawNode(int depth);
};


class Forflow: public Basestmt{
    Expr* init;
    Expr* limit;
    Expr* step;
    Scope* Forbody;
    bool has_body;

public:
    Forflow(Expr* i,Expr* l,Expr* s):init(i),limit(l),step(s){Forbody=NULL;has_body=false;}
    Forflow(Expr* i,Expr* l,Expr* s, Scope* b):init(i),limit(l),step(s){Forbody=b;has_body=true;}
    ~Forflow(){}

    bool test_body(){return has_body;}
    virtual int DrawNode(int depth);  
};

class Whileflow: public Basestmt{
    Expr* limit;
    Scope* whilebody;
    bool has_body;

public:
    Whileflow(Expr* l):limit(l),whilebody(NULL),has_body(false){}
    Whileflow(Expr* l, Scope* s): limit(l),whilebody(s),has_body(true){}
    ~Whileflow(){}

    bool test_body(){return has_body;}
    virtual int DrawNode(int depth); 
};

class Dowhileflow: public Basestmt{
    Expr* limit;
    Scope* whilebody;
 
public:
    Dowhileflow(Expr* l, Scope* w):limit(l),whilebody(w){}
    ~Dowhileflow(){}
    virtual int DrawNode(int depth); 
};


class Switchflow: public Basestmt{
    Expr* switchExpr;
    Caselist* list;
public:
    Switchflow(Expr* e,Caselist* l):switchExpr(e),list(l){}
    ~Switchflow(){}
    virtual int DrawNode(int depth);
};

class Case: public Node{
    bool has_break;
    bool is_default;
    Expr* caseExpr;
    Stmt* casebody;

public:
    Case(Expr* e, Stmt* b):caseExpr(e),casebody(b){has_break=false;is_default=false;}
    Case(Stmt* b):caseExpr(NULL),casebody(b){has_break=false;is_default=false;}

    ~Case(){}

    void set_break(){has_break=true;}
    void set_default(){is_default=true;}
    bool test_break(){return has_break;}
    bool test_default(){return is_default;}
    virtual int DrawNode(int depth); 
};
//////////////////////////////////////////////////////////////////////////////////////
// start your part at here


class Expr : public Node{
public:
    bool RHvalue; //is this expression only can be used as a right hand side value
                  // optional you can decide whether to use or not

    Expr(){}
    ~Expr(){}
// leave them be for now
    virtual llvm::Value * CodeGenPTR(CodeGenerator &Gen) {}
	virtual llvm::Value * CodeGen(CodeGenerator &Gen) {}
	virtual int DrawNode(int depth) {}
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

	// llvm::Value * CodeGen(CodeGenerator &Gen);
	virtual int DrawNode(int depth);  
};


class Variable: public Expr{
public:
    std::string _name;
    Variable(std::string name): _name(name) {}
    ~Variable() {}
    virtual int DrawNode(int depth);  
};

class FuncCall: public Expr{
public:
    std::string _func_name;
    CallArgList* _arg_list;
    FuncCall(std::string name, CallArgList* args) : _func_name(name), _arg_list(args) {}
    ~FuncCall() {}
    virtual int DrawNode(int depth);  
};

class BinopExpr: public Expr{
public:
    int _op;
    Expr* _lhs;
    Expr* _rhs;
    BinopExpr(int op, Expr* lhs, Expr* rhs) : _op(op), _lhs(lhs), _rhs(rhs) {}
    ~BinopExpr() {}
    virtual int DrawNode(int depth);
};

class UnaopExpr: public Expr{
public:
    int _op;
    Expr* _operand;
    UnaopExpr(int op, Expr* operand): _op(op), _operand(operand) {}
    ~UnaopExpr() {}
    virtual int DrawNode(int depth);
};

class SufopExpr: public Expr{
public:
    int _op;
    Expr* _operand;
    SufopExpr(int op, Expr* operand): _op(op), _operand(operand) {}
    ~SufopExpr() {}
    virtual int DrawNode(int depth);
};

class SizeofExpr: public Expr{
public:
    Expr* _expr;
    SizeofExpr(Expr* expr): _expr(expr) {}
    ~SizeofExpr() {}
    virtual int DrawNode(int depth);
};

class SizeofType: public Expr{
public:
    Type* _type;
    SizeofType(Type* type): _type(type) {}
    ~SizeofType() {}
    virtual int DrawNode(int depth);
};

class TernaryCondition: public Expr{
public:
    Expr* _condition;
    Expr* _if_then;
    Expr* _else_then;
    TernaryCondition(Expr* condition, Expr* if_then, Expr* else_then)
        : _condition(condition), _if_then(if_then), _else_then(else_then) {}
    ~TernaryCondition() {}
    virtual int DrawNode(int depth);
};
class TypeCast: public Expr{
public:
    Type* _type;
    Expr* _expr;
    TypeCast(Type* type, Expr* expr): _type(type), _expr(expr) {}
    ~TypeCast() {}
    virtual int DrawNode(int depth);
};

class Subscript: public Expr{
public:
    Expr* _array;
    Expr* _index;
    Subscript(Expr* array, Expr* index): _array(array), _index(index) {}
    ~Subscript() {}
    virtual int DrawNode(int depth);
};

class MemAccessPtr: public Expr{
public:
    Expr* _struct_ptr;
    std::string _member;
    MemAccessPtr(Expr* struct_ptr, std::string member)
        : _struct_ptr(struct_ptr), _member(member) {}
    ~MemAccessPtr() {}
    virtual int DrawNode(int depth);
};

class MemAccessObj: public Expr{
public:
    Expr* _struct;
    std::string _member;
    MemAccessObj(Expr* struct_name, std::string member)
        : _struct(struct_name), _member(member) {}
    ~MemAccessObj() {}
    virtual int DrawNode(int depth);
};



#endif