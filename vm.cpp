/*
Team Void: UVSim
vm.cpp
*/
#include <iostream>
#include "exceptions.h"
#include <string>
#include "instructions.h"
#include "memory.h"
#include "vm.h"
using namespace std;

//to be renamed and moved into a class
//just a spot to temporarily hold switch statement
bool call_Operation(int op_code, int operand, Memory& m){
    instructions instructions;//create instructions object
    bool continue_running = true;
    switch(op_code) {
      case 10://READ
        instructions.read(operand, m);
        break;
      case 11://WRITE
        instructions.write(operand, m);
        break;
      case 12: //WRITECHAR
        instructions.writeChar(operand,m);
      case 20://LOAD
          instructions.load(operand, m);
          break;
      case 21://STORE
          instructions.store(operand, m);
          break;
      case 22://LOAD VAL
          instructions.loadval(operand, m);
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
      case 40://Branch
          instructions.branch(operand, m);
          break;
      case 41://BranchNeg
          instructions.branchneg(operand, m);
          break;
      case 42://BranchZero
          instructions.branchzero(operand, m);
          break;
      case 43://HALT
          continue_running = false;//sets continue running
          break;
      default:
          throw UnrecognizedOpcodeException(op_code); //Invalid op code
          break;
    }

    // print any errors set running to false

    return continue_running;//sets continue running
}

void VM(Memory& m) {
    m.IC = -1;
    int op_code;
    int operand;
    bool continue_running = true;
    while (continue_running) {
        // Increment IC
        m.IC = m.IC + 1;

        if (m.IC >= m.capacity || m.IC == m.last_address) {
          m.IC--;
          break;
        }

        m.IR = m.get_value(m.IC); // retrieve the instruction from memory
        op_code = (m.IR / 1000);
        operand = (m.IR % 1000);

        try {
          if (operand < 0 || operand > (m.capacity - 1))
            throw runtime_error("Error: Memory access violation.");
          continue_running = call_Operation(op_code, operand, m); // This function will need to pass the memory object to instructions.cpp
        } catch (exception &e) {
          cerr << e.what();
        }
    }
}
