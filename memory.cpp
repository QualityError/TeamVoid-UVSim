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
    cout<<"MEMORY"<<endl; cout<<"\t00\t01\t02\t03\t04\t05\t06\t07\t08\t09"<<endl; // Column count
    for(int i = 0; i < 100; i += 10){
      cout <<"0"<<i*0.1<< "\t"; // Row count
      for(int j = i; j < 10+i && j < 100; j++){ 
        cout << setw(5) << setfill('0') <<memory_array[j] << "\t"; // Converting output to string to display a 00000 format of the memory slot
        }  
        cout << endl;
        }
  }

void Memory::dumpResults(){
    int op_code;
    int operand;
    IR = Memory::get_value(IC); // retrieve the instruction from memory
    op_code = (IR / 100);
    operand = (IR % 100);
    cout<<op_code;
}