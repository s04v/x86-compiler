#pragma once 
#include <string>
#include <iostream>


using namespace std;

inline string int2str(int n)
{
    string s = to_string(n);
    if(n > 0)
        s.insert(0,1,'+');
    return s;
}