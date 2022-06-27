#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <string>

class UnrecognizedOpcodeException : public std::exception {
  int _opcode;

  public:
    std::string what() {
      return "Unrecognized opcode " + std::to_string(_opcode) + " used. Unable to execute line";
    }

  explicit UnrecognizedOpcodeException(int opcode) {
    _opcode = opcode;
  }
};

class MemoryAccessViolation : public std::exception {
  int _opcode;

  public:
    std::string what() {
      return "Memory access violation at:  " + std::to_string(_opcode);
    }

  explicit MemoryAccessViolation(int opcode) {
    _opcode = opcode;
  }
};

class AccumulatorOverflow : public std::exception {
  int _increment_counter;
  int _accumulator;
  int _memory_val;

  public:
    std::string what() {
      return "Error: Accumulator overflow occured at line: " + std::to_string(_increment_counter) + 
                    ". Between the values " + std::to_string(_accumulator) + " and " + std::to_string(_memory_val);
    }

  explicit AccumulatorOverflow(int increment_counter, int accumulator, int memory_val) {
    _increment_counter = increment_counter;
    _accumulator = accumulator;
    _memory_val = memory_val;
  }
};

#endif