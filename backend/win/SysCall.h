#pragma once

#include <string>

using namespace std;

namespace win {

class SysCall
{
public:
    SysCall();

    string write(string label, int size);
};

}
