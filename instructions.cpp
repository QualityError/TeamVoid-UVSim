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


