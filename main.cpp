/*
Team Void: UVSim
main.cpp
*/
#include "memory.h"
#include "vm.h"
#include <iostream>
#include <limits>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

const string TEMP_FILE = "instructions.txt";

vector<int> getUserProgramInput(Memory& m);
void runProgramInMemory(Memory& m);
int promptMenu(string question, string options[], int numOptions);
void mainMenu();
void subMenu();
void runProgram(bool write_flag);
void write_to_file(vector<int> v, string filename);
void loadFromFile(Memory& m);

int main() {
    
    mainMenu();
    return 0;
}

void write_to_file(vector<int> v, string file_name = TEMP_FILE) {
    ofstream ofs;
    ofs.open(file_name, fstream::trunc);
    for (const int& i : v) // iterate through vector putting each item in file
        ofs << i << "\n";
    ofs.close();
}

void mainMenu(){
    string options[4] = { "Run Regular Program", "Write to file", "Other Options", "Quit" };
    int choice = promptMenu("string", options, sizeof(options)/sizeof(options[0]));
    bool write_flag = false;
    switch(choice){
      case 1:
        runProgram(write_flag);
        break;
      case 2: // write to file
        write_flag = true;
        runProgram(write_flag);
        break;
      case 3:
        subMenu();
        break;
      case 4:
        cout << "Exiting Program" << "\n";
        return;
        break;
    }
    mainMenu();//to go back to this menu after option execution
}

void subMenu(){
    string options[4] = { "Run Regular Program", "second option", "Other Options", "To Main Menu" };
    int choice = promptMenu("string", options, sizeof(options)/sizeof(options[0]));
    switch(choice){
      case 1:
        // runProgram(write_flag); // commented out so program compiles :) see mainMenu
        break;
      case 2: 
        cout << "doing the second thing" << "\n";
        break;
      case 3:
        subMenu();
        break;
      case 4://to Main Menu
        return;//assumes main menu is the only method calling this menu
        break;
    }
    subMenu();//to go back to this menu after option execution
}

void runProgram(bool write_flag){

    //set up memory
    Memory m;
    for (int i = 0; i < m.capacity; i++){//initialize memory to be all zeros
        m.set_value(i,0);
    }

    // call write_to_file with vector passed back by getUserProgramInput in variable, check flag
    if (write_flag) {
        write_to_file(getUserProgramInput(m));
    } 
    else {
        // getUserProgramInput(m);
        loadFromFile(m);
        runProgramInMemory(m);
    }
}

void runProgramInMemory(Memory& m){
    //run program in memory
    cout<<"*** Program execution begins ***"<<endl;
    VM(m);
    m.dumpMemory();
}

// Loading saved data from a file to the Memory
void loadFromFile(Memory& m){

  ifstream file;
    file.open("instructionsData.txt");

    if (file.is_open()) {
        int i = 0;
        int element;

        while (file >> element) {
          if (element == -99999) { // Exit condition
              m.last_address = i;
              break;
          }
            m.set_value(i++,element); // Reading instructions to the memory one by one

    }
  }
  cout<<"\n*** Program loading complete ***"<<endl;
  // error handling left to do
}

vector<int> getUserProgramInput(Memory& m){
    cout << "*** Welcome to UVSim! ***" << endl;
    cout << "*** Please enter your program one instruction ***" << endl;
    cout << "*** ( or data word ) at a time into the input ***" << endl;
    cout << "*** text field.  The line number and a quest- ***" << endl;
    cout << "*** ion mark will display.  Type the instruc- ***" << endl;
    cout << "*** ion for that line. Enter -99999 to compl- ***" << endl;
    cout << "*** plete entering your program and run.      ***\n" << endl;

    vector<int> write_vector;
    int input;

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

    cout<<"\n*** Program loading complete ***"<<endl;
    return write_vector; // default to TEMP_FILE, can use filename given by user
}

int promptMenu(string question, string options[], int numOptions){
    cout << question << "\n";
    for(int i = 0; i < numOptions; i++){
        cout << i+1 << "\t" << options[i] << "\n";
    }

    int input;
    //get and validate user input
    cout<<"Enter Choice:";
    cin>>input;
    while(1){
      if(cin.fail() || input < 1 || input > numOptions){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout<<"Please enter a valid input"<<endl;
        cin>>input;
      } else {
        break;
      }
    }

    return input;
}