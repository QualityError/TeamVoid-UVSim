/*
Team Void: UVSim
instructions.cpp
*/
#include <memory.h>
#include <iostream>
using namespace std;


class instructions {
    public:
        void read(int operand);
        void write(int operand);
        void load(int operand);
        void store(int operand);
        void add(int operand);
        void subtract(int operand);
        void divide(int operand);
        void multiply(int operand);
    private:
        bool outOfBounds(int value);
};

//I/O Operations

void instructions::read(int operand, Memory m){
  int input_value;
  cout<<"\nEnter an integer: ";
  cin>>input_value;
  m.set_value(operand,input_value);
}

void instructions::write(int operand, Memory m){
  int output_value = m.get_value(operand);
  cout<<"The value at this location is: "<<output_value<<endl;
}


// LOAD and STORE Operations

void instructions::load(int operand, Memory m) { // expecting memory object
    m.A = m.memory_array[operand];
}

void instructions::store(int operand, Memory m) { // expecting memory object
    m.memory_array[operand] = m.A;
}

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
