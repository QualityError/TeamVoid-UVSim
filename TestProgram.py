import subprocess

def main():
    result = testExample()
    print("TestExample :", result)

#example inputs ="1000\n1100\n4300\n-99999\n1200\n"
def runUVSim(inputs):
    command = "./UVSim.app"
    #run
    p = subprocess.Popen(command, stdin=subprocess.PIPE, stdout=subprocess.PIPE, shell=True, universal_newlines=True)
    output, err = p.communicate(input=inputs)
    #return
    return output[output.rfind(" "):-1]  # -1 to strip the final newline

def testExample():
    inputs ="1000\n1100\n4300\n-99999\n1200\n"
    output = runUVSim(inputs)
    #print(output)
    return True # if test passed

def testLoadVal():
    inputs = "22789\n21987\n11987\n-99999"
    output = runUVSim(inputs)
    print(output)
    return True

main()