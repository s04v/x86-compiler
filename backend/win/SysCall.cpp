#include "SysCall.h"
#include <string>

using namespace std;

namespace win {

SysCall::SysCall()
{

}


string SysCall::write(string label, int size)
{
    string ret = "";
    ret +=  "call write"; // TODO:
    return ret;
}

}
