#pragma once
#include <iostream>

using namespace std;

inline void exitError(const char* text)
{
    cout << text << endl;
    exit(1);
}
