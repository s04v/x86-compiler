#include <string>
#include "FunctionSignature.h"
#include "SizeType.h"

using namespace std;

namespace x86 {

void FunctionSignature::setArgType(SizeType type)
{
    switch(type) {
        case SizeType::BOOL:
            sign += "_b";
            break;
        case SizeType::I8:
            sign += "_i8";
            break;
        case SizeType::U8:
            sign += "_u8";
            break;
        case SizeType::I16:
            sign += "_i16";
            break;
        case SizeType::U16:
            sign += "_u16";
            break;
        case SizeType::I32:
            sign += "_i32";
            break;
        case SizeType::U32:
            sign += "_u32";
            break;
        default:
            break;
    }
}

void FunctionSignature::setReturnType(SizeType type)
{
    switch(type) {
        case SizeType::BOOL:
            sign += ":b";
            break;
        case SizeType::I8:
            sign += ":i8";
            break;
        case SizeType::U8:
            sign += ":u8";
            break;
        case SizeType::I16:
            sign += ":i16";
            break;
        case SizeType::U16:
            sign += ":u16";
            break;
        case SizeType::I32:
            sign += ":i32";
            break;
        case SizeType::U32:
            sign += ":u32";
            break;
        case SizeType::VOID:
            sign += ":v";
            break;
        default:
            break;
    }
}

string FunctionSignature::get()
{
    return sign;
}

bool FunctionSignature::equals(FunctionSignature func)
{
    return sign.compare(func.get()) == 0    ;
}
}

