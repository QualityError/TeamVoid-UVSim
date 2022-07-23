#ifndef VM_H
#define VM_H

#include <iostream>
#include "memory.h"
using namespace std;

void VM(Memory& m1);
bool call_Operation(int op_code, int operand, Memory& m);

#endif