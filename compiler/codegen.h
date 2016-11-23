#ifndef CODEGEN_H
#define CODEGEN_H

/*
 * Types:
 * 0 - Program
 * 1 - void function
 * 2 - function
 * 3 - function declaration
 * 4 - formal params
 * 5 - block
 * 6 - call
 * 7 - type list
 * 8 - type
 * 9 - array type
 * 10- while
 * 11- if
 * 12- ifelse
 * 13- goto
 * 14- return
 * 15- return with value
 * 16- assignment
 * 17- negation
 * 18- int
 * 19- identifier
 * 20- relational exp
 * 21- var
 * 22- array var
 * 23- varlist
 * 24- value param
 * 25- var param
 * 26- func param
 * 27- label
 * 28- simple exp
 * 29- term
 * 30- additivelist
 * 31- multiplicativeList
 * 32- compound
 */

int stackHeight();
void processProgram(void*);

#endif
