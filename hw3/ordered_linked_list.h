#ifndef ORDERED_LINKED_LIST_H
#define ORDERED_LINKED_LIST_H

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>


typedef struct _node {
  void* data;
  struct _node* next;
} Node;


typedef struct {
  int count;
  Node *head, *pos;
  int (*compare)(void*, void*);
} OrderedList;


OrderedList* CreateList(int (*compare)(void*, void*));
void AddNode(OrderedList* list, void* newData);
bool RemoveNode(OrderedList* list, void* data);
Node* SearchList(OrderedList* list, void* key);
void DestroyList(OrderedList* list);
void TraverseList(OrderedList* list, void (*Print)(void*));
int ListCount(OrderedList* list);
bool IsEmptyList(OrderedList* list);
bool IsFullList(OrderedList* list);


#endif
