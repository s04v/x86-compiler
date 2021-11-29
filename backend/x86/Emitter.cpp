#include <string>
#include <iostream>
#include <stdarg.h>
#include "Emitter.h"
#include "Reg.h"
#include "../../utils/int2str.h"

using namespace std;

namespace x86 {

#define toString(x) int2str(x).c_str()

#define INST(name) \
    string Emitter::name() { \
        return emit(#name "\n"); \
    } 

#define INST_REG(name) \
    string Emitter::name##_reg(int src) { \
        return emit(#name" %s\n", reg.getName(src)); \
    }

#define INST_MEM(name) \
    string Emitter::name##_mem(int src, int offset) { \
        return emit(#name " [%s%s]\n", reg.getName(src), toString(offset)); \
    }

#define INST_IMM(name) \
    string Emitter::name##_imm(int val) { \
        return emit(#name " %d\n", val); \
    }

#define INST_REG_REG(name) \
    string Emitter::name##_reg_reg(int dest, int src) { \
        return emit( #name " %s, %s\n", reg.getName(dest), reg.getName(src)); \
    }

#define INST_REG_IMM(name) \
    string Emitter::name##_reg_imm(int dest, int val) { \
        return emit( #name " %s, %d\n", reg.getName(dest), val); \
    }

#define INST_REG_MEM(name) \
    string Emitter::name##_reg_mem(int dest, int src, int offset) { \
        return offset != 0 ? emit(#name " %s, [%s%s]\n", reg.getName(dest), reg.getName(src), toString(offset)) \
                           : emit(#name " %s, [%s]\n", reg.getName(dest), reg.getName(src)); \
    }

#define INST_MEM_REG(name) \
    string Emitter::name##_mem_reg(int dest, int src, int offset) { \
        return offset != 0 ? emit(#name " [%s%s], %s\n", reg.getName(dest), reg.getName(src)) \
                           : emit(#name " [%s], %s\n", reg.getName(dest), reg.getName(src), toString(offset)); \
    }
    
#define INST_MEM_IMM(name) \
    string Emitter::name##_mem_imm(int dest, int val, int offset) { \
        return offset != 0 ? emit(#name " [%s%s], %d\n", reg.getName(dest), val, toString(offset)) \
                           : emit(#name " [%s], %d\n", reg.getName(dest), val); \
    }

#define INST_REG_REG_IMM(name) \
    string Emitter::name##_reg_reg_imm(int dest,int src, int val) { \
        return emit(#name" %s, %s, %d\n", reg.getName(dest), reg.getName(src), val); \
    }

#define INST_REG_MEM_IMM(name) \
    string Emitter::name##_reg_mem_imm(int dest,int src, int val, int offset) { \
        return offset != 0 ? emit(#name " %s, [%s%s], %s\n", reg.getName(dest), reg.getName(src), val, toString(offset)) \
                           : emit(#name " %s, [%s], %s\n", reg.getName(dest), reg.getName(src), val); \
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
