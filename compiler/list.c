#include "list.h"
#include <stdlib.h>

unsigned getListSize(List* list) {
  List* next = list;
  if (next == NULL) return 0;
  unsigned size = 1;
  while (next->next != NULL) {
    next = next->next;
    ++size;
  }
  return size;
}

List* allocList(void* first_value, int is_list) {
  List* list = malloc(sizeof(List));
  list->value = first_value;
  list->is_list = is_list;
  list->next = NULL;
  return list;
}

void insertIntoList(List* list, void* child, int is_list) {
  List* next = list;
  while (next->next != NULL)
    next = next->next;

  next->next = allocList(child, is_list);
}

void* getFromList(List* list, int pos) {
  List* next = list;
  while (pos > 0) {
    next = next->next;
    --pos;
  }
  return next->value;
}
