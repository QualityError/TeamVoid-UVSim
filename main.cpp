/*
Team Void: UVSim
main.cpp
*/
#include "memory.h"
#include "vm.h"
#include <iostream>
#include <fstream>
#include <cstdio>
#include <limits>
#include <string>
#include <vector>
using namespace std;

vector<int> getUserProgramInput(Memory& m);
const string MEMORY_DUMP_TO_FILE = "memory.txt";
const string INSTRUCTION_WRITE_FILE = "instructions.txt";

void runProgramInMemory(Memory& m);
int promptMenu(string question, string options[], int numOptions);
void mainMenu();
void subMenu();
void runProgram(bool instructions_write_flag, bool instructions_read_flag, bool memory_output_flag);
void write_instructions_to_file(vector<int> v, string filename);
void memoryOutToFile(Memory& m);
void loadFromFile(Memory& m);
void printLogo();

void printLogo() {
    cout <<"\033[32;1;4m██╗   ██╗██╗   ██╗███████╗██╗███╗   ███╗\033[0m"<<endl;
    cout <<"\033[32;1;4m██║   ██║██║   ██║██╔════╝██║████╗ ████║\033[0m"<<endl;
    cout <<"\033[32;1;4m██║   ██║██║   ██║███████╗██║██╔████╔██║\033[0m"<<endl;
    cout <<"\033[32;1;4m██║   ██║╚██╗ ██╔╝╚════██║██║██║╚██╔╝██║\033[0m"<<endl;
    cout <<"\033[32;1;4m╚██████╔╝ ╚████╔╝ ███████║██║██║ ╚═╝ ██║\033[0m"<<endl;
    cout <<"\033[32;1;4m ╚═════╝   ╚═══╝  ╚══════╝╚═╝╚═╝     ╚═╝\033[0m"<<endl;
}

int main() {
    printLogo();
    mainMenu();
    return 0;
}

void write_instructions_to_file(vector<int> v, string file_name = INSTRUCTION_WRITE_FILE) {//for user instructions
    ofstream ofs;
    ofs.open(file_name, fstream::trunc);
    for (const int& i : v) // iterate through vector putting each item in file
        ofs << i << "\n";
    ofs.close();
}

void memoryOutToFile(Memory& m) {//for memory
  m.dumpMemory(MEMORY_DUMP_TO_FILE);
}

void mainMenu(){
    string options[5] = { "Run Regular Program", "Run Program and Save", "Run Program from Load", "Quit", "About"};
    int choice = promptMenu("Hello there", options, sizeof(options)/sizeof(options[0]));
    bool instructions_write_flag = false;
    bool instructions_read_flag = false;
    bool memory_output_flag = false;
    switch(choice){
      case 1:
        runProgram(instructions_write_flag, instructions_read_flag, memory_output_flag);
        break;
      case 2:// write to file
        instructions_write_flag = true;
        memory_output_flag = true;
        runProgram(instructions_write_flag, instructions_read_flag, memory_output_flag);
        cout << "Saving..." << "\n";
        break;
      case 3:
        cout << "Loading..." << "\n";
        instructions_read_flag = true;
        runProgram(instructions_write_flag, instructions_read_flag, memory_output_flag);
        break;
      case 4:
        cout << "Exiting Program" << "\n";
        return;
        break;
      case 5:
        cout << "About stuff can go here! But UVSIM is super cool and we're all super cool and that's about all I got to say about that." << "\n";
        mainMenu();
        return;
        break;
    }
    //mainMenu();//to go back to this menu after option execution
}

void subMenu() {
    string options[4] = { "Run Regular Program", "second option", "Other Options", "To Main Menu" };

    int choice = promptMenu("This is the subMenu", options, sizeof(options) / sizeof(options[0]));
    switch (choice) {
    case 1:
        // runProgram(instructions_write_flag); // commented out so program compiles :) see mainMenu
        break;
    case 2:
        cout << "Saving..." << "\n";
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

void runProgram(bool instructions_write_flag, bool instructions_read_flag, bool memory_output_flag){

    //set up memory
    Memory m;
    for (int i = 0; i < m.capacity; i++){//initialize memory to be all zeros
        m.set_value(i,0);
    }

    //user input
    vector<int> input;
    if(instructions_read_flag){
      loadFromFile(m);
    } else {
      input = getUserProgramInput(m);
    }

    // call write_instructions_to_file with vector passed back by getUserProgramInput in variable, check flag
    if(instructions_write_flag){
      write_instructions_to_file(input);
    }
    
    VM(m);
    m.dumpMemory("");//arg is blank file path

    if(memory_output_flag){
      memoryOutToFile(m);
    }
}

void runProgramInMemory(Memory& m){
    //run program in memory
    cout<<"*** Program execution begins ***"<<endl;
    VM(m);
    m.dumpMemory("");
    memoryOutToFile(m);
}

// Loading saved data from a file to the Memory
void loadFromFile(Memory& m){

  ifstream file;
    file.open("instructions.txt");

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