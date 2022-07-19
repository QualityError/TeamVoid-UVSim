/*
Team Void: UVSim
main.cpp
*/
#include "memory.h"
#include "vm.h"
#include <iostream>
#include <limits>
#include <string>
using namespace std;

void getUserProgramInput(Memory& m);
void runProgramInMemory(Memory& m);
int promptMenu(string question, string options[], int numOptions);
void mainMenu();
void subMenu();
void runProgram();

int main() {

    mainMenu();

    return 0;
}

void mainMenu(){
    string options[4] = { "Run Regular Program", "second option", "Other Options", "Quit" };
    int choice = promptMenu("string", options, sizeof(options)/sizeof(options[0]));
    switch(choice){
      case 1:
        runProgram();
        break;
      case 2:
        cout << "doing the second thing" << "\n";
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
        runProgram();
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

void runProgram(){

    //set up memory
    Memory m;
    for (int i = 0; i < m.capacity; i++){//initialize memory to be all zeros
        m.set_value(i,0);
    }

    getUserProgramInput(m);

    runProgramInMemory(m);

    loadFromFile(m);

}

void runProgramInMemory(Memory& m){
    //run program in memory
    cout<<"*** Program execution begins ***"<<endl;
    VM(m);
    m.dumpMemory();
}

// Loading saved data from a file to the Memory
void loadFromFile(Memory& m){
  /*
  Assuming instructionsData contains instructions;
           resultsData contains results.
  */
  ifstream file;
    file.open("instructionsData.txt")// Temporary instructions storage name
    int element;

    if (file.is_open()) {
        int i = 0;
        while (file >> element) {
            m.set_value(i++,element); // Reading instructions to the memory one by one
    }
  }
  // Need to figure out how to read resultsData into the array

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
