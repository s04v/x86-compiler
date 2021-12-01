#pragma once

#include <string>
#include "Reg.h"
#include "AsmOperand.h"

using namespace std;

namespace x86{

#define DEF_INST(inst) \
    string inst();

#define DEF_INST_REG(inst) \
    string inst(AsmRegister r);

#define DEF_INST_MEM(inst) \
    string inst(AsmMemory m);

#define DEF_INST_IMM(inst) \
    string inst(AsmConstant c);

#define DEF_INST_REG_REG(inst) \
    string inst(AsmRegister dest, AsmRegister src);

#define DEF_INST_REG_IMM(inst) \
    string inst(AsmRegister dest, AsmConstant c);

#define DEF_INST_REG_MEM(inst) \
    string inst(AsmRegister dest, AsmMemory src);

#define DEF_INST_MEM_REG(inst) \
    string inst(AsmMemory dest, AsmRegister src);

#define DEF_INST_MEM_IMM(inst) \
    string inst(AsmMemory dest, AsmConstant c);

#define DEF_INST_REG_REG_IMM(inst) \
    string inst(AsmRegister dest, AsmRegister src, AsmConstant c);

#define DEF_INST_REG_MEM_IMM(inst) \
    string inst(AsmRegister dest, AsmMemory src, AsmConstant c);


class Emitter {
public: 
    Register reg;

    string emit(char* fmt, ...); 

    DEF_INST_REG_REG(mov)
    DEF_INST_REG_IMM(mov)
    DEF_INST_REG_MEM(mov)
    DEF_INST_MEM_REG(mov)
    DEF_INST_MEM_IMM(mov)

    DEF_INST_REG_REG(add)
    DEF_INST_REG_IMM(add)
    DEF_INST_REG_MEM(add)
    DEF_INST_MEM_REG(add)
    DEF_INST_MEM_IMM(add)  
 
    DEF_INST_REG_REG(sub)
    DEF_INST_REG_IMM(sub)
    DEF_INST_REG_MEM(sub)
    DEF_INST_MEM_REG(sub)
    DEF_INST_MEM_IMM(sub)
    
    DEF_INST_REG_REG(imul)
    DEF_INST_REG_MEM(imul)
    DEF_INST_REG_REG_IMM(imul)
    DEF_INST_REG_MEM_IMM(imul)

    DEF_INST_REG(idiv)
    DEF_INST_MEM(idiv)
    
// TODO
    DEF_INST_REG(inot)
    DEF_INST_MEM(inot)

    DEF_INST_REG(push)

    DEF_INST(leave)
    DEF_INST(ret)
};
}
