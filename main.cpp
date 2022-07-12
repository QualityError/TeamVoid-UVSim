/*
Team Void: UVSim
main.cpp
*/
#include "memory.h"
#include "vm.h"
#include <iostream>
#include <limits>
using namespace std;

int enterCommands();

int main() {
    int input = 0;
    string filePath;

    bool saveInput = false, saveOutput = false;

    cout << "*** Welcome to UVSim! ***" << endl;

    while(input == 0) {
        cout << "Please select an option" << endl;
        cout << "1. Enter UVSim commands" << endl;
        cout << "2. Load program from external file" << endl;
        cout << "3. Enable/disable save input to file" << endl;
        cout << "4. Enable/disable save output to file" << endl;

        cin >> input;

        switch(input) {
            case 1:
                return enterCommands();
            case 2:
                cout << "Enter file path" << endl;
                cin >> filePath;
                break;
            case 3:
                saveInput = !saveInput;
                cout << "Save input is now: " << saveInput << endl;
                break;
            case 4:
                saveOutput = !saveOutput;
                cout << "Save output is now: " << saveOutput << endl;
                break;
            default:
                cout << "That is an invalid option. Pleas try again." << endl;
                input = 0;
        }
    }

}

int enterCommands() {
    Memory m;
    int input = 0;

    for (int i = 0; i < m.capacity; i++){//initialize memory to be all zeros
        m.set_value(i,0);
    }

    cout << "*** Please enter your program one instruction ***" << endl;
    cout << "*** ( or data word ) at a time into the input ***" << endl;
    cout << "*** text field.  The line number and a quest- ***" << endl;
    cout << "*** ion mark will display.  Type the instruc- ***" << endl;
    cout << "*** ion for that line. Enter -99999 to compl- ***" << endl;
    cout << "*** plete entering your program and run.      ***\n" << endl;

    for (int i = 0; i < m.capacity; i++) {

        if (i < 10)
            cout << "0" << i << ": ";
        else
            cout << i << ": ";

        cin >> input;

        if (input == -99999) { // Exit condition
            m.last_address = i;
            break;
        }
        if (input < 10000 || input > 99999) { // Not storing in memory if out of range
            i--;
            cout << "ML command is the incorrect length, please input a two digit opcode and three digit memory location.\n";
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