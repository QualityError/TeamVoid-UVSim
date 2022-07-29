# TeamVoid-UVSim
UVSim Program (CS2450)

#How to use the program

    Launching the program-
        Open the main.cpp file and run without debugging.
    
        
    Navigating the Menu-
        After launching the program, a menu will display five options to choose from.
        Please type the number that corresponds with the action you wish to perform and press Enter.
        The different options are self explanatory:
            1) Run regular Program
            2) Save
            3) Load
            4) Quit
            5) About


    Running the program-
        Selecting option 1 allows you to make your own program. 
        Notice that there is a brief introduction printed to to the terminal with simple instructions on how to use the program.-
            " Please enter your program one instruction ( or data word ) at a time into the input 
            text field. The line number and a question mark will display. Type the instruction 
            for that line. Enter -99999 to complete entering your program and run"

    Basic ML-
        Here are some basic operations and their definitions to help you create your own program!
        Name - Operator - Operand - Description
            
            READ       - 10 - Destintation Memory Address - Reads a keyboard into the specific location in memory.
            WRITE      - 11 - Source Memory Address - Write a word from the specific location in memory to screen.
            WRITECHAR  - 12 - Source Memory Address - Writes a character from the specific location in memory to screen, translating the value as ascii to character.
            LOAD       - 20 - Source Memory Address - Load a word from a specific location memory into the accumulator.
            STORE      - 21 - Destination Memory Address - Store a word from the accumulator into a specific location in memory.
            LOADVAL    - 22 - Value                 - Loads a 3 digit number into the accumulator.
            ADD        - 30 - Source Memory Address - Add a word from a specific location in memory to the word in the accumulator and leave the result in the accumulator.
            SUBTRACT   - 31 - Source Memory Address - Subtract a word from a specific location in memory from the word in the accumulator and leave the result in the accumulator.
            DIVIDE     - 32 - Source Memory Address - Divide the word in the accumulator by a word from a specific location in memory and leave the result in the accumulator.
            MULTIPLY   - 33 - Source Memory Address - Multiply a word from a specific location in memory to the word in the accumulator and leave the result in the accumulator.
            BRANCH     - 40 - Branch Memory Address - Branch to a specific location in memory.
            BRANCHNEG  - 41 - Branch Memory Address - Branch to a specific location in memory if the accumulator is negative.
            BRANCHZERO - 42 - Branch Memory Address - Branch to a specific location in memory if the accumulator is zero.
            HALT       - 43 - None                  - Pause the program.

    Once you're done with your program you can save it or quit. Have fun!

#Everything that follows are individual file explanations for developers.
# File: main.cpp
    main() {
        initialize the terminal window.
        display the directions on the terminal to the user.
        a loop that prompts the user to input commands for execution.
        -- store the commands on RAM/file etc.
        execution happens in vm.cpp.
        dump the results in console (Feature 6).
        terminate the program.
        
        initialize the menu.
        display the directions on the menu to the user.
        possible include a submenu
        get and store the user commands




    }

# File: vm.cpp 
    VM stands for virtual machine. It will retrieve the opcodes and the memory locations and execute the insturctions.
        a loop that ends when no instructions are left to execute.
        retrieve the instruction from the file where the instructions are stored.
        load the instruction into IR (Instruction Register).
        create switch/if statements for instruction identification:
        -- if opcode == 10 (READ):
        ---- go to instructions.cpp /READ -> perform the operation -> go back to vm.cpp.
        increment the PC (Program Counter or Instruction Counter).

# File: instructions.cpp
    Contains instructions for execution.
    VM will use this file to execute the instructions it retrieves from a file that stores all the instructions the user inputed.

## Example:
### READ:
    user_input = int(input()) // if user inputs an integer
    memory[memory_location] = user_input // memory_location is the last two bits of the instruction that the user inputs.
                                        // it is retrieved by VM and passed as an argument to the READ instruction.

# File: memory.cpp:
    The file contains a data structure with 100 memory locations and the values in each memory location.
    It also contains IR (Instruction Register), IC (Instruction Counter), A (Accumulator) registers and their values.
    Some other files are interconnected with this file.
    Sort of like a dictionary in python:
    Example:
    {00: 00001, ..., 99: 00000}
    Or a simple array: [00001, 00005, ...]

# Ideas for user stories:
## US1: in instructions.cpp:
    Task1:  implement IO operations.
    Task2:  implement Load/Store operations.
    Task3:  implement Arithmetic operations.
    Task4:  implement Control operations.
## US2: in memory.cpp:
    Task1:  implement a data structure for memory and create three other registers (IR, IC, A).

## US3: in vm.cpp:
    Task1:  create a loop that will retrieve each instruction and load into IR.
    Task2:  create switch statements for IO operations.
    Task3:  create switch statements for Load/Store operations.
    Task4:  create switch statements for Arithmetic operations.
    Task5:  create switch statements for Control operations.
    Task6:  increment IC.

## US4: in main.cpp:
    Task1:  Set up skeleton of Code base as outlined in this document (make each file and function name).

    Task2:  initialize the terminal window.
            display the directions on the terminal to the user.

    Task3:  a loop that prompts the user to input commands for execution.
            store the commands on RAM/file etc.
