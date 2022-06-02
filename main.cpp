/*
Team Void: UVSim
main.cpp
*/
#include "memory.h"
#include "vm.h"
#include <iostream>
using namespace std;

const int max_input = 100;

int main() {

    Memory m{};
    int input;

    for (int i = 0; i < 100; i++){//initialize memory to be all zeros
        m.set_value(i,0);
    }

    cout << "Welcome to the Utah Valley ML Simulator!!";
    cout << "=========================================";
    cout << "The UVML Sim simulates up 100 assembly commands";

    cout << "Usage:\n";
    cout << "One register is available, the accumulator register";
    cout << "Input your desired op code followed by the desired memory location";
    cout << "Possible Opcodes:";
    cout << "10XX: Reads a word from the keyboard into the specific location in memory (XX)";
    cout << "11XX: Write a word from the specific location in memory to screen";
    cout << "20XX: Load a word from a specific location in memory into the accumulator";
    cout << "21XX: Store a word from the accumulator into a specific location in memory";
    cout << "30XX: Add a word from a specific location in memory to the word in the accumulator and leave the result in the accumulator";
    cout << "31XX: Subtract a word from a specific location in memory from the word in the accumulator and leave the result in the accumulator";
    cout << "32XX: Divide the word in the accumulator by a word from a specific location in memory and leave the result in the accumulator";
    cout << "33XX: Multiply a word from a specific location in memory to the word in the accumulator and leave the result in the accumulator";
    cout << "40XX: Branch to a specific location in memory.";
    cout << "41XX: Branch to a specific location in memory if the accumulator is negative";
    cout << "42XX: Branch to a specific location in memory if the accumulator is zero";
    cout << "4300: Halt command";
    cout << "Input -99999 to stop inputing commands";

    for (int i = 0; i < max_input; i++) {
        if (i < 10)
            cout << "0" << i << ": ";
        else
            cout << i << ": ";

        cin >> input;
        if (input == -99999) { // Exit condition
            break;
        }
        if (input < 1000 || input > 9999) { // Not storing in memory if out of range
            i--;
            cout << "ML command is the incorrect length, please input a two digit opcode and two digit memory location";
            continue;
        }
        m.set_value(i, input);
    }
    m.print_memory(); // visualize memory

    VM(m);

    return 0;
}
