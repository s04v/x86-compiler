#include <string>
#include <iostream>
#include <stdarg.h>
#include "emitter.h"
#include "reg.h"
#include "../../utils/int2str.h"

using namespace std;

#define toString(x) int2str(x).c_str()

#define INST_REG_REG(name) \
    string Emitter::name##_reg_reg(int dest, int src) { \
        return emit( #name " %s, %s\n", reg.getName(dest), reg.getName(src)); \
    }

#define INST_REG_IMM(name) \
    string Emitter::name##_reg_imm(int dest, int val) { \
        return emit( #name " %s, %d\n", reg.getName(dest), val); \
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
// string Emitter::mov_reg_imm(int dest, int val) 
// {
//     return emit("mov %s, %d\n", reg.getName(dest), val);
// }

string Emitter::mov_reg_mem(int dest, int src, int offset) 
{
    return offset != 0 ? emit("mov %s, [%s%s]\n", reg.getName(dest), reg.getName(src), toString(offset))
                       : emit("mov %s, [%s]\n", reg.getName(dest), reg.getName(src));
}

string Emitter::mov_mem_reg(int dest, int src, int offset) 
{
    return offset != 0 ? emit("mov [%s%s], %s\n", reg.getName(dest), reg.getName(src))
                       : emit("mov [%s], %s\n", reg.getName(dest), reg.getName(src), toString(offset));
}

string Emitter::mov_mem_imm(int dest, int val, int offset) 
{
    return offset != 0 ? emit("mov [%s%s], %d\n", reg.getName(dest), val, toString(offset))
                       : emit("mov [%s], %d\n", reg.getName(dest), val);
}

string Emitter::add_reg_reg(int dest, int src)
{
    return emit( "add %s, %s\n", reg.getName(dest), reg.getName(src));
}

string Emitter::add_reg_imm(int dest, int val)
{
    return emit("add %s, %d\n", reg.getName(dest), val);
}

string Emitter::add_reg_mem(int dest, int src, int offset)
{
    return offset != 0 ? emit("add %s, [%s%s]\n", reg.getName(dest), reg.getName(src), toString(offset))
                       : emit("add %s, [%s]\n", reg.getName(dest), reg.getName(src));
}

string Emitter::add_mem_reg(int dest, int src, int offset)
{
    return offset != 0 ? emit("add [%s%s], %s\n", reg.getName(dest), reg.getName(src), toString(offset))
                       : emit("add [%s], %s\n", reg.getName(dest), reg.getName(src));
}

string Emitter::add_mem_imm(int dest, int val, int offset)
{
    return offset != 0 ? emit("add [%s%s], %d\n", reg.getName(dest), val, toString(offset))
                       : emit("add [%s], %d\n", reg.getName(dest), val);
}

string Emitter::sub_reg_reg(int dest, int src)
{
    return emit("sub %s, %s\n", reg.getName(dest), reg.getName(src));
}

string Emitter::sub_reg_imm(int dest, int val)
{
    return emit("sub %s, %d\n", reg.getName(dest), val);
}

string Emitter::sub_reg_mem(int dest, int src, int offset)
{
    return offset != 0 ? emit("sub %s, [%s%s]\n", reg.getName(dest), reg.getName(src), toString(offset))
                       : emit("sub %s, [%s]\n", reg.getName(dest), reg.getName(src));
}

string Emitter::sub_mem_reg(int dest, int src, int offset)
{
    return offset != 0 ? emit("sub [%s%s], %s\n", reg.getName(dest), reg.getName(src), toString(offset)) 
                       : emit("sub [%s], %s\n", reg.getName(dest), reg.getName(src));
}

string Emitter::sub_mem_imm(int dest, int val, int offset)
{
    return offset != 0 ? emit("sub [%s%s], %d\n", reg.getName(dest), val, toString(offset))
                       : emit("sub [%s], %d\n", reg.getName(dest), val);
}

string Emitter::imul_reg_reg(int dest,int src)
{
    return emit("imul %s, %s\n", reg.getName(dest), reg.getName(src));
}

string Emitter::imul_reg_mem(int dest,int src, int offset)
{
    return offset != 0 ? emit("imul %s, [%s%s]\n", reg.getName(dest), reg.getName(src), toString(offset))
                       : emit("imul %s, [%s]\n", reg.getName(dest), reg.getName(src));
}

string Emitter::imul_reg_reg_imm(int dest,int src, int val)
{
    return emit("imul %s, %s, %d\n", reg.getName(dest), reg.getName(src), val);
}

string Emitter::imul_reg_mem_imm(int dest,int src, int val, int offset)
{
    return offset != 0 ? emit("imul %s, [%s%s], %s\n", reg.getName(dest), reg.getName(src), val, toString(offset))
                       : emit("imul %s, [%s], %s\n", reg.getName(dest), reg.getName(src), val);
}

string Emitter::push_reg(int src)
{
    return emit("imul %s\n", reg.getName(src));
}

string Emitter::idiv_reg(int src)
{
    return emit("cdq\nidiv %s\n", reg.getName(src));
}

string Emitter::idiv_mem(int src, int offset)
{
    return emit("cdq\nidiv [%s]\n", reg.getName(src));
}

string Emitter::leave()
{
    return emit("leave");
}

string Emitter::ret()
{
    return emit("ret");
}