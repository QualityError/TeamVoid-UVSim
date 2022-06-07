/*
Team Void: UVSim
memory.cpp
*/
#include "memory.h"
#include <iostream>
#include <iomanip>
using namespace std;

void Memory::set_value(int mem_location, int value) {
    memory_array[mem_location] = value;
}

int Memory::get_value(int mem_location) {
    return memory_array[mem_location];
}

void Memory::print_memory() {
    cout<<"\nMEMORY"<<endl; cout<<"\t00\t01\t02\t03\t04\t05\t06\t07\t08\t09"<<endl; // Column count
    for(int i = 0; i < 100; i += 10){
      cout <<"0"<<i*0.1<< "\t"; // Row count
      for(int j = i; j < 10+i && j < 100; j++){ 
        cout << setw(5) << setfill('0') <<memory_array[j] << "\t"; // Converting output to string to display a 00000 format of the memory slot
        }  
        cout << endl;
        }
  }

void Memory::dumpMemory() {
    int op_code = IR/100;
    int operand = IR%100;
    cout<<"\nREGISTERS:"<<endl;
    cout<<"Accumulator: \t\t"<<setw(5) << setfill('0')<<A<<endl;
    cout<<"InstructionCounter: \t"<<setw(2) << setfill('0')<<IC<<endl;
    cout<<"InstructionRegister: \t"<<setw(5) << setfill('0') <<IR<<endl;
    cout<<"OperationCode: \t\t"<<setw(2) << setfill('0')<<op_code<<endl;
    cout<<"Operand: \t\t"<<setw(2) << setfill('0')<<operand<<endl;
    print_memory();
}
