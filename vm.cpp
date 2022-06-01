/*
Team Void: UVSim
vm.cpp
*/
#include <iostream>
#include "instructions.cpp"
#include "memory.h"
#include "vm.h"
using namespace std;

class UnrecognizedOpcodeException : public exception {
  int _opcode;

  public:
    string what() {
      return "Unrecognized opcode " + to_string(_opcode) + " used. Unable to execute line";
    }

  explicit UnrecognizedOpcodeException(int opcode) {
    _opcode = opcode;
  }
};


//to be renamed and moved into a class
//just a spot to temporarily hold swich statement
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
      case 34://Branch
          instructions.branch(operand, m);
          break;
      case 35://BranchNeg
          instructions.branchneg(operand, m);
          break;
      case 36://BranchZero
          instructions.branchzero(operand, m);
          break;
      case 37://HALT
          instructions.halt(operand, m);
          break;
      default:
          throw UnrecognizedOpcodeException(operand);
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

        try {
          temporarySwitchFunction(op_code, operand, m); // This function will need to pass the memory object to instructions.cpp
        } catch (exception &e) {
          cerr << e.what();
        }

        // Increment IC
        m.IC = m.IC + 1;
    }
}