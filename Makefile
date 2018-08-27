all: mainExe

mainExe: main.cpp
	g++ main.cpp -o mainExe
clean:
	rm *.o *.exe

