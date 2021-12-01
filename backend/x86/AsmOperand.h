#pragma once

#include <string>

using namespace std;

namespace x86 {



class AsmConstant{
public:
    string val;
    const char* getVal() { return val.c_str(); }

};

class AsmMemory{
public:
    string reg;
    string offset = "";
    const char* getReg() { return reg.c_str(); }
    const char* getOffset() { return offset.c_str(); }



};

class AsmRegister{
public:
    string name;
    const char* getName() { return name.c_str();}
};

}
