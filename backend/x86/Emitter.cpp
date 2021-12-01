#include <string>
#include <iostream>
#include <stdarg.h>
#include "Emitter.h"
#include "Reg.h"
#include "../../utils/int2str.h"
#include "AsmOperand.h"


using namespace std;

namespace x86 {

#define toString(x) int2str(x).c_str()

#define INST(inst) \
    string Emitter::inst() { \
        return emit(#inst "\n"); \
    }

#define INST_REG(inst) \
    string Emitter::inst(AsmRegister r) { \
        return emit(#inst" %s\n", r.getName()); \
    }

#define INST_MEM(inst) \
    string Emitter::inst(AsmMemory m) { \
        return emit(#inst " [%s%s]\n", m.getReg(), m.getOffset()); \
    }

#define INST_IMM(inst) \
    string Emitter::inst(AsmConstant c) { \
        return emit(#inst " %s\n", c.getVal()); \
    }

#define INST_REG_REG(inst) \
    string Emitter::inst(AsmRegister dest, AsmRegister src) { \
        return emit( #inst " %s, %s\n", dest.getName(), src.getName()); \
    }

#define INST_REG_IMM(inst) \
    string Emitter::inst(AsmRegister dest, AsmConstant c) { \
        return emit( #inst " %s, %s\n", dest.getName(), c.getVal()); \
    }

#define INST_REG_MEM(inst) \
    string Emitter::inst(AsmRegister dest, AsmMemory src) { \
        return src.getOffset() != "" ? emit(#inst " %s, [%s%s]\n", dest.getName(), src.getReg(), src.getOffset()) \
                           : emit(#inst " %s, [%s]\n", dest.getName(), src.getReg()); \
    }

#define INST_MEM_REG(inst) \
    string Emitter::inst(AsmMemory dest, AsmRegister src) { \
        return dest.getOffset() != "" ? emit(#inst " [%s%s], %s\n", dest.getReg(), dest.getOffset(),  src.getName()) \
                           : emit(#inst " [%s], %s\n", dest.getReg(), src.getName()); \
    }

#define INST_MEM_IMM(inst) \
    string Emitter::inst(AsmMemory dest, AsmConstant c) { \
        return dest.getOffset() != "" ? emit(#inst " [%s%s], %s\n", dest.getReg(), dest.getOffset(), c.getVal()) \
                           : emit(#inst " [%s], %s\n", dest.getReg(), c.getVal()); \
    }

#define INST_REG_REG_IMM(inst) \
    string Emitter::inst(AsmRegister dest, AsmRegister src, AsmConstant c) { \
        return emit(#inst" %s, %s, %s\n", dest.getName(), src.getName(), c.getVal()); \
    }

#define INST_REG_MEM_IMM(inst) \
    string Emitter::inst(AsmRegister dest, AsmMemory src, AsmConstant c) { \
        return src.getOffset()  != "" ? emit(#inst " %s, [%s%s], %s\n", dest.getName(), src.getReg(), src.getOffset(), c.getVal()) \
                           : emit(#inst " %s, [%s], %s\n", dest.getName(), src.getReg(), c.getVal()); \
    }

string Emitter::emit(char* fmt, ...)
{
    char buf[64];

    va_list args;
    va_start(args, fmt);
    vsprintf(buf, fmt, args);
    va_end(args);
    string ret(buf);

    return ret;
}

INST_REG_REG(mov)
INST_REG_IMM(mov)
INST_REG_MEM(mov)
INST_MEM_REG(mov)
INST_MEM_IMM(mov)

INST_REG_REG(add)
INST_REG_IMM(add)
INST_REG_MEM(add)
INST_MEM_REG(add)
INST_MEM_IMM(add)

INST_REG_REG(sub)
INST_REG_IMM(sub)
INST_REG_MEM(sub)
INST_MEM_REG(sub)
INST_MEM_IMM(sub)

INST_REG_REG(imul)
INST_REG_MEM(imul)
INST_REG_REG_IMM(imul)
INST_REG_MEM_IMM(imul)

INST_REG(idiv)
INST_MEM(idiv)

INST_REG(push)
INST(leave)
INST(ret)

}
