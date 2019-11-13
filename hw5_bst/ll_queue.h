#ifndef LL_QUEUE_H
#define LL_QUEUE_H

#include <stdlib.h>
#include <stdio.h>


typedef enum {false, true} bool;


typedef struct _qnode {
  void* data;
  struct _qnode* next;
} QNode;


typedef struct {
  int count;
  QNode *front, *rear;
} Queue;


Queue* CreateQueue(int size);
bool Enqueue(Queue* queue, void* item);
void* Dequeue(Queue* queue);
bool IsFullQueue(Queue* queue);
bool IsEmptyQueue(Queue* queue);
void DestroyQueue(Queue* queue);
void PrintQueue(Queue* queue, void (*Print)(void* item));

#endif
