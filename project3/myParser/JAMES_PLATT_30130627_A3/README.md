James Platt 30130627
CPSC 411 Assignment 3

Hi There!

This is my submission for cpsc 411 assignment 3.
I have implemented all the checks as specified in the outline and included a sweet of
tests for these checks under /tests. 

I have also improved on all the parsing issues of
my last submission for assignment 2. I'm not exactly sure how many issues my previous 
submission had, so I would like this submission to be ran against all the assignment 2 tests, 
but at the very least I improved on my last submission by fixing how empty functions are parsed,
how function arguments are parsed, added line numbers to all outputs, improved how the ast looks
for a chain of if statements (as shown below) and fixed a number of stability issues / crashes
when parsing things that it did support. It still does not support composite statements inside of 
composite statements though, as I didn't have time to fix that, and the floating else
issue is also still present, but every other parsing issue should be fixed.

- The output from a successfull is an AST with type information that may look something like this:

pring the tree!
Checking semantics
Semantics are good!
Program 
	Var Int u @1
	Var Int y @2
Func Void test @6
 
Func Int gcd @10
	Return Expression @9: INT: 7
Func Void temp @17
 	Int[] Param x @12
	Var Int z @13
	Var Int y1 @14
	Expression @16 of type INT: z == INT: 10
Func Int main @38
	Var Int x @20
	Var Int y2 @20
	Var Int[5] z @20
	Var Int u3 @21
	Expression @22 of type INT: x = INT: y2
	Expression @24 of type INT[]: z[INT: 4] = INT: 10
	Expression @26 of type VOIDFUNC: temp(INT[]: z)
	Expression @28 of type INT: gcd() * 1
	Expression @30 of type INT: x = INTFUNC: gcd()
	If Expression @38: INT: y2 = INT: x
		if statment @38: 
			If Expression @38: INT: x = INT: 4
				if statment @37: 
					If Expression @37: INT: y2 == INT: 2
						if statment @35: 
							Return Expression @35: INT: u3
						else statement @37: 
							Expression @37 of type INT: y2 = INT: 2


- This output can be interpreted as a program that meets the requirments on the c- grammar and semantic rules.
All expressions are marked by their types, and further type information of components is included when
it may be useful. params / local variables are denoted with either 'Var' before the type if it is a var,
or 'Param' after the type if it is a param. You can tell if a var or param belongs to a function by weather or not it 
appears under a function line (belongs), or if it is on it's own (global). I implemented unique IDs by attaching a unique digit to the end of any local variable that has the same name as a global variable, as shown above

- There are also 3 test files containing multiple tests each for the seperate types of checks I implemented for this assignment. 
You can run a test by uncommenting it, and then running the program against the file. What is being tested and the expected output is specified on each test.

NOTE: I implemented my analyzer using c, and used some gnu libraries (glib-2.0) so that 
I could have access to some nicely implemented hash tables. As such, you will need to compile
this program from a linux device that has these gnu tools installed (basically all of them.)
I checked that my program compiles on the univeristy Linux Lab machines and it does. I'm not
sure if it can be ran from an osx device.

**COMPILE AND RUN** - to compile my program run the following commands

1. make flex

2. make bison

3. make compile

this will create a program called 'parser' which you can use by running

./parser <name of file you would like to test against>


**FILES AND STRUCTURE**
- basically my program can be broken down as follows
	scanning -> myScanner.l
	grammarRules and tree building -> myParser.y
	ast node constructors -> createAST.c
	semanticRoutines -> mySem.c
	ast printing -> printAST.c
	structs,enums -> structs.h
	functionDefintions for mySem, printAST, and createAST -> myAST.h
