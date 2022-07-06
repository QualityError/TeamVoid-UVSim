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
  int _memory_location;

  public:
    std::string what() {
      return "Memory access violation at:  " + std::to_string(_memory_location);
    }

  explicit MemoryAccessViolation(int memory_location) {
    _memory_location = memory_location;
  }
};

class AccumulatorOverflow : public std::exception {
  int _increment_counter;
  int _accumulator;
  int _memory_location;

  public:
    std::string what() {
      return "Error: Accumulator overflow occured at line: " + std::to_string(_increment_counter) + 
                    ". Between the values " + std::to_string(_accumulator) + " and " + std::to_string(_memory_location);
    }

  explicit AccumulatorOverflow(int increment_counter, int accumulator, int memory_location) {
    _increment_counter = increment_counter;
    _accumulator = accumulator;
    _memory_location = memory_location;
  }
};

#endif