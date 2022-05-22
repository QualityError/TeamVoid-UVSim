/*
Team Void: UVSim
vm.cpp
*/

#include <iostream>
#include "instructions.cpp"
using namespace std;

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