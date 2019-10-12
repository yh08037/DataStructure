#ifndef LINKED_LIST_H
#define LINKED_LIST_H


typedef struct _node {
  void* data;
  _node* next;
} Node;


typedef struct {
  Node* head;
  Node* pos;
  Node* tail;
  int (*compare)(void* arg1, void* arg2);
} List;



List CreateList();
void AddNode(List list, void* newData);
void RemoveNode(List list, void* data);
void* SearchList(List list, void* key);
void DestroyList(List list);




#endif
