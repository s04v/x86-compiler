#include <string>
#include "reg.h"

using namespace std;


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

int Register::alloc16() {}
int Register::alloc32() {}

char* Register::getName(int r) 
{
    return (char*)name[r].c_str();
}
void Register::free(int r) {}