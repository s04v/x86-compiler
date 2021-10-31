#include <string>
#include <iostream>
#include "constant.h"

using namespace std;

Constant::Constant() {};

Constant::Constant(ConstType t, string v) {
    type = t;
    val = v;
}

void Constant::toString() {
    cout << type << " " << val << " " << prefix << endl;
}
