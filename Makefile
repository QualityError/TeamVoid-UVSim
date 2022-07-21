UVSim.app:
	g++ main.cpp memory.cpp vm.cpp instructions.cpp -o UVSim.app

clean:
	rm UVSim.app

test:
	python3 TestProgram.py
