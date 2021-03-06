#ifndef ORDERED_ARRAY_LIST_H
#define ORDERED_ARRAY_LIST_H

#ifndef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdlib.h>
#include <stdio.h>

// #include <stdbool.h>
#pragma once

#define false 0
#define true  1

#define bool int


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
