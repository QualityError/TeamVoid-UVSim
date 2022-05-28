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
    array_size = mem_location;
}

int Memory::get_value(int mem_location) {
    if (mem_location < array_size) {
        return memory_array[mem_location];
    }
    //need other return, not a void function
}

void Memory::print_memory() {
    cout<<"MEMORY"<<endl; cout<<"\t00\t\t01\t\t02\t\t03\t\t04\t\t05\t\t06\t\t07\t\t08\t\t09"<<endl; // Column count
    for(int i = 0; i < 100; i += 10){
      cout <<"0"<<i*0.1<< "\t"; // Row count
      for(int j = i; j < 10+i && j < 100; j++){ 
        cout << setw(5) << setfill('0') <<memory_array[j] << "\t"; // Converting output to string to display a 00000 format of the memory slot
        }  
        cout << endl;
        }
  }
