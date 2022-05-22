# TeamVoid-UVSim
UVSim Program (CS2450)

# File: main.cpp
    # main() {
        # initialize the terminal window.
        # display the directions on the terminal to the user.
        # a loop that prompts the user to input commands for execution.
        # -- store the commands on RAM/file etc.
        # execution happens in vm.cpp.
        # display the content at each location to the user (Feature 5).
        # dump the results in concole (Feature 6).
        # terminate the program.
    # }

# File: vm.cpp 
    # VM stands for virtual machine. It will retrieve the opcodes and the memory locations and execute the insturctions.
        # a loop that ends when no instructions are left to execute.
        # retrieve the instruction from the file where the instructions are stored.
        # load the instruction into IR (Instruction Register).
        # create switch/if statements for instruction identification:
        # -- if opcode == 10 (READ):
        # ---- go to instructions.cpp /READ -> perform the operation -> go back to vm.cpp.
        # increment the PC (Program Counter or Instruction Counter).

# File: instructions.cpp
    # Contains instructions for execution.
    # VM will use this file to execute the instructions it retrieves from a file that stores all the instructions the user inputed.
    # Example:
        # READ:
            # user_input = int(input()) // if user inputs an integer
            # memory[memory_location] = user_input // memory_location is the last two bits of the instruction that the user inputs.
            #                                      // it is retrieved by VM and passed as an argument to the READ instruction.

# File: registers.cpp
    # The file contains a data structure with 100 memory locations and the values in each memory location.
    # It also contains IR (Instruction Register), IC (Instruction Counter), A (Accumulator) registers and their values.
    # Some other files are interconnected with this file.
    # Sort of like a dictionary in python:
    # Example:
        # {00: 00001, ..., 99: 00000}
        # Or a simple array: [00001, 00005, ...]

# Ideas for user stories:
    # US1: in instructions.cpp:
        # Task1: implement IO operations.
        # Task2: implement Load/Store operations.
        # Task3: implement Arithmetic operations.
        # Task4: implement Control operations.
    # US2: in registers.cpp:
        # Task1: implement a data structure for memory and create three other instructions (IR, IC, A).
    # US3: in vm.cpp:
        # Task1: create a loop that will retrieve each instruction and load into IR.
        # Task2: create switch statements for IO operations.
        # Task3: create switch statements for Load/Store operations.
        # Task4: create switch statements for Arithmetic operations.
        # Task5: create switch statements for Control operations.
        # Task6: increment IC.
    # US4: in main.cpp:
        # Task3: implement Arithmetic operations.
        # Task4: implement Control operations.
    # US2: in memory.cpp:
        # Task1: implement a data structure for memory and create three other instructions (IR, IC, A).
        # Task1: implement a data structure for memory and create three other registers (IR, IC, A).
    # US3: in vm.cpp:
        # Task1: create a loop that will retrieve each instruction and load into IR.
        # Task2: create switch statements for IO operations.
        