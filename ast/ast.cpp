#include "ast.h"

char* ASTNode::toString() { return "Node"; }
char* Program::toString() { return "Program"; }
char* FuncDef::toString() { return "FuncDef"; }
FuncDef::FuncDef(int t) { type=t;}
FuncDef::FuncDef() {}
char* VarDef::toString() { return "VarDef"; }
VarDef::VarDef(int t) { type=t;}
VarDef::VarDef() {}