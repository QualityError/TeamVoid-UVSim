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

    cout << "*** Welcome to UVSim! ***" << endl;
    cout << "*** Please enter your program one instruction ***" << endl;
    cout << "*** ( or data word ) at a time into the input ***" << endl;
    cout << "*** text field.  The line number and a quest- ***" << endl;
    cout << "*** ion mark will display.  Type the instruc- ***" << endl;
    cout << "*** ion for that line. Enter -99999 to compl- ***" << endl;
    cout << "*** plete entering your program and run.      ***\n" << endl;

    for (int i = 0; i < max_input; i++) {

        if (i < 10)
            cout << "0" << i << ": ";
        else
            cout << i << ": ";

        cin >> input;

        if (input == -99999) { // Exit condition
            m.last_address = i;
            break;
        }
        if (input < 1000 || input > 9999) { // Not storing in memory if out of range
            i--;
            cout << "ML command is the incorrect length, please input a two digit opcode and two digit memory location.\n";
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        m.set_value(i, input);
    }
    
    cout<<"\n*** Program loading complete ***"<<endl;
    cout<<"*** Program execution begins ***"<<endl;
    VM(m);
    m.dumpMemory();

    return 0;
}
