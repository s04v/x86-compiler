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
    string imul_reg_mem_imm(int dest,int src, int offset, int val);


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

    //DEF_INST_OP2(imul)
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

    const char* funcStart();
    const char* funcEnd();


    const char* getMemSize(SizeType s);
    const char* getReg(int r, SizeType s);
};
}
