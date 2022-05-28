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
  int input_value;
  cout<<"\nEnter an integer: ";
  cin>>input_value;//DO we need to validate or call validation method to re-enter data if bad?
  m.set_value(operand,input_value);
}

void instructions::write(int operand, Memory m){
  int output_value = m.get_value(operand);
  cout<<"The value at this location is: "<<output_value<<endl;
}


// LOAD and STORE Operations

void instructions::load(int operand, Memory m) { // expecting memory object
    m.A = m.get_value(operand);
}

void instructions::store(int operand, Memory m) { // expecting memory object
    m.set_value(operand,m.A);
}

//Arithmetic Operations

void instructions::add (int operand, Memory m) {
    m.A += m.get_value(operand);
    if (m.A > 99999 || m.A < 1){
        //error
    }
}

void instructions::subtract (int operand, Memory m) {
    m.A -= m.get_value(operand);
    if (m.A > 99999 || m.A < 1){
        //error
    }
}

void instructions::divide (int operand, Memory m) {
    m.A /= m.get_value(operand);
    if (m.A > 99999 || m.A < 1){
        //error
    }
}

//Branch control operations
void instructions::branch (int operand, Memory m) {
    if (m.IC > 0) {
        m.IC = m.get_value(operand);
        if (m.A > 99999 || m.A < 1){
            //error
        }
    }
}
void instructions::branchneg (int operand, Memory m) {
    if (m.IC < 0) {
        m.IC = m.get_value(operand);
        if (m.A > 99999 || m.A < 1){
            //error
        }
    }
}
void instructions::branchzero (int operand, Memory m) {
    if (m.IC == 0) {
        m.IC = m.get_value(operand);
        if (m.A > 99999 || m.A < 1){
            //error
        }
    }
}
void instructions::halt (int operand, Memory m) {
    
    if (m.IC > 99999 || m.A < 1) {
        //error
    }
}
