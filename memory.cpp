/*
Team Void: UVSim
memory.cpp
*/
#include "memory.h"
#include <iostream>
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
    for (int i = 0; i < 100; i++) {
        cout << memory_array[i] << " ";
    }
}