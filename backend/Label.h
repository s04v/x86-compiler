#pragma once
#include <string>

using namespace std;

namespace Backend {

class Label
{
    int count = 0;
    int countString = 0;
public:
    Label() {};

    string create() {
        string s = ".L";
        s += to_string(count++);
        return s;
    }

    string createString() {
        string s = "S";
        s += to_string(count++);
        return s;
    }
};

}

