#pragma once 

#include <string>
#include "Operand.h"

using namespace std;

class Id : public Operand {
public:
    string name;
    Id(string n) : name(n) {}; 
};