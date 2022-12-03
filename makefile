all: proj3

proj3: main.o ARMInstruct.o FileManager.o
	g++ -o proj3 main.o ARMInstruct.o FileManager.o

main.o: main.cpp
	g++ -c main.cpp

ARMInstruct.o: ARMInstruct.cpp ARMInstruct.h
	g++ -c ARMInstruct.cpp

FileManager.o: FileManager.cpp FileManager.h
	g++ -c FileManager.cpp

clean:
	rm -f *.o proj3