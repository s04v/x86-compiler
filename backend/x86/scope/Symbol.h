#pragma once
#include <string>



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
    int sizeType;
    SymbolType type;
    int offset; // offset on stack

    Symbol() {}


    Symbol(string n, int s, SymbolType t, int o) : name(n), sizeType(s), type(t), offset(o) {}
};
}
