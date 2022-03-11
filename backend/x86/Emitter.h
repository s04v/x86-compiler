#pragma once

#include <string>
#include "Reg.h"
#include "AsmValue.h"
#include "SizeType.h"

using namespace std;

namespace x86{

#define DEF_INST_OP1(name) \
    string name(AsmValue* v);

#define DEF_INST_OP2(name) \
    string name(AsmValue* v1, AsmValue* v2);

#define DEF_INST_OP3(name) \
    string name(AsmValue* v1, AsmValue* v2, AsmValue* v3);

#define DEF_INST(name) \
    string name();

#define DEF_INST_REG(name) \
    string name##_reg(int src);

#define DEF_INST_IMM(name) \
    string name##_imm(int val);

#define DEF_INST_STR(name) \
    string name##_str(string label);

#define DEF_INST_MEM(name) \
    string name##_mem(int src, int offset, SizeType size);

#define DEF_INST_REG_REG(name) \
    string name##_reg_reg(int dest, int src);

#define DEF_INST_REG_STR(name) \
    string name##_reg_str(int dest, string label);

#define DEF_INST_REG_IMM(name) \
    string name##_reg_imm(int dest, int val);

#define DEF_INST_REG_MEM(name) \
    string name##_reg_mem(int dest, int src, int offset, SizeType size);

#define DEF_INST_MEM_REG(name) \
    string name##_mem_reg(int dest, int offset, SizeType size, int src);

#define DEF_INST_MEM_STR(name) \
    string name##_mem_str(int dest, int offset, SizeType size, string label);

#define DEF_INST_MEM_IMM(name) \
    string name##_mem_imm(int dest, int offset, SizeType size, int val);

#define DEF_INST_REG_REG_IMM(name) \
    string name##_reg_reg_imm(int dest,int src, int val);

#define DEF_INST_REG_MEM_IMM(name) \
    string imul_reg_mem_imm(int dest,int src, int offset, SizeType size, int val);


class Emitter {
public: 
    Register reg;

    string emit(char* fmt, ...); 

    DEF_INST_OP2(mov)
    DEF_INST_REG_REG(mov)
    DEF_INST_REG_STR(mov)
    DEF_INST_REG_IMM(mov)
    DEF_INST_REG_MEM(mov)
    DEF_INST_MEM_REG(mov)
    DEF_INST_MEM_STR(mov)
    DEF_INST_MEM_IMM(mov)

    DEF_INST_OP2(add)
    DEF_INST_REG_REG(add)
    DEF_INST_REG_STR(add)
    DEF_INST_REG_IMM(add)
    DEF_INST_REG_MEM(add)
    DEF_INST_MEM_REG(add)
    DEF_INST_MEM_STR(add)
    DEF_INST_MEM_IMM(add)

    DEF_INST_OP2(sub)
    DEF_INST_REG_REG(sub)
    DEF_INST_REG_STR(sub)
    DEF_INST_REG_IMM(sub)
    DEF_INST_REG_MEM(sub)
    DEF_INST_MEM_REG(sub)
    DEF_INST_MEM_STR(sub)
    DEF_INST_MEM_IMM(sub)

    DEF_INST_OP2(imul)
    DEF_INST_OP3(imul)

    DEF_INST_REG_STR(imul) // idle
    DEF_INST_REG_IMM(imul) // idle
    DEF_INST_MEM_REG(imul) // idle
    DEF_INST_MEM_STR(imul) // idle
    DEF_INST_MEM_IMM(imul) // idle

    DEF_INST_REG_REG(imul)
    DEF_INST_REG_MEM(imul)
    DEF_INST_REG_REG_IMM(imul)
    DEF_INST_REG_MEM_IMM(imul)

    DEF_INST_REG(idiv)
    DEF_INST_MEM(idiv)
    
// TODO
    DEF_INST_REG(inot)
    DEF_INST_MEM(inot)

    DEF_INST_OP1(push)
    DEF_INST_REG(push)
    DEF_INST_STR(push)
    DEF_INST_IMM(push)
    DEF_INST_MEM(push)

    DEF_INST(leave)
    DEF_INST(ret)


    DEF_INST_OP2(cmp)
    DEF_INST_REG_REG(cmp)
    DEF_INST_REG_STR(cmp) // idle
    DEF_INST_REG_IMM(cmp)
    DEF_INST_REG_MEM(cmp)
    DEF_INST_MEM_REG(cmp)
    DEF_INST_MEM_STR(cmp) // idle
    DEF_INST_MEM_IMM(cmp)

    DEF_INST_OP1(jne)
    DEF_INST_STR(jne) // Label
    DEF_INST_REG(jne) // idle
    DEF_INST_IMM(jne) // idle
    DEF_INST_MEM(jne) // idle

    DEF_INST_OP1(je)
    DEF_INST_STR(je) // Label
    DEF_INST_REG(je) // idle
    DEF_INST_IMM(je) // idle
    DEF_INST_MEM(je) // idle

    DEF_INST_OP1(jle)
    DEF_INST_STR(jle) // Label
    DEF_INST_REG(jle) // idle
    DEF_INST_IMM(jle) // idle
    DEF_INST_MEM(jle) // idle

    DEF_INST_OP1(jl)
    DEF_INST_STR(jl) // Label
    DEF_INST_REG(jl) // idle
    DEF_INST_IMM(jl) // idle
    DEF_INST_MEM(jl) // idle

    DEF_INST_OP1(jge)
    DEF_INST_STR(jge) // Label
    DEF_INST_REG(jge) // idle
    DEF_INST_IMM(jge) // idle
    DEF_INST_MEM(jge) // idle

    DEF_INST_OP1(jg)
    DEF_INST_STR(jg) // Label
    DEF_INST_REG(jg) // idle
    DEF_INST_IMM(jg) // idle
    DEF_INST_MEM(jg) // idle

    DEF_INST_OP1(jmp)
    DEF_INST_STR(jmp) // Label
    DEF_INST_REG(jmp) // idle
    DEF_INST_IMM(jmp) // idle
    DEF_INST_MEM(jmp) // idle

    const char* funcStart();
    const char* funcEnd();


    const char* getMemSize(SizeType s);
    const char* getReg(int r, SizeType s);
};
}
