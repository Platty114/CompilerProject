HOW TO COMPILE AND RUN THE PROJECT

-> there is a make file included in this project. So, if you are
on a linux machine with g++ installed, all you need to do is run 

    make

to compile the project, and then you can run the project by running

    ./scanner inputFileName outputFileName

where  [inputFileName] is the name of the file you would like to scan,
and [outputFileName] is the name you would like for the oupted file.

    ex ./scanner input.txt output.txt


TEST FILE

-> there is a test file called 'input.txt' that tests for many different cases, which
are all specified in the comments of the given file. There is also a file called output.txt
with the results of running the scanner on input.txt, with the output categorized by test,
just to make things easier for you. Definetely produce another file though.


INTERPRETTING OUPUT

-> I tried to follow the same kind of ouput style as given in the handout
so each line specifies the details of a token in the following format

    lineNumber: tokenType [optional details]

for example 'void' on line 1 would be

    1: VOID

an id on line 1 would be 

    1: ID "main"

a number 999 on line 1 would be

    1: NUM "999"

and an error would be

    1: ERROR: 'error message'