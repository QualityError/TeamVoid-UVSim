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
        if (i < 10)
            cout << "0" << i << "? ";
        else
            cout << i << "? ";

        cin >> input;
        if (input == -99999) { // Exit condition
            break;
        }
        if (input < 1000 || input > 9999) { // Not storing in memory if out of range
            i--;
            continue;
        }
        m.set_value(i, input);
    }
    //m.print_memory(); // dump memory for debugging

    VM(m);

    return 0;
}
