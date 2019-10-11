#ifndef LL_QUEUE_H
#define LL_QUEUE_H

#include <stdlib.h>
#include <stdbool.h>


typedef struct _node {
  void* data;
  _node* next;
} Node;


typedef struct {
  int count;
  Node *front, *rear;
} Queue;


Queue* CreateQueue(int size);
bool Enqueue(Queue* queue, void* item);
void* Dequeue(Queue* queue);
bool IsFullQueue(Queue* queue);
bool IsEmptyQueue(Queue* queue);
void DestroyQueue(Queue* queue);

#endif
