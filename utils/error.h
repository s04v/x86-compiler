#pragma once
#include <iostream>

using namespace std;

inline void errorReport(const char* text)
{
    cout << "[" <<"\033[1;31mERROR\033[0m" << "] " << text << endl;
    exit(1);
}
