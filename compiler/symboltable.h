#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H

struct Type_t {
  char* name;
}

struct Symbol_t {
  char* label;
  unsigned level;
  unsigned addr;
  Type_t type;
}

#endif
