#ifndef MEMORY_H
#define MEMORY_H

#include <iostream>
using namespace std;

class Memory {
    public:
        int array_size; // the actual number of instructions entered by user.
        int IR;
        int IC;
        int A;

        void set_value(int mem_location, int value);
        int get_value(int mem_location);
        void print_memory();
    
    private://should not be used out =side of memory.cpp
        int memory_array[100];

};

#endif