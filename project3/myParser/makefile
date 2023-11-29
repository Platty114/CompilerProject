flex: myScanner.l
	flex --header-file=scanner.h -o scanner.c myScanner.l

bison: myParser.y
	bison -dvo parser.c myParser.y

compile: parser.c scanner.c createAST.c printAST.c mySem.c
	gcc `pkg-config --cflags --libs glib-2.0` parser.c scanner.c createAST.c printAST.c mySem.c -o parser
