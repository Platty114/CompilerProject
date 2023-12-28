Welcome to my Compiler Project!

Here you can find a work in progress compiler I've been building for the C- language as specified in this textbook 
https://www3.nd.edu/~dthain/compilerbook/

Currently it is able to do scan a file for tokens, parse the tokens, and perform basic semantic checks on the input.

HOW TO RUN
----------------------
 - Navigate to the src directory and run the 3 following commands.
 	1. make flex
	2. make bison
	3. make compile
 
This will produce an executable named 'parser', which can be ran on a file in the following fasion
	./parser <nameOfFileForCompilation>

	ie

	./parser input.txt

OUTPUT
-----------------------
- in this projects current state, there are 1 of 2 possible outputs from the program.
	1. There is a lexical, syntactic or semantic error in the given file so an appropiate error is printed.
	2. There are no erros so a Abstract syntax tree with type information is printed to the console.

TESTS
-----------------------
- I've implemented some tests along the way of developing this project, specifically for lexical / semantic analysis.
  These tests can be found in the tests folder, each providing different test cases and their respective correct output, as well as descriptions of how they should be ran.
