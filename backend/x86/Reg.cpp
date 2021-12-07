#include <string>
#include "Reg.h"

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

string Register::get16From(int r)
{
    if(r%4 == 0)
        return name[r+1];
    return name[r];
}

string Register::get8hFrom(int r)
{
    if(r%4 == 0)
        return name[r+2];
    return name[r+1];
}

string Register::get8lFrom(int r)
{
    if(r%4 == 0)
        return name[r+3];
    return name[r+2];
}


const char* Register::getName(int r)
{
    return name[r].c_str();
}

void Register::free(int r) 
{
    reg[r] = 1;
}

}
