#include "symboltable.h"
#include <string.h>
#include <stdlib.h>
#include "slc.h"

int level = -1;
List* types_stack[MAX_STACK_SIZE];
List* symbol_stack[MAX_STACK_SIZE];

int increaseStackSize() {
  level += 1;
//  printf("level: %d\n", level);
  types_stack[level] = allocList(NULL, 0);
  symbol_stack[level] = allocList(NULL, 0);
  return level;
}

int decreaseStackSize() {
  level -= 1;
  return level;
  //TODO: Memory leak
}

int getNextAddrs() {
  int addr = 0;
  unsigned level_size = getListSize(symbol_stack[level]);
  for (int i = 0; i < level_size; i++) {
      Symbol* sym = getFromList(symbol_stack[level], i);
      if (sym != NULL)
        addr += sym->type->size;
  }
  return addr;
}

Symbol* insertSymbol(char* label, char* type) {
  Symbol* sym = malloc(sizeof(Symbol));
  sym->label = malloc(strlen(label));
  strcpy(sym->label, label);
  sym->level = level;
  sym->addr = getNextAddrs();
  sym->type = findType(type);
  if (sym->type == NULL)  SemanticError("Didn't find a type\n");
  insertIntoList(symbol_stack[level], sym, 0);
//  printf("inserting symbol: %s : %s at level %d and addr %u\n", sym->label, sym->type->label, sym->level, sym->addr);
  return sym;
}

Symbol* findSymbol(char* label) {
  for (int l = level; l >= 0; l--) {
    unsigned level_size = getListSize(symbol_stack[l]);
    for (int i = 0; i < level_size; i++) {
      Symbol* sym = getFromList(symbol_stack[l], i);
      if (sym == NULL) continue;
      if (strcmp(sym->label, label) == 0) {
//        printf("variable %s : %s found in level %d at %u\n", sym->label, sym->type->label, sym->level, sym->addr);
        return sym;
      }
    }
  }
  return NULL;
}

Type* insertType(char* label, unsigned size) {
//  printf("inserting type: %s with size: %u at level %d\n", label, size, level);
  Type* type = malloc(sizeof(Type));
  type->label = malloc(strlen(label));
  strcpy(type->label, label);
  type->size = size;
  insertIntoList(types_stack[level], type, 0);
  return type;
}

Type* findType(char* label) {
  for (int l = level; l >= 0; l--) {
    unsigned level_size = getListSize(types_stack[l]);
    for (int i = 0; i < level_size; i++) {
      Type* type = getFromList(types_stack[l], i);
      if (type == NULL) continue;
      if (strcmp(type->label, label) == 0)
        return type;
    }
  }
  return NULL;
}
