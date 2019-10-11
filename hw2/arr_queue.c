#include "arr_queue.h"


Queue* CreateQueue(int size) {
  Queue* queue;

  if ( !(queue = (Queue*)malloc(sizeof(Queue))) )
    return NULL;

  if ( !(queue->array = (void**)malloc(sizeof(void*)*size)) ) {
    free(queue);
    return NULL;
  }

  queue->size  = size;
  queue->front = 0;
  queue->rear  = 0;

  return queue;
}


bool Enqueue(Queue* queue, void* item) {
  if ( IsFullQueue(queue) )
    return false;
  queue->rear = (queue->rear + 1) % queue->size;
  queue->array[queue->rear] = item;

  return true;
}


void* Dequeue(Queue *queue) {
  if( IsEmptyQueue(queue) )
    return NULL;
  else {
    queue->front = (queue->front + 1) % queue->size;
    return queue->array[queue->front];
  }
}


bool IsFullQueue(Queue* queue) {
  return ((queue->rear + 1) % queue->size == queue->front);
}


bool IsEmptyQueue(Queue* queue) {
  return (queue->front == queue->rear);
}


void DestroyQueue(Queue* queue) {
  if ( queue != NULL ) {
    free(queue->array);
    free(queue);
    queue = NULL;
  }
}
