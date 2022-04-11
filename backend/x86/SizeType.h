#pragma once
struct SizeType_t {
    enum Type {
        BOOL,
        U8,
        I8,
        U16,
        I16,
        U32, //5
        I32,
        STRING_T,
        NUMBER,
        VOID
    };
};

typedef SizeType_t::Type SizeType;
