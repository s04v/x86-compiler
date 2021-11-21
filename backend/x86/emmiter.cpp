#include <string>
#include <iostream>
#include <stdarg.h>
#include "emmiter.h"
#include "reg.h"

using namespace std;

string Emmiter::emit(char* fmt, ...)
{
    char buf[64];

    va_list args;
    va_start(args, fmt);
    vsprintf(buf, fmt, args);
    va_end(args);
    string ret(buf);

    return ret;
} 

string Emmiter::mov_reg_reg(int dest, int src) 
{   
    return emit( "mov %s, %s\n", reg.getName(dest), reg.getName(src));
}

string Emmiter::mov_reg_imm(int dest, int val) 
{
    return emit("mov %s, %d\n", reg.getName(dest), val);
}

string Emmiter::mov_reg_mem(int dest, int src) 
{
    return emit("mov %s, [%s]\n", reg.getName(dest), reg.getName(src));
}

string Emmiter::mov_mem_reg(int dest, int src) 
{
    return emit("mov [%s], %s\n", reg.getName(dest), reg.getName(src));
}

string Emmiter::mov_mem_imm(int dest, int val) 
{
    return emit("mov [%s], %d\n", reg.getName(dest), val);
}

string Emmiter::add_reg_reg(int dest, int src)
{
    return emit( "add %s, %s\n", reg.getName(dest), reg.getName(src));
}

string Emmiter::add_reg_imm(int dest, int val)
{
    return emit("add %s, %d\n", reg.getName(dest), val);
}

string Emmiter::add_reg_mem(int dest, int src)
{
    return emit("add %s, [%s]\n", reg.getName(dest), reg.getName(src));
}

string Emmiter::add_mem_reg(int dest, int src)
{
    return emit("add [%s], %s\n", reg.getName(dest), reg.getName(src));
}

string Emmiter::add_mem_imm(int dest, int val)
{
    return emit("add [%s], %d\n", reg.getName(dest), val);
}

string Emmiter::sub_reg_reg(int dest, int src)
{
    return emit("sub %s, %s\n", reg.getName(dest), reg.getName(src));
}

string Emmiter::sub_reg_imm(int dest, int val)
{
    return emit("sub %s, %d\n", reg.getName(dest), val);
}

string Emmiter::sub_reg_mem(int dest, int src)
{
    return emit("sub %s, [%s]\n", reg.getName(dest), reg.getName(src));
}

string Emmiter::sub_mem_reg(int dest, int src)
{
    return emit("sub [%s], %s\n", reg.getName(dest), reg.getName(src));
}

string Emmiter::sub_mem_imm(int dest, int val)
{
    return emit("sub [%s], %d\n", reg.getName(dest), val);
}

string Emmiter::imul_reg_reg(int dest,int src)
{
    return emit("imul %s, %s\n", reg.getName(dest), reg.getName(src));
}

string Emmiter::imul_reg_mem(int dest,int src)
{
    return emit("imul %s, [%s]\n", reg.getName(dest), reg.getName(src));
}

string Emmiter::imul_reg_reg_imm(int dest,int src, int val)
{
    return emit("imul %s, %s, %d\n", reg.getName(dest), reg.getName(src), val);
}

string Emmiter::imul_reg_mem_imm(int dest,int src, int val)
{
    return emit("imul %s, [%s], %s\n", reg.getName(dest), reg.getName(src), val);
}

string Emmiter::push_reg(int src)
{
    return emit("imul %s\n", reg.getName(src));
}

string Emmiter::leave()
{
    return emit("leave");
}

string Emmiter::ret()
{
    return emit("ret");
}