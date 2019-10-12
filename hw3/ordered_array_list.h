#ifndef ORDERED_ARRAY_LIST_H
#define ORDERED_ARRAY_LIST_H

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


typedef struct {
  void** array;
  int size;
  int head;
  int pos;
  int tail;
} OrderedList;




#endif
