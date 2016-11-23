all:
	bison -d -o parser.c parser.y
	flex -i -o scanner.c  scanner.l
	gcc -g -O0 -std=c99 -o slc *.c
