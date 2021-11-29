#pragma once 

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

    virtual ~Stmt() = default;
};