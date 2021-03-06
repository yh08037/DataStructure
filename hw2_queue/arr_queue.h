#ifndef ARR_QUEUE_H
#define ARR_QUEUE_H

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>


typedef struct {
  void** array;
  int size;
  int front, rear;
} Queue;


Queue* CreateQueue(int size);
bool Enqueue(Queue* queue, void* item);
void* Dequeue(Queue* queue);
bool IsFullQueue(Queue* queue);
bool IsEmptyQueue(Queue* queue);
void DestroyQueue(Queue* queue);
void PrintQueue(Queue* queue, void (*Print)(void* item));

#endif
