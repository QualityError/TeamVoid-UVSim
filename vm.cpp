/*
Team Void: UVSim
vm.cpp
*/
#include <iostream>
#include "vm.h"
#include "memory.h"
#include "instructions.h"
using namespace std;


//to be renamed and moved into a class
//just a spot to temporarily hold switch statement
void temporarySwitchFunction(int op_code, int operand, Memory m){
    instructions instructions;//create instructions object
    switch(op_code) {
      case 10://READ
        instructions.read(operand, m);
        break;
      case 11://WRITE
        instructions.write(operand, m);
        break;
      case 20://LOAD
          instructions.load(operand, m); // expecting memory object to pass to instructions.cpp
          break;
      case 21://STORE
          instructions.store(operand, m); // expecting memory object to pass to instructions.cpp
          break;
      case 30://ADD
          instructions.add(operand, m);
          break;
      case 31://Subtract
          instructions.subtract(operand, m);
          break;
      case 32://Divide
          instructions.divide(operand, m);
          break;
      case 33://Multiple
          instructions.multiply(operand, m);
          break;
      default:
          //Invalid op code
          //display appropriate error
          break;
    }
}

void VM(Memory m) {
    m.IC = 0;
    int op_code;
    int operand;
    while (m.IC < m.array_size) {
        m.IR = m.get_value(m.IC); // retrieve the instruction from memory
        op_code = (m.IR / 100);
        operand = (m.IR % 100);
        temporarySwitchFunction(op_code, operand, m); // This function will need to pass the memory object to instructions.cpp

        // Increment IC
    }
}
