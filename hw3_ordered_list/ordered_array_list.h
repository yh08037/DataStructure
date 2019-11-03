#ifndef ORDERED_ARRAY_LIST_H
#define ORDERED_ARRAY_LIST_H

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>


typedef struct {
  int size, tail, pos;
  void** array;
  int (*compare)(void*, void*);
} OrderedList;


OrderedList* CreateList(int size, int (*compare)(void*, void*));
bool AddNode(OrderedList* list, void* newData);
bool RemoveNode(OrderedList* list, void* data);
bool SearchList(OrderedList* list, void* key);
void DestroyList(OrderedList* list);
void TraverseList(OrderedList* list, void (*Print)(void*));
int ListCount(OrderedList* list);
bool IsEmptyList(OrderedList* list);
bool IsFullList(OrderedList* list);


#endif
