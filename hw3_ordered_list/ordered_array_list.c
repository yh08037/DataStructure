#include "ordered_array_list.h"


OrderedList* CreateList(int size, int (*compare)(void*, void*)) {
  OrderedList* newList;
  void* newArray;

  if ( !compare || !(newList = (OrderedList*)malloc(sizeof(OrderedList))) )
    return NULL;

  if ( !(newArray = (void**)malloc(sizeof(void*) * size)) ) {
    free(newList);
    return NULL;
  }

  newList->size = size;
  newList->array = newArray;
  newList->tail = newList->pos = -1;
  newList->compare = compare;

  return newList;
}


bool AddNode(OrderedList* list, void* newData) {
  if ( list == NULL || newData == NULL )
    return false;

  if ( IsFullList(list) )
    return false;

  int idx = 0;

  while (idx <= list->tail && (list->compare)(list->array[idx], newData) < 0 )
    idx++;

  for (int i = list->tail; i >= idx; i--)
    (list->array)[i+1] = (list->array)[i];

  (list->array)[idx] = newData;
  list->tail++;

  return true;
}


bool RemoveNode(OrderedList* list, void* data) {
  if ( list == NULL || data == NULL )
    return false;

  if ( IsEmptyList(list) )
    return false;

  if ( !SearchList(list, data) )
    return false;

  int idx = list->pos;

  void* tmp = (list->array)[idx];

  for (int i = idx + 1; i <= list->tail; i++)
    (list->array)[i-1] = (list->array)[i];

  list->tail--;
  free(tmp);

  return true;
}


bool SearchList(OrderedList* list, void* key) {
  if ( list == NULL || key == NULL )
    return -1;

  int i;

  for (i = 0; i <= list->tail; i++)
    if ( (list->compare)(list->array[i], key) == 0 )
      break;

  list->pos = i;

  return (0 <= i && i <= list->tail);
}


void DestroyList(OrderedList* list) {
  if ( list == NULL )
    return;

  for ( int i = 0; i <= list->tail; i++)
    free((list->array)[i]);

  free(list->array);
  free(list);
}


void TraverseList(OrderedList* list, void (*Print)(void*)) {
  if ( list == NULL )
    return;

  for ( int i = 0; i <= list->tail; i++) {
    Print((list->array)[i]);
    printf(", ");
  }

  if ( IsEmptyList(list) )
    printf("\n");
  else
    printf("\b\b  \n");
}


int ListCount(OrderedList* list) {
  return list->tail + 1;
}


bool IsEmptyList(OrderedList* list) {
  return (list->tail == -1);
}


bool IsFullList(OrderedList* list) {
  return (list->tail + 1  == list->size);
}
