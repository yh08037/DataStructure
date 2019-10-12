#include "ordered_linked_list.h"

OrderedList* CreateList(int (*compare)(void* arg1, void* arg2)) {
  OrderedList* newList;

  if ( !(newList = (OrderedList*)malloc(sizeof(OrderedList))) )
    return NULL;

  newList->count = 0;
  newList->head = newList->pos = NULL;
  newList->compare = compare;

  return newList;
}


Node* GenerateNode(void* newData) {
  Node* newNode;
  if ( !(newNode = (Node*)malloc(sizeof(Node))) )
    return NULL;

  newNode->data = newData;
  newNode->next = NULL;

  return newNode;
}


void AddNode(OrderedList* list, void* newData) {
  if ( list == NULL )
    return;

  Node* newNode = GenerateNode(newData);

  if ( IsEmptyList(list) ) {
    list->head = list->pos = newNode;
    list->count++;
    return;
  }

  Node* cur = list->head;
  Node* prev = NULL;

  while ( cur != NULL && (list->compare)(cur->data, newNode->data) < 0 ) {
    prev = cur;
    cur = cur->next;
  }

  if ( prev == NULL ) { // 가장 처음에 들어간다.
    newNode->next = list->head;
    list->head = newNode;
  }
  else {
    prev->next = newNode;
    newNode->next = cur;
  }

  list->count++;
}


bool RemoveNode(OrderedList* list, void* data) {
  if ( list == NULL && list->head == NULL )
    return false;

  Node* tmp;

  if ( (tmp = SearchList(list, data)) == NULL)
    return false;

  if ( list->pos == NULL )  // when remove node is head
    list->head = tmp->next;
  else
    list->pos->next = tmp->next;

  free(tmp->data);
  free(tmp);

  list->count--;

  return true;
}


Node* SearchList(OrderedList* list, void* key) {
  if ( list == NULL )
    return NULL;

  Node* cur = list->head;
  list->pos = NULL;

  while ( cur != NULL && (list->compare)(cur->data, key) != 0 ) {
    list->pos = cur;
    cur = cur->next;
  }

  return cur;
}


void DestroyList(OrderedList* list) {
  if ( list == NULL )
    return;

  Node *cur, *tmp;
  cur = list->head;

  while ( cur != NULL ) {
    tmp = cur;
    cur = cur->next;
    free(tmp->data);
    free(tmp);
  }

  free(list);
  list = NULL;
}


void TraverseList(OrderedList* list, void (*Print)(void* data)) {
  if ( list == NULL || Print == NULL )
    return;

  Node* cur;

  for (cur = list->head; cur != NULL; cur = cur->next) {
    Print(cur->data);
    printf(", ");
  }
  if ( IsEmptyList(list) )
    printf("\n");
  else
    printf("\b\b  \n");
}


int ListCount(OrderedList* list) {
  return list->count;
}


bool IsEmptyList(OrderedList* list) {
  return (list->count == 0);
}


bool IsFullList(OrderedList* list) {
  Node* temp;

  if ((temp = (Node*)malloc(sizeof(Node)))) {
    free(temp);
    return false;
  }

  return true;
}
