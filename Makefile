UVSim.app: main.o memory.o vm.o instructions.o
	g++ main.o memory.o vm.o instructions.o -o UVSim.app

main.o:
	g++ -c main.cpp

memory.o:
	g++ -c memory.cpp

vm.o:
	g++ -c vm.cpp

instructions.o:
	g++ -c instructions.cpp

clean:
	rm *.o UVSim.app