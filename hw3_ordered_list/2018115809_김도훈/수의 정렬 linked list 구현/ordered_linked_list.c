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


void AddNode(OrderedList* list, void* newData) {
  Node *newNode, *cur, *prev;

  if ( list == NULL )
    return;

  if ( !(newNode = (Node*)malloc(sizeof(Node))) )
    return;

  newNode->data = newData;
  newNode->next = NULL;

  if ( IsEmptyList(list) ) {
    list->head = list->pos = newNode;
    list->count++;
    return;
  }

  cur = list->head;
  prev = NULL;

  while ( cur != NULL && (list->compare)(cur->data, newNode->data) < 0 ) {
    prev = cur;
    cur = cur->next;
  }

  if ( prev == NULL ) { // ���� ó���� ����.
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
  Node* tmp;

  if ( list == NULL && list->head == NULL )
    return false;

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
  Node* cur;

  if ( list == NULL )
    return NULL;

   cur = list->head;
  list->pos = NULL;

  while ( cur != NULL && (list->compare)(cur->data, key) != 0 ) {
    list->pos = cur;
    cur = cur->next;
  }

  return cur;
}


void DestroyList(OrderedList* list) {
  Node *cur, *tmp;

  if ( list == NULL )
    return;

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
  Node* cur;

  if ( list == NULL || Print == NULL )
    return;

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
