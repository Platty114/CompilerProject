all: compile clean

compile: main.o tokenHelpers.o fileHelpers.o
	g++ main.o tokenHelpers.o fileHelpers.o -o scanner

main.o: main.cpp
	g++ -c main.cpp

tokensHelpers.o: tokenHelpers.cpp
	g++ -c tokenHelpers.cpp

fileHelpers.o: fileHelpers.cpp
	g++ -c fileHelpers.cpp

clean:
	rm main.o tokenHelpers.o fileHelpers.o