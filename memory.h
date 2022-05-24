#ifndef MEMORY_H
#define MEMORY_H

#include <iostream>
using namespace std;

 class Memory {
    public:
    int memory_array[100];
    int array_size; // the actual number of instructions entered by user.
    int IR;
    int IC;
    int A;

    void set_value(int mem_location, int value) {
        memory_array[mem_location] = value;
        array_size = mem_location;
    }

    int get_value(int mem_location) {
        if (mem_location < array_size) {
            return memory_array[mem_location];
        }
    }

    void print_memory() {
        for (int i = 0; i < 100; i++) {
            cout << memory_array[i] << " ";
        }
    }
};

#endif