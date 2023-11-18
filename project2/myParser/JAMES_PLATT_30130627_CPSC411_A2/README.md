
Hi there!

This is my second submission, and it is late. I'm really sorry.
I slept on it and realized why I was having the issues with stmts
and arguments overnight, and have now fixed them. Obviously it's not
fair to hand in my assingment late, but I wanted to submit the corrections anyway.

to compile the prgram, you need to run the following 3 commands.

1.  flex --header-file=scanner.h -o scanner.c myScanner.l

2. bison -dvo parser.c myParser.y

3. gcc -o parser parser.c scanner.c 

there is still an issue with my pareser in that it cannot handle 
comments. This is an issue with my scanner implementation that 
I still have yet to figure out. any feedback would be greatly appreciated

I've also included some test files (including the one from the handout) that show case both what the parser can paser and what it cant'. it seems to be able to parse everything, but the formatting isn't pretty.