#pragma once
#include <string>
#include <vector>
#include "../backend/x86/Compiler.h"
#include "../backend/x86/AsmValue.h"

using namespace std;



struct SizeType_t {
    enum Type {
        BOOL,
        U8,
        I8,
        U16,
        I16,
        U32,
        I32,
        STRING_T,
        VOID
    };
};

typedef SizeType_t::Type SizeType;


struct Stmt_t {
    enum Type {
        EXPR,
        ASSIGN,
        VAR_DEF,
        FUNC_DEF,
        IF
    };
};

typedef Stmt_t::Type StmtType;


class Stmt {
public:
    StmtType stmtType;

    Stmt() {};

    virtual AsmValue* gen(x86::Compiler& compiler) = 0;
    virtual ~Stmt() = default;
};

class ExprOp;

class If : public Stmt {
public:
    ExprOp* condition;
    vector<Stmt*>* stmts;
    If(ExprOp* c, vector<Stmt*>* s ) : condition(c), stmts(s) {};
    virtual AsmValue* gen(x86::Compiler& compiler) override {};
};

class FuncArg {
public:
    string name;
    SizeType type;

    FuncArg(string n, SizeType t) : name(n), type(t) {};
};

class FuncDef : public Stmt {
public:
    string name;
    SizeType returnType;
    vector<FuncArg*>* args;
    vector<Stmt*>* stmts;

    FuncDef(string n, SizeType r, vector<FuncArg*>* a, vector<Stmt*>* s) : name(n), returnType(r), args(a), stmts(s) {}
    virtual AsmValue* gen(x86::Compiler& compiler) override { compiler.gen(*this); };
};

struct AssignOperation_t {
    enum Type {
        ASSIGN,
        MUL_ASSIGN,
        DIV_ASSIGN,
        MOD_ASSIGN,
        ADD_ASSIGN,
        SUB_ASSIGN,
        AND_ASSIGN,
        OR_ASSIGN
    };
};

typedef AssignOperation_t::Type AssignOperation;

class Operand;

class Assign : public Stmt{
public:
    AssignOperation type;
    Operand* left;
    ExprOp* right;

    Assign(AssignOperation t, Operand* l, ExprOp* r) : type(t), left(l),right(r) {};
    virtual AsmValue* gen(x86::Compiler& compiler) override {};
};

class VarDef : public Stmt {
public:
    SizeType sizeType;
    string left;
    ExprOp* right;

    VarDef();
    VarDef(SizeType t, string l, ExprOp* r) : sizeType(t), left(l), right(r) {} ;
    virtual AsmValue* gen(x86::Compiler& compiler)  override { compiler.gen(*this); };

};

struct Expr_t{
    enum Type {
        MUL,
        DIV,
        MOD,
        ADD,
        SUB,

        LT,
        GT,
        LTEQ,
        GTEQ,
        EQ,
        NEQ,

        AND_AND,
        OR_OR,

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

    ExprOp() {};

    virtual AsmValue* gen(x86::Compiler& compiler) override {};
    virtual ~ExprOp() {};
};


typedef Expr_t::Type ExprType;

class Expr : public ExprOp {
public:
    ExprType exprType;
    ExprOp* left;
    ExprOp* right;

    Expr() {};
    Expr(ExprType t, ExprOp* l, ExprOp* r) : exprType(t), left(l), right(r) {};

    virtual AsmValue* gen(x86::Compiler& compiler) override { return compiler.gen(*this); };

    virtual ~Expr() { };
};

struct OpType_t {
    enum Type {
        NONE,
        CONSTANT,
        ID,
        CALL,
        ARRAY,
        MEMBER_t
    };
};

typedef OpType_t::Type OpType;

struct Prefix_mod {
    enum Type {
        NONE,
        MUL,
        ADD,
        SUB,
        NOT,
        AND,
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
    virtual AsmValue* gen(x86::Compiler& compiler) override { return {};  };
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
    std::string val;

    Constant() {};
    Constant(ConstType t, std::string v) : type(t), val(v) {  };

    virtual AsmValue* gen(x86::Compiler& compiler) override { return compiler.gen(*this); };
};

class Id : public Operand {
public:
    string name;

    Id(string n) : name(n) {};
    virtual AsmValue* gen(x86::Compiler& compiler) override { return compiler.gen(*this); };
};


class Call : public Operand {
public:
    Operand* name; // ID
    vector<ExprOp*>* args;

    Call(Operand* n, vector<ExprOp*>* a) : name(n), args(a) {};
};

