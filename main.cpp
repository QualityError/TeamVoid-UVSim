/*
Team Void: UVSim
main.cpp
*/
#include "memory.h"
#include "vm.h"
#include <iostream>
#include <limits>
using namespace std;

const int max_input = 100;

int main() {

    Memory m;
    int input;

    for (int i = 0; i < 100; i++){//initialize memory to be all zeros
        m.set_value(i,0);
    }

    cout << "Welcome to the Utah Valley ML Simulator!!"<<endl;
    cout << "========================================="<<endl;
    cout << "The UVML Sim simulates up 100 assembly commands"<<endl;

    cout << "Usage:"<<endl;
    cout << "One register is available, the accumulator register"<<endl;
    cout << "Input your desired op code followed by the desired memory location"<<endl;
    cout << "Possible Opcodes:"<<endl;
    cout << "10XX: Reads a word from the keyboard into the specific location in memory (XX)"<<endl;
    cout << "11XX: Write a word from the specific location in memory to screen"<<endl;
    cout << "20XX: Load a word from a specific location in memory into the accumulator"<<endl;
    cout << "21XX: Store a word from the accumulator into a specific location in memory"<<endl;
    cout << "30XX: Add a word from a specific location in memory to the word in the accumulator and leave the result in the accumulator"<<endl;
    cout << "31XX: Subtract a word from a specific location in memory from the word in the accumulator and leave the result in the accumulator"<<endl;
    cout << "32XX: Divide the word in the accumulator by a word from a specific location in memory and leave the result in the accumulator"<<endl;
    cout << "33XX: Multiply a word from a specific location in memory to the word in the accumulator and leave the result in the accumulator"<<endl;
    cout << "40XX: Branch to a specific location in memory."<<endl;
    cout << "41XX: Branch to a specific location in memory if the accumulator is negative"<<endl;
    cout << "42XX: Branch to a specific location in memory if the accumulator is zero"<<endl;
    cout << "4300: Halt command"<<endl;
    cout << "Input -99999 to stop inputing commands"<<endl;
    cout<<"^---!!!PLEASE SEE THE REQUIREMENTS FOR WELCOME MESSAGE!!!---^"<<endl;

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
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        m.set_value(i, input);
    }

    

    VM(m);

    // m.print_memory(); // visualize memory
    m.dumpResults();

    return 0;
}
