#pragma once
#include <string>
#include "../../../frontend/Ast.h"


using namespace std;

namespace x86 {

struct SType_t {
    enum Type {
        VAR,
        FUNC
    };
};

typedef SType_t::Type SymbolType;

class Symbol {
public:
    string name;
    SizeType sizeType;
    SymbolType type;


    Symbol() {}


    Symbol(string n, SizeType s, SymbolType t) : name(n), sizeType(s), type(t) {}
};
}
