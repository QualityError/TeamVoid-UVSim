import subprocess

def main():
    result = testExample()
    print("TestExample :", result)
    #arithmeticResult = arithmeticTest()
    #print("TestExample :", arithmeticResult)

#example inputs ="1000\n1100\n4300\n-99999\n1200\n"
def runUVSim(inputs):
    command = "./UVSim.app"
    #run
    p = subprocess.Popen(command, stdin=subprocess.PIPE, stdout=subprocess.PIPE, shell=True, universal_newlines=True)
    output, err = p.communicate(input=inputs)
    #return
    return output[output.rfind(" "):-1]  # -1 to strip the final newline

def testExample():#Enters a number in to an adress and checks if it is there
    inputs ="10000\n11000\n43000\n-99999\n12000\n"
    output = runUVSim(inputs)
    #print(output)
    passed = True
    if(not str(output).__contains__("00\t12000\t11000\t43000")):#if string is not present
        passed = False
    if(not str(output).__contains__("01\t00000\t00000\t00000")):#if string is not present
        passed = False
    return passed # if test passed

def arithmeticTest(): # possibly create paramterized function so I am not duplicating your testExample code
    addInput = "10000\n10001\n20000\n30001\n" # store two numbers, load one into the accumulator, do math
    #subInput = "10000\n10001\n20000\n31001"
    #divInput = "10000\n10001\n20000\n32001"
    #mulInput =  "10000\n10001\n20000\n33001"
    #output = runUVSim(addInput)
    #print(output)

def testLoadVal():
    inputs = "22789\n21987\n11987\n-99999"
    output = runUVSim(inputs)
    print(output)
    return True

main()