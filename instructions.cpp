/*
Team Void: UVSim
instructions.cpp
*/
#include <iostream>
#include "instructions.h"
#include "memory.h"
using namespace std;

//I/O Operations

void instructions::read(int operand, Memory m){
    // if operand is not within range of memory (0-99), throw error: out of range
    // check if input_value is a valid integer, throw error: invalid input (different types of invalid input)
    int input_value;
    cout<<"\nEnter an integer: ";
    cin>>input_value;//DO we need to validate or call validation method to re-enter data if bad?
    m.set_value(operand,input_value);
}

void instructions::write(int operand, Memory m){
    // if operand is not within range of memory (0-99), throw error: out of range
    int output_value = m.get_value(operand);
    cout<<"The value at this location is: "<<output_value<<endl;
}


// LOAD and STORE Operations

void instructions::load(int operand, Memory m) {
    // if operand is not within range of memory (0-99), throw error: out of range
    m.A = m.get_value(operand);
}

void instructions::store(int operand, Memory m) {
    // if operand is not within range of memory (0-99), throw error: out of range
    m.set_value(operand, m.A);
}

//Arithmetic Operations

void instructions::add (int operand, Memory m) {
    // if operand is not within range of memory (0-99), throw error: out of range
    // check if value at memory[operand] is an integer or double, otherwise throw error: invalid math operation
    m.A += m.get_value(operand);
    // check if value in accumulator after operation occurs is an overflow, throw error: overflow
}

void instructions::subtract (int operand, Memory m) {
    // if operand is not within range of memory (0-99), throw error: out of range
    // check if value at memory[operand] is an integer or double, otherwise throw error: invalid math operation
    m.A -= m.get_value(operand);
    // check if value in accumulator after operation occurs is an overflow, throw error: overflow
}

void instructions::divide (int operand, Memory m) {
    // if operand is not within range of memory (0-99), throw error: out of range
    // check if value at memory[operand] is an integer or double, otherwise throw error: invalid math operation
    // check memory[operand] for zero, throw error: divide by zero
    m.A /= m.get_value(operand);
    // check if value in accumulator after operation occurs is an overflow, throw error: overflow
}

//Branch control operations
void instructions::branch (int operand, Memory m) {
    // if operand is not within range of memory (0-99), throw error: invalid branch loaction
    // check if IC is in a valid location (0-99), throw error: IC out of bounds
    if (m.IC > 0) { // branch to location regardless of condition
        m.IC = m.get_value(operand); // want to set IC to operand 
    }
}
void instructions::branchneg (int operand, Memory m) {
    // if operand is not within range of memory (0-99), throw error: invalid branch loaction
    // check if IC is in a valid location (0-99), throw error: IC out of bounds
    if (m.IC < 0) { // want to check if A is negative not IC
        m.IC = m.get_value(operand); // want to set IC to operand 
    }
}
void instructions::branchzero (int operand, Memory m) {
    // if operand is not within range of memory (0-99), throw error: invalid branch loaction
    // check if IC is in a valid location (0-99), throw error: IC out of bounds
    if (m.IC == 0) { // want to check if A is 0 not IC
        m.IC = m.get_value(operand); // want to set IC to operand 
    }
}
