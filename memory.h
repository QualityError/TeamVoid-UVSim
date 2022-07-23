#ifndef MEMORY_H
#define MEMORY_H

#include <iostream>
using namespace std;

class Memory {
    public:
        int last_address; // the actual number of instructions entered by user.
        int IR;
        int IC;
        int A;
        int capacity = 1000;

        void set_value(int mem_location, int value);
        int get_value(int mem_location);
        void dumpMemory(string outFile);
    
    private://should not be used outside of memory.cpp
        int memory_array[1000];

};

#endif
