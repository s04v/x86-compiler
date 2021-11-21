#pragma once

#include <string>
#include "reg.h"

using namespace std;

class Emmiter {
public: 
    Register reg;

    string emit(char* fmt, ...); 

    string mov_reg_reg(int dest, int src);
    string mov_reg_imm(int dest, int val);
    string mov_reg_mem(int dest, int src);
    string mov_mem_reg(int dest, int src);
    string mov_mem_imm(int dest, int val);

    string add_reg_reg(int dest, int src);
    string add_reg_imm(int dest, int val);
    string add_reg_mem(int dest, int src);
    string add_mem_reg(int dest, int src);
    string add_mem_imm(int dest, int val);
    
    string sub_reg_reg(int dest, int src);
    string sub_reg_imm(int dest, int val);
    string sub_reg_mem(int dest, int src);
    string sub_mem_reg(int dest, int src);
    string sub_mem_imm(int dest, int val);
    
    string imul_reg_reg(int dest,int src);
    string imul_reg_mem(int dest,int src);
    string imul_reg_reg_imm(int dest,int src, int val);
    string imul_reg_mem_imm(int dest,int src, int val);

    string push_reg(int src);
    string leave();
    string ret();



};