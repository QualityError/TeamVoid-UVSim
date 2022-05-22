#ifndef MEMORY_H
#define MEMORY_H

#include <iostream>
using namespace std;

 class Memory {
    public:
    int memory_array[100];
    int IR;
    int IC;
    int A;

    void set_value(int mem_location, int value) {
        memory_array[mem_location] = value;
    }

    void print_memory() {
        for (int i = 0; i < 100; i++) {
            cout << memory_array[i] << " ";
        }
    }
};

#endif