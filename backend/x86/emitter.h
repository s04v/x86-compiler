#pragma once

#include <string>
#include "reg.h"

using namespace std;
namespace x86{

#define DEF_INST(name) \
    string name();

#define DEF_INST_REG(name) \
    string name##_reg(int src);

#define DEF_INST_IMM(name) \
    string name##_imm(int val);

#define DEF_INST_MEM(name) \
    string name##_mem(int src, int offset = 0);

#define DEF_INST_REG_REG(name) \
    string name##_reg_reg(int dest, int src);

#define DEF_INST_REG_IMM(name) \
    string name##_reg_imm(int dest, int val);

#define DEF_INST_REG_MEM(name) \
    string name##_reg_mem(int dest, int src, int offset = 0);

#define DEF_INST_MEM_REG(name) \
    string name##_mem_reg(int dest, int src, int offset = 0);

#define DEF_INST_MEM_IMM(name) \
    string name##_mem_imm(int dest, int val, int offset = 0);

#define DEF_INST_REG_REG_IMM(name) \
    string name##_reg_reg_imm(int dest,int src, int val);

#define DEF_INST_REG_MEM_IMM(name) \
    string imul_reg_mem_imm(int dest,int src, int val, int offset = 0);


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
    DEF_INST_REG(not)
    DEF_INST_MEM(not)

    DEF_INST_REG(push)

    DEF_INST(leave)
    DEF_INST(ret)
};
}