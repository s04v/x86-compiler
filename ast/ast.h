
#include <string>
#include <vector>

using namespace std;

enum NodeType {
    Var_t,
    Func_t
};

class ASTNode {
public:
    int type;
    virtual char* toString();
};

class Program : public ASTNode {
public:
    vector<ASTNode*> stmts;
    char* toString();

};

class FuncDef : public ASTNode {
public:
    FuncDef(int);
    FuncDef();
    char* toString();
};

class VarDef : public ASTNode {
public:
    VarDef(int);
    VarDef();
    char* toString();
};

