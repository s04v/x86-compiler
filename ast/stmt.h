#pragma once 

struct Stmt_t {
    enum Type {
        EXPR,
        VAR_ASSIGN,
        VAR_DEF,
        IF
    }
};

typedef Stmt_t::Type StmtType;

class Stmt {
public:
    StmtType stmtType;

    virtual ~Stmt() = default;
}