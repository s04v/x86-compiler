#include <string>
#include <iostream>
#include <stdarg.h>
#include "Emitter.h"
#include "Reg.h"
#include "../utils/int2str.h"
#include "AsmValue.h"
#include "SizeType.h"

using namespace std;

namespace x86 {

#define toString(x) int2str(x).c_str()

#define R 0x1
#define M 0x2
#define I 0x3
#define S 0x4 // string label

#define RR 0x11
#define RM 0x12
#define RI 0x13
#define RS 0x14
#define MR 0x21
#define MI 0x23
#define MS 0x24

#define RRI 0x113
#define RMI 0x123

#define INST_OP1(name) \
    string Emitter::name(AsmValue* v) \
    { \
        int jump = v->type; \
        switch (jump) { \
            case R: \
                return name##_reg(v->index); \
            case M: \
                return name##_mem(v->index, v->offset, v->memSize); \
            case I: \
                return name##_imm(v->imm); \
            case S: \
                return name##_str(v->val); \
            default: \
                break; \
        }\
        return "invalid instruction"; \
    }

#define INST_OP2(name) \
    string Emitter::name(AsmValue* v1, AsmValue* v2) \
    { \
        int jump = 0; \
        jump = v1->type << 4; \
        jump += v2->type; \
        switch (jump) { \
            case RR: \
                return name##_reg_reg(v1->index, v2->index); \
            case RM: \
                return name##_reg_mem(v1->index, v2->index, v2->offset, v2->memSize); \
            case RI: \
                return name##_reg_imm(v1->index, v2->imm); \
            case MR: \
                return name##_mem_reg(v1->index, v1->offset, v1->memSize, v2->index); \
            case MI: \
                return name##_mem_imm(v1->index, v1->offset, v1->memSize, v2->imm); \
            case RS: \
                return name##_reg_str(v1->index, v2->val); \
            case MS: \
                return name##_mem_str(v1->index, v1->offset, v1->memSize, v2->val); \
            default: \
                break; \
        }\
        return "invalid instruction"; \
    }

#define INST_OP3(name) \
    string Emitter::name(AsmValue* v1, AsmValue* v2, AsmValue* v3) \
    { \
        int jump = 0; \
        jump = v1->type << 8; \
        jump += v2->type << 4; \
        jump += v3->type; \
        switch (jump) { \
            case RRI: \
                return name##_reg_reg_imm(v1->index, v2->index, v3->imm); \
            case RMI: \
                return name##_reg_mem_imm(v1->index, v2->index, v2->offset, v2->memSize, v3->imm); \
            default: \
                break; \
        }\
        return "invalid instruction"; \
    }

#define INST(name) \
    string Emitter::name() { \
        return emit(#name "\n"); \
    }

#define INST_REG(name) \
    string Emitter::name##_reg(int src) { \
        return emit(#name" %s\n", reg.getName(src)); \
    }

#define INST_STR(name) \
    string Emitter::name##_str(string label) { \
        return emit(#name" %s\n", label.c_str()); \
    }

#define INST_MEM(name) \
    string Emitter::name##_mem(int src, int offset, SizeType size) { \
        return emit(#name " %s [%s%s]\n", getMemSize(size),reg.getName(src), toString(offset)); \
    }

#define INST_IMM(name) \
    string Emitter::name##_imm(int val) { \
        return emit(#name " %d\n", val); \
    }

#define INST_REG_REG(name) \
    string Emitter::name##_reg_reg(int dest, int src) { \
        return emit( #name " %s, %s\n", reg.getName(dest), reg.getName(src)); \
    }

#define INST_REG_STR(name) \
    string Emitter::name##_reg_str(int dest, string label) { \
        return emit( #name " %s, %s\n", reg.getName(dest), label.c_str()); \
    }

#define INST_REG_IMM(name) \
    string Emitter::name##_reg_imm(int dest, int val) { \
        return emit( #name " %s, %d\n", reg.getName(dest), val); \
    }

#define INST_REG_MEM(name) \
    string Emitter::name##_reg_mem(int dest, int src, int offset, SizeType size) { \
        return offset != 0 ? emit(#name " %s, %s [%s%s]\n", reg.getName(dest), getMemSize(size), reg.getName(src), toString(offset)) \
                           : emit(#name " %s, %s [%s]\n", reg.getName(dest), getMemSize(size), reg.getName(src)); \
    }

#define INST_MEM_REG(name) \
    string Emitter::name##_mem_reg(int dest, int offset, SizeType size, int src) { \
        const char* r = getReg(src, size); \
        return offset != 0 ? emit(#name " %s [%s%s], %s\n", getMemSize(size), reg.getName(dest), toString(offset), r) \
                           : emit(#name " %s [%s], %s\n", getMemSize(size), reg.getName(dest), r); \
    }

#define INST_MEM_STR(name) \
    string Emitter::name##_mem_str(int dest, int offset, SizeType size, string label) { \
        return offset != 0 ? emit(#name " %s [%s%s], %s\n", getMemSize(size), reg.getName(dest), toString(offset), label.c_str()) \
                           : emit(#name " %s [%s], %s\n", getMemSize(size), reg.getName(dest), label.c_str()); \
    }

#define INST_MEM_IMM(name) \
    string Emitter::name##_mem_imm(int dest, int offset, SizeType size, int val) { \
        return offset != 0 ? emit(#name " %s [%s%s], %d\n", getMemSize(size), reg.getName(dest), toString(offset), val) \
                           : emit(#name " %s [%s], %d\n", getMemSize(size), reg.getName(dest), val); \
    }

#define INST_REG_REG_IMM(name) \
    string Emitter::name##_reg_reg_imm(int dest,int src, int val) { \
        return emit(#name" %s, %s, %d\n", reg.getName(dest), reg.getName(src), val); \
    }

#define INST_REG_MEM_IMM(name) \
    string Emitter::name##_reg_mem_imm(int dest, int src, int offset, SizeType size, int val) { \
        return offset != 0 ? emit(#name " %s, %s [%s%s], %d\n", reg.getName(dest),  getMemSize(size), reg.getName(src), toString(offset), val) \
                           : emit(#name " %s, %s [%s], %d\n", reg.getName(dest),  getMemSize(size), reg.getName(src), val); \
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

INST_OP2(mov)
INST_REG_REG(mov)
INST_REG_STR(mov)
INST_REG_IMM(mov)
INST_REG_MEM(mov)
INST_MEM_REG(mov)
INST_MEM_STR(mov)
INST_MEM_IMM(mov)

INST_OP2(add)
INST_REG_REG(add)
INST_REG_STR(add)
INST_REG_IMM(add)
INST_REG_MEM(add)
INST_MEM_REG(add)
INST_MEM_STR(add)
INST_MEM_IMM(add)

INST_OP2(sub)
INST_REG_REG(sub)
INST_REG_STR(sub)
INST_REG_IMM(sub)
INST_REG_MEM(sub)
INST_MEM_REG(sub)
INST_MEM_STR(sub)
INST_MEM_IMM(sub)

INST_OP2(imul)
INST_OP3(imul)

INST_REG_STR(imul) // idle
INST_REG_IMM(imul) // idle
INST_MEM_REG(imul) // idle
INST_MEM_STR(imul) // idle
INST_MEM_IMM(imul) // idle

INST_REG_REG(imul)
INST_REG_MEM(imul)
INST_REG_REG_IMM(imul)
INST_REG_MEM_IMM(imul)

INST_OP1(idiv)
INST_REG(idiv)
INST_MEM(idiv)
INST_STR(idiv) // idle
INST_IMM(idiv) // idle

INST_OP1(push)
INST_REG(push)
INST_STR(push)
INST_IMM(push)
INST_MEM(push)

INST(leave)
INST(ret)

INST_OP2(cmp)
INST_REG_REG(cmp)
INST_REG_STR(cmp) // idle
INST_REG_IMM(cmp)
INST_REG_MEM(cmp)
INST_MEM_REG(cmp)
INST_MEM_STR(cmp) // idle
INST_MEM_IMM(cmp)

INST_OP1(jne)
INST_STR(jne) // Lable
INST_REG(jne) // idle
INST_IMM(jne) // idle
INST_MEM(jne) // idle


INST_OP1(je)
INST_STR(je) // Lable
INST_REG(je) // idle
INST_IMM(je) // idle
INST_MEM(je) // idle

INST_OP1(jle)
INST_STR(jle) // Label
INST_REG(jle) // idle
INST_IMM(jle) // idle
INST_MEM(jle) // idle

INST_OP1(jl)
INST_STR(jl) // Label
INST_REG(jl) // idle
INST_IMM(jl) // idle
INST_MEM(jl) // idle

INST_OP1(jge)
INST_STR(jge) // Label
INST_REG(jge) // idle
INST_IMM(jge) // idle
INST_MEM(jge) // idle

INST_OP1(jg)
INST_STR(jg) // Label
INST_REG(jg) // idle
INST_IMM(jg) // idle
INST_MEM(jg) // idle

INST_OP1(jmp)
INST_STR(jmp) // Label
INST_REG(jmp) // idle
INST_IMM(jmp) // idle
INST_MEM(jmp) // idle

const char* Emitter::funcStart()
{
    return "push ebp\n"
            "mov ebp, esp\n";
}

const char* Emitter::funcEnd()
{
    return "nop\n"
            "leave\n"
            "ret\n\n";
}

const char* Emitter::getMemSize(SizeType s)
{
    switch(s)
    {
        case SizeType::BOOL:
        case SizeType::U8:
        case SizeType::I8:
            return "BYTE";
        case SizeType::U16:
        case SizeType::I16:
            return "WORD";
        case SizeType::U32:
        case SizeType::I32:
        case SizeType::STRING_T:
            return "DWORD";
        default:
            return "invalid ptr";
    }
}

const char* Emitter::getReg(int r, SizeType s)
{
    switch(s)
    {
        case SizeType::BOOL:
        case SizeType::U8:
        case SizeType::I8:
            return reg.getName(r + 3);
        case SizeType::U16:
        case SizeType::I16:
            return reg.getName(r + 1);
        case SizeType::U32:
        case SizeType::I32:
            return reg.getName(r);
        default:
            return "invalid reg";
    }
}
}
