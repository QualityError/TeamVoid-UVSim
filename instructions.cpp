/*
Team Void: UVSim
instructions.cpp
*/

#include <iostream>
using namespace std;


class instructions {
    public:
        void add(int operand);
        void subtract(int operand);
        void divide(int operand);
        void multiply(int operand);
        void branch(int operand);
        void branchneg(int operand);
        void branchzero(int operand);
        void halt(int operand);
    private:
        bool outOfBounds(int value);
};


//Arithmetic Operations

void instructions::add (int operand) {
    Memory.accumulator += Memory.array[operand];
    if (outOfBounds(Memory.accumulator)){
        //error
    }
}

void instructions::subtract (int operand) {
    Memory.accumulator -= Memory.array[operand];
    if (outOfBounds(Memory.accumulator)){
        //error
    }
}

void instructions::divide (int operand) {
    Memory.accumulator /= Memory.array[operand];
    if (outOfBounds(Memory.accumulator)){
        //error
    }
}

void instructions::multiply (int operand) {
    Memory.accumulator *= Memory.array[operand];
    if (outOfBounds(Memory.accumulator)){
        //error
    }
}

//checks if value manipulated is out of the storage range
bool outOfBounds(int value){
    if (value > 99999 || value < 1){
        return true; //out of bounds
    }
    return false; // inbounds
}

//Control operations
void instructions::branch (int operand) {
    if (operand > 0) {
        return true;
    }
    continue;
}


void instructions::branchneg (int operand) {
    if (operand < 0) {
        return true;
    }
    continue;
}


void instructions::branchzero (int operand) {
    if (operand == 0) {
        return true;
    }
    continue;
}

void instructions::halt (int operand) {
    break;
}

