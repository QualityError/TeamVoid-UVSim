#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

#include "memory.h"

class instructions {
    public:
        void read(int operand, Memory m);
        void write(int operand, Memory m);
        void load(int operand, Memory m);
        void store(int operand, Memory m);
        void add(int operand, Memory m);
        void subtract(int operand, Memory m);
        void divide(int operand, Memory m);
        void multiply(int operand, Memory m);
        void branch(int operand, Memory m);
        void branchneg(int operand, Memory m);
        void branchzero(int operand, Memory m);
        void halt(int operand, Memory m);
    private:
        bool outOfBounds(int value);
};
};
#endif