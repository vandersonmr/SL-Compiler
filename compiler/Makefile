all:
	bison -d -o parser.c parser.y
	flex -i -o scanner.c  scanner.l
	gcc -std=c99 -pedantic -o slc *.c
