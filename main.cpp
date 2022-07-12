/*
Team Void: UVSim
main.cpp
*/
#include "memory.h"
#include "vm.h"
#include <iostream>
#include <limits>
using namespace std;

void getUserProgramInput(Memory& m);
void runProgramInMemory(Memory& m);



int promptMenu(const char* question, const char* options[]){
    cout << question << "\n";
    for(int i = 0; i < 4; i++){
        cout << i << "\t" << options[i] << "\n";
    }

    //user input
    //need to validate
    cout << "Enter Choice: ";
    int input;
    cin >> input;
    return input;
}

int main() {
    //set up memory
    Memory m;
    for (int i = 0; i < m.capacity; i++){//initialize memory to be all zeros
        m.set_value(i,0);
    }
    
    const char* options[4] = { "Blue", "Red", "Orange", "Yellow" };
    int choice = promptMenu("string", options);
    //switch(choice)

    //getUserProgramInput(m);

    //runProgramInMemory(m);

    return 0;
}

void runProgramInMemory(Memory& m){
    //run program in memory
    cout<<"*** Program execution begins ***"<<endl;
    VM(m);
    m.dumpMemory();
}

void getUserProgramInput(Memory& m){
    cout << "*** Welcome to UVSim! ***" << endl;
    cout << "*** Please enter your program one instruction ***" << endl;
    cout << "*** ( or data word ) at a time into the input ***" << endl;
    cout << "*** text field.  The line number and a quest- ***" << endl;
    cout << "*** ion mark will display.  Type the instruc- ***" << endl;
    cout << "*** ion for that line. Enter -99999 to compl- ***" << endl;
    cout << "*** plete entering your program and run.      ***\n" << endl;

    int input;

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
}