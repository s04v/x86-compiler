#pragma once
#include <string>
#include <vector>
#include "../backend/TypeSystem.h"
#include "../backend/Compiler.h"
#include "../backend/AsmValue.h"
#include "../backend/SizeType.h"

using namespace std;

struct Stmt_t {
    enum Type {
        EXPR,
        ASSIGN,
        VAR_DEF,
        FUNC_DEF,
        IF,
        FOR,
        RETURN
    };
};

typedef Stmt_t::Type StmtType;

class Stmt {
public:
    StmtType stmtType;
    unsigned int line;

    Stmt() {}
    virtual Backend::AsmValue* gen(Backend::Compiler& compiler) = 0;
    virtual ~Stmt() = default;
};

class ExprOp;

class If : public Stmt {
public:
    ExprOp* condition;
    vector<Stmt*>* stmts;

    If(ExprOp* c, vector<Stmt*>* s ) : condition(c), stmts(s) {}
    virtual Backend::AsmValue* gen(Backend::Compiler& compiler) override {  compiler.gen(*this); }
};

class For : public Stmt {
public:
    VarDef* init;
    ExprOp* condition;
    ExprOp* expr;
    vector<Stmt*>* stmts;

    For(VarDef* i, ExprOp* c, ExprOp* e, vector<Stmt*>* s) : init(i), condition(c), expr(e), stmts(s) {}
    virtual Backend::AsmValue* gen(Backend::Compiler& compiler) override {  compiler.gen(*this); }

};

class FuncArg {
public:
    string name;
    SizeType type;

    FuncArg(string n, SizeType t) : name(n), type(t) {}
};

class Return : public Stmt {
public:
    ExprOp* value;

    Return(ExprOp* v) : value(v) {}
    virtual Backend::AsmValue* gen(Backend::Compiler& compiler) override { return compiler.gen(*this); }
};

class FuncDef : public Stmt {
public:
    string name;
    SizeType returnType;
    vector<FuncArg*>* args;
    vector<Stmt*>* stmts;

    FuncDef(string n, SizeType r, vector<FuncArg*>* a, vector<Stmt*>* s) : name(n), returnType(r), args(a), stmts(s) {}
    virtual Backend::AsmValue* gen(Backend::Compiler& compiler) override { compiler.gen(*this); }
};

class Operand;

class Assign : public Stmt{
public:
    string left;
    ExprOp* right;

    Assign(string l, ExprOp* r) : left(l),right(r) {}
    virtual Backend::AsmValue* gen(Backend::Compiler& compiler) override { compiler.gen(*this); }
};

class VarDef : public Stmt {
public:
    SizeType sizeType;
    string left;
    ExprOp* right;

    VarDef(SizeType t, string l, ExprOp* r) : sizeType(t), left(l), right(r) {}
    virtual Backend::AsmValue* gen(Backend::Compiler& compiler)  override { compiler.gen(*this); }
};

struct Expr_t{
    enum Type {
        MUL,
        DIV,
        ADD,
        SUB,
        LT,
        GT,
        LTEQ,
        GTEQ,
        EQ,
        NEQ,
        AND,
        OR
    };
};

struct ExprOp_t {
    enum Type {
        OPERAND,
        EXPR
    };
};

typedef ExprOp_t::Type ExprOpType;

class ExprOp : public Stmt{
public:
    ExprOpType type;

    ExprOp() {}
    virtual Backend::AsmValue* gen(Backend::Compiler& compiler) override {}
    virtual SizeType getType(Backend::TypeSystem& typeSystem) = 0;
    virtual ~ExprOp() {}
};


typedef Expr_t::Type ExprType;

class Expr : public ExprOp {
public:
    ExprType exprType;
    ExprOp* left;
    ExprOp* right;

    Expr() {}
    Expr(ExprType t, ExprOp* l, ExprOp* r) : exprType(t), left(l), right(r) {}
    virtual Backend::AsmValue* gen(Backend::Compiler& compiler) override { return compiler.gen(*this); }
    virtual SizeType getType(Backend::TypeSystem& typeSystem) override  { return typeSystem.getType(*this); }
    virtual ~Expr() { }
};

struct OpType_t {
    enum Type {
        NONE,
        CONSTANT,
        ID,
        CALL,
    };
};

typedef OpType_t::Type OpType;

struct Prefix_mod {
    enum Type {
        NONE,
        INC,
        DEC
    };
};

typedef Prefix_mod::Type Prefix;

struct Postfix_mod {
    enum Type {
        NONE,
        INC,
        DEC
    };
};

typedef Postfix_mod::Type Postfix;

class Operand : public ExprOp{
public:
    OpType opType;
    Prefix prefix;
    Postfix postfix;

    Operand () {}
    virtual Backend::AsmValue* gen(Backend::Compiler& compiler) override { return {};  }
    virtual SizeType getType(Backend::TypeSystem& typeSystem)  { return {}; }
    virtual ~Operand() = default;
};

struct ConstType_t {
    enum Type {
        NUMBER,
        STRING,
        CHAR
    };
};

typedef ConstType_t::Type ConstType;

class Constant : public Operand {
public:
    ConstType type;
    string val;

    Constant() {}
    Constant(ConstType t, std::string v) : type(t), val(v) {
        if(t == ConstType::STRING)
            val = val.substr(1, val.size() - 2);
    }

    virtual Backend::AsmValue* gen(Backend::Compiler& compiler) override { return compiler.gen(*this); }
    virtual SizeType getType(Backend::TypeSystem& typeSystem) override { return typeSystem.getType(*this); }
};

class Id : public Operand {
public:
    string name;

    Id(string n) : name(n) {}
    virtual Backend::AsmValue* gen(Backend::Compiler& compiler) override { return compiler.gen(*this); }
    virtual SizeType getType(Backend::TypeSystem& typeSystem) override { return typeSystem.getType(*this); }
};


class Call : public Operand {
public:
    string name;
    vector<ExprOp*>* args;

    Call(string n, vector<ExprOp*>* a) : name(n), args(a) {}
    virtual Backend::AsmValue* gen(Backend::Compiler& compiler) override { return compiler.gen(*this); }
    virtual SizeType getType(Backend::TypeSystem& typeSystem) override { return typeSystem.getType(*this); }
};
