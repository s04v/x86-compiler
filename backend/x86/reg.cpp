#include <string>
#include "reg.h"

using namespace std;

namespace x86 {

int Register::alloc8l() 
{
    for (int i = 3; i < 16; i += 4)
    {
        if(reg[i])
        {
            reg[i] = 0;
            return i;     
        }
    }
}

int Register::alloc8h() 
{
    for (int i = 2; i < 16; i += 4)
    {
        if(reg[i])
        {
            reg[i] = 0;
            return i;     
        }
    }
} 

int Register::alloc16() 
{
    for (int i = 1; i < 16; i += 4)
    {
        if(reg[i])
        {
            reg[i] = 0;
            return i;     
        }
    }
}

int Register::alloc32() 
{
    for (int i = 0; i < 16; i += 4)
    {
        if(reg[i])
        {
            reg[i] = 0;
            return i;     
        }
    }
}

char* Register::getName(int r) 
{
    return (char*)name[r].c_str();
}

void Register::free(int r) 
{
    reg[i] = 1;
}

}
