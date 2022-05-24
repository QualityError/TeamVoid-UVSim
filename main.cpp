/*
Team Void: UVSim
main.cpp
*/
#include "memory.h"
#include "vm.h"
#include <iostream>
using namespace std;

const int MAX_INPUT = 100;

int main() {

    Memory m;
    int input;

    for (int i = 0; i < MAX_INPUT; i++) {
        cout << i << "? ";
        cin >> input;
        if (input == -99999) // Exit condition
            break;
        if (input < 0 || input > 9999) { // Not storing in memory if invalid
            i--;
            continue;
        }
        m.memory_array[i] = input;
    }
    m.print_memory();

    VM(m);

    return 0;
}
