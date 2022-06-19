#include "TypeSystem.h"
#include "SizeType.h"
#include "../frontend/Ast.h"
#include "../utils/error.h"

namespace Backend {

TypeSystem::TypeSystem() {}

SizeType TypeSystem::getType(Constant& constant)
{
    if( constant.type == ConstType::NUMBER)
        return SizeType::NUMBER;
    return SizeType::STRING_T;
}

SizeType TypeSystem::getType(Id& id)
{
    Symbol symbol = currentScope->table.get(id.name);
    return symbol.sizeType;
}

SizeType TypeSystem::getType(Call& call)
{
    Function function = currentScope->funcTable.get(call.name);
    return function.returnType;
}

SizeType TypeSystem::getType(Expr& expr)
{
    SizeType left = expr.left->getType(*this);
    SizeType right = expr.right->getType(*this);

    if(!possibleCast[left][right])
    {
       incorretType(expr.line);
    }

    return left;
}

SizeType TypeSystem::getType(ExprOp& exprOp)
{
    return SizeType::U32;
}

bool TypeSystem::isCorrect(SizeType left, SizeType right)
{
    return possibleCast[left][right];
}

bool TypeSystem::isCorrect(SizeType type, Constant& constant)
{
    return possibleCast[type][getType(constant)];
}

bool TypeSystem::isCorrect(SizeType type, Id& id)
{
    return possibleCast[type][getType(id)];
}

bool TypeSystem::isCorrect(SizeType type, Call& call)
{
    return possibleCast[type][getType(call)];
}

bool TypeSystem::isCorrect(SizeType type, Expr& expr)
{
    return possibleCast[type][getType(expr)];
}

bool TypeSystem::isCorrect(SizeType type, ExprOp& exprOp)
{
    return possibleCast[type][getType(exprOp)];
}

char* TypeSystem::getTypeName(SizeType type)
{
    switch(type)
    {
    case SizeType::BOOL:
        return "bool";
        break;
    case SizeType::I8:
        return "i8";
        break;
    case SizeType::I16:
        return "i16";
        break;
    case SizeType::I32:
        return "i32";
        break;
    case SizeType::U8:
        return "u8";
        break;
    case SizeType::U16:
        return "u16";
        break;
    case SizeType::U32:
        return "u32";
        break;
    case SizeType::NUMBER:
        return "number";
        break;
    case SizeType::STRING_T:
        return "string";
        break;
    case SizeType::VOID:
        return "void";
        break;
    default:
        return "invalid type name";
    }
}

}
