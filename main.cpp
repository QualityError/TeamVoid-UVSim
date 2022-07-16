/*
Team Void: UVSim
main.cpp
*/
#include "memory.h"
#include "vm.h"
#include <iostream>
#include <fstream>
#include <limits>
#include <vector>
using namespace std;

const string TEMP_FILE = "instructions.txt";

void write_to_file(vector<int> v, string file_name = TEMP_FILE) {
    ofstream ofs;
    ofs.open(file_name, fstream::trunc);
    for (const int& i : v) // iterate through vector putting each item in file
        ofs << i << "\n";
    ofs.close();
}

int main() {

    Memory m;
    int input;
    vector<int> write_vector; // write to file vector

    for (int i = 0; i < m.capacity; i++){//initialize memory to be all zeros
        m.set_value(i,0);
    }

    cout << "*** Welcome to UVSim! ***" << endl;
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
            write_vector.push_back(input);
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
        write_vector.push_back(input);
        m.set_value(i, input);
    }

    write_to_file(write_vector); // default to TEMP_FILE, can use filename given by user
    cout<<"\n*** Program loading complete ***"<<endl;
    cout<<"*** Program execution begins ***"<<endl;
    VM(m);
    m.dumpMemory();

    return 0;
}
