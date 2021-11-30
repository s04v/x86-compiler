#pragma once 

struct SizeType_t {
    enum Type {     
        BOOL,
        U8,
        I8,
        U16,
        I16,
        U32,
        I32,
        STRING_T,
        VOID
    };
};

typedef SizeType_t::Type SizeType;
