#pragma once

#include <string>

using namespace std;


struct AsmOpType_t {
    enum Type {
        CONSTANT,
        MEMORY,
        REGISTER
    };
};

typedef AsmOpType_t::Type AsmOp;

class AsmValue{
public:
    AsmOp type;

    AsmValue() {}
    AsmValue(AsmOp t) : type(t) {}
    virtual ~AsmValue() = default;
};

class AsmConstant : public AsmValue{
public:
    string val;

    AsmConstant(string v) : AsmValue(AsmOp::CONSTANT), val(v) {}
    const char* getVal() { return val.c_str(); }
};

class AsmMemory : public AsmValue{
public:
    string reg;
    string offset = "";

    AsmMemory() : AsmValue(AsmOp::MEMORY) {}
    const char* getReg() { return reg.c_str(); }
    const char* getOffset() { return offset.c_str(); }
};

class AsmRegister : public AsmValue{
public:
    string name;
    int index;

    AsmRegister() : AsmValue(AsmOp::REGISTER) {}
    const char* getName() { return name.c_str();}

};

