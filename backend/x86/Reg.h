#pragma once 

#include <string>

using namespace std;

namespace x86{

enum Reg {
    EAX, AX, AH, AL,
    EBX, BX, BH, BL,
    ECX, CX, CH, CL,
    EDX, DX, DH, DL,
    ESP, SP, SPL,
    EBP, BP, BPL
};

    

class Register {
private:
    string name[22] = {
        "eax", "ax", "ah", "al",
        "ebx", "bx", "bh", "bl",
        "ecx", "cx", "ch", "cl",
        "edx", "dx", "dh", "dl",
        "esp", "sp", "spl",
        "ebp", "bp", "sbl",
    };
 
    bool reg[22]  = {
        1,  1,  1,  1,
//      eax ax  ah  al
        1,  1,  1,  1,
//      ebx bx  bh  bl
        1,  1,  1,  1,
//      ecx cx  ch  cl
        1,  1,  1,  1,
//      edx dx  dh  dl
        1,  1,  1,
//      esp sp  spl
        1,  1,  1,
//      ebp bx  bph
    };

public:
    bool isAvailable(int r);

    int alloc8l();
    int alloc8h();
    int alloc16();
    int alloc32();

    string get16From(int r);
    string get8hFrom(int r);
    string get8lFrom(int r);

    const char* getName(int r);
    void free(int r);
};
}
