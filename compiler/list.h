#ifndef LIST_INCLUDED
#define LIST_INCLUDED

#define List struct List_t
struct List_t {
  void* value;
  int is_list;
  List* next;
};

extern unsigned getListSize(List*);
extern List* allocList(void*, int);
extern void insertIntoList(List*, void*, int);
extern void* getFromList(List*, int);
#endif
