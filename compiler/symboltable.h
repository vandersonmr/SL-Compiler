#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H

#include "list.h"

#define Type struct Type_t
#define Symbol struct Symbol_t

struct Type_t {
  char* label;
  unsigned size;
};

struct Symbol_t {
  char* label;
  int level;
  int addr;
  Type* type;
};

#define MAX_STACK_SIZE 20

int getNextAddrs();
int increaseStackSize();
int decreaseStackSize();
Symbol* insertSymbol(char*, char*);
Symbol* findSymbol(char*);
Type* insertType(char*, unsigned);
Type* findType(char*);

#endif
