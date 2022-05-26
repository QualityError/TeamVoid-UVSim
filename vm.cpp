/*
Team Void: UVSim
vm.cpp
*/
#include "memory.h"
#include <iostream>
#include "instructions.cpp"
using namespace std;


void VM(Memory m) {
    m.IC = 0;
    int op_code;
    int operand;
    while (m.IC < m.array_size) {
        m.IR = m.get_value(m.IC); // retrieve the instruction from memory
        op_code = (m.IR / 100);
        operand = (m.IR % 100);
        temporarySwitchFunction(op_code, operand); // This function will need to pass the memory object to instructions.cpp
        
        // Increment IC
        m.IC = m.IC + 1;
    }
}

//to be renamed and moved into a class
//just a spot to temporarily hold swich statement
void temporarySwitchFunction(int op_code, int operand){
    instructions instructions;//create instructions object
    switch(op_code) {
        case 30://ADD
            instructions.add(operand);
            break;
        case 31://Subtract
            instructions.subtract(operand);
            break;
        case 32://Divide
            instructions.divide(operand);
            break;
        case 33://Multiple
            instructions.multiply(operand);
            break;
        default:
            //Invalid op code
            //display appropriate error
    }
} 

//Switch statements for control operations
void switchStatementsControlOpsFunction(int op_code, int operand) {
    instructions instructions;
    switch(op_code) {
        case 34://Branch
            instructions.branch(operand);
            break;
        case 35://BranchNeg
            instructions.branchneg(operand);
            break;
        case 36://BranchZero
            instructions.branchzero(operand);
            break;
        case 37://HALT
            instructions.halt(operand);
            break;
        default:
            //Invalid op code
            //display appropriate error
    }
}
