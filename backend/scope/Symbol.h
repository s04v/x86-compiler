#pragma once
#include <string>
#include "../SizeType.h"


using namespace std;

namespace Backend {

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
    SymbolType type; // TODO: delete type
    int offset; // offset on stack

    Symbol() {}

    Symbol(string n, SizeType s, SymbolType t, int o) : name(n), sizeType(s), type(t), offset(o) {}
};
}
