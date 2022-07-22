/*
Team Void: UVSim
memory.cpp
*/
#include "memory.h"
#include <iostream>
#include <iomanip>
#include <bits/stdc++.h>
using namespace std;

void Memory::set_value(int mem_location, int value) {
    memory_array[mem_location] = value;
}

int Memory::get_value(int mem_location) {
    return memory_array[mem_location];
}

void Memory::dumpMemory(string outFile) {
  int op_code = IR/1000;
  int operand = IR%1000;

  stringstream a_stream;

  a_stream<<"\nREGISTERS:"<<endl;
  a_stream<<"Accumulator: \t\t"<<setw(5) << setfill('0')<<A<<endl;
  a_stream<<"InstructionCounter: \t"<<setw(2) << setfill('0')<<IC<<endl;
  a_stream<<"InstructionRegister: \t"<<setw(5) << setfill('0') <<IR<<endl;
  a_stream<<"OperationCode: \t\t"<<setw(2) << setfill('0')<<op_code<<endl;
  a_stream<<"Operand: \t\t"<<setw(3) << setfill('0')<<operand<<endl;

  a_stream<<"\nMEMORY"<<endl; a_stream<<"\t00\t01\t02\t03\t04\t05\t06\t07\t08\t09"<<endl; // Column count
  for(int i = 0; i < 1000; i += 10){
    if(i<=99){ // Row count
    a_stream <<"0"<<i*0.1<< "\t";
  }else{
    a_stream<<i*0.1<< "\t";
  }
    for(int j = i; j < 10+i && j < 1000; j++){
      a_stream << setw(5) << setfill('0') <<memory_array[j] << "\t"; // Converting output to string to display a 00000 format of the memory slot
      }
      a_stream << endl;
      }
  string the_string = a_stream.str();
  if (outFile.length() != 0) {
    ofstream cout(outFile);
    cout << the_string; // only writes the output to a file if the file is provided
  }
  else {
    cout << the_string; // always prints the output to the terminal
  }
}