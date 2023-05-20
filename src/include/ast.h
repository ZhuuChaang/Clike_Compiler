#ifndef _AST_H_
#define _AST_H_

#include <string>
#include <vector>
#include <memory>
#include <map>
#include "LLVMlibs.h"
#include "CodeGen.h"



//all AST node structures definition
class Node;
class Program; //the starting node of AST

class Decl;
    using Decls = std::vector<std::unique_ptr<Decl>>;

class FuncDef;
    class FuncFParam;
    using FuncFParams = std::vector<std::unique_ptr<FuncFParam>>;

class Stmt;
    class VarDecl;
    class VarDef;
    using VarDefs = std::vector<std::unique_ptr<VarDef>>;
        class InitVal;
    class AssignStmt;
    class IfStmt;
    class WhileStmt;
    class BreakStmt;
    class ContinueStmt;
    class ReturnStmt;

class Block;
using Stmts = std::vector<std::unique_ptr<Stmt>>;

class Expr;
    class UnaryExpr;
    class FuncCall;
    using FuncPParams = std::vector<std::unique_ptr<Expr>>;
    class MulExpr;
    class AddExpr;
    class RelExpr;
    class EqExpr;
    class AndExpr;
    class OrExpr;
    
// class Function;
// class FunctionList;

// class Variable;
// class VariableList;

// class DefinedTypes;
// class DefinedTypeList;
// class Node{
// public:
//     Node(void);
//     ~Node(void);
//     virtual llvm::Value * CodeGen(CodeGenerator &Gen)=0;
//     virtual int DrawNode()=0;
// };

// class Program: public Node{
// public:
//     std::unique_ptr<Node> decl;
//     Program(std::unique_ptr<Node> decl) :decl(decl) {}
// 	~Program(void) {}
// 	llvm::Value* CodeGen(CodeGenerator& __Generator);
// 	std::string astJson();
// };

// class Decl : public Node {
// public:
//     Decl(void) {}
//     ~Decl(void) {}
//     virtual llvm::Value* CodeGen(CodeGenerator& __Generator) = 0;
//     virtual std::string astJson() = 0;
// };

// class Stmt : public Decl {
// public:
//     Stmt(void) {}
//     ~Stmt(void) {}
//     virtual llvm::Value* CodeGen(CodeGenerator& __Generator) = 0;
//     virtual std::string astJson() = 0;
// };

// class VarDecl : public Stmt {
// public:
//     //The variable type
//     std::unique_ptr<Node>  var_type;
//     //The variable list
//     std::unique_ptr<VarDefs> var_defs;
//     VarDecl(std::unique_ptr<Node> var_type, std::unique_ptr<VarDefs> var_defs) :
//         var_type(var_type), var_defs(var_defs) {}
//     ~VarDecl(void) {}
//     llvm::Value* CodeGen(CodeGenerator& __Generator);
//     std::string astJson();
// };

// class VarType :public Node {
// public:
//     //bool is_const;temporary not support constants
//     llvm::Type* LLVMType;
// 	VarType(void) : is_const(false), LLVMType(NULL) {}
// 	~VarType(void) {}
//     // void SetConst(void) {
// 	// 	this->_isConst = true;
// 	// }
// };

// class VarDef :public Node {
// public:
//     std::unique_ptr<std::string> ident;
//     std::unique_ptr<Node> expr;//array initial to be implement
//     VarDef(std::unique_ptr<std::string> ident) :
//         ident(ident), expr(NULL) {}
//     VarDef(std::unique_ptr<std::string> ident, std::unique_ptr<Node> expr) :
//         ident(ident), expr(expr) {}
// 	~VarDef(void) {}
// };

// class FuncDecl :public Decl {
// public:
//     std::unique_ptr<Node> return_type;
//     std::unique_ptr<std::string> ident;
//     std::unique_ptr<FuncFParams> func_params;
//     std::unique_ptr<Node> block;
//     FuncDecl(std::unique_ptr<Node> return_type, std::unique_ptr<std::string> ident,
//     std::unique_ptr<FuncFParams> func_params, std::unique_ptr<Node> block):
//         return_type(return_type), ident(ident), func_params(func_params), block(block) {}
//     //prototype declare
//     FuncDecl(std::unique_ptr<Node> return_type, std::unique_ptr<std::string> ident,
//     std::unique_ptr<FuncFParams> func_params):
//         return_type(return_type), ident(ident), func_params(func_params), block(NULL) {}
//     ~FuncDecl(void) {}
// };

// class FuncFParam :public Node {
// public:
//     std::unique_ptr<Node> var_type;
//     std::unique_ptr<std::string> ident;
//     FuncFParam(std::unique_ptr<Node> var_type, std::unique_ptr<std::string> ident):
//         var_type(var_type), ident(ident) {}
//     ~FuncFParam(void) {}
// };

// class Block :public Stmt {
// public:
//     std::unique_ptr<Stmts> stmts;
//     Block(std::unique_ptr<Stmts> stmts): stmts(stmts) {}
//     ~Block(void);
// };

// class AssignStmt :public Stmt {
// public:
//     //if array implemented, need to change to left value 
//     std::unique_ptr<std::string> ident;
//     std::unique_ptr<Node> expr;
//     AssignStmt(std::unique_ptr<std::string> ident, std::unique_ptr<Node> Expr) :
//         ident(ident), expr(expr) {}
//     ~AssignStmt(void) {}
// }
// class IfStmt :public Stmt {
// public:
//     std::unique_ptr<Node> expr;
//     std::unique_ptr<Node> if_stmt;
//     std::unique_ptr<Node> else_stmt;
//     AssignStmt(std::unique_ptr<Node> expr, std::unique_ptr<Node> if_stmt, std::unique_ptr<Node> else_stmt) :
//         expr(expr), if_stmt(if_stmt), else_stmt(else_stmt) {}
//     AssignStmt(std::unique_ptr<Node> expr, std::unique_ptr<Node> if_stmt) :
//         expr(expr), if_stmt(if_stmt), else_stmt(NULL) {}
//     ~AssignStmt(void) {}
// }
// class WhileStmt :public Stmt{
// public:
//     std::unique_ptr<Node> expr;
//     std::unique_ptr<Node> stmt;
//     WhileStmt(std::unique_ptr<Node> expr, std::unique_ptr<Node> stmt) :
//         expr(expr), stmt(stmt) {}
//     ~WhileStmt(void) {}
// }
// class BreakStmt :public Stmt{
// public:
//     BreakStmt(void) {}
//     ~BreakStmt(void) {}
// }
// class ContinueStmt :public Stmt{
// public:
//     ContinueStmt(void) {}
//     ~ContinueStmt(void) {}
// }
// class ReturnStmt :public Stmt{
// public:
//     std::unique_ptr<Node> expr;
//     ReturnStmt(std::unique_ptr<Node> expr) :expr(expr) {}
//     ~ReturnStmt(void) {}
// }
// class Expr :public Stmt{
// public:
//     Expr(void) {}
//     ~Expr(void) {}
// }
// //temporary not implemented
// class UnaryExpr;
// class FuncCall;
// class MulExpr;
// class AddExpr;
// class RelExpr;
// class EqExpr;
// class AndExpr;
// class OrExpr;

#endif