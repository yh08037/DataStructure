#include "ll_queue.h"


Queue* CreateQueue(int size) {
  Queue* queue;

  if ( !(queue = (Queue*)malloc(sizeof(Queue))) )
    return NULL;

  queue->count = 0;
  queue->front = NULL;
  queue->rear  = NULL;

  return queue;
}


bool Enqueue(Queue* queue, void* item) {
  Node* newNode;

  if ( !(newNode = (Node*)malloc(sizeof(Node))) )
    return false;

  newNode->data = item;
  newNode->next = NULL;

  if ( queue->count <= 0 ) {
    queue->front = newNode;
    queue->rear  = newNode;
  }
  else {
    queue->rear->next = newNode;
    queue->rear = newNode;
  }

  queue->count++;

  return true;
}


void* Dequeue(Queue* queue) {
  if ( queue->count <= 0 )
    return NULL;

  Node* front = queue->front;
  void* item  = front->data;

  if ( queue->count == 1 ) {
    queue->front = NULL;
    queue->rear  = NULL;
  }
  else {
    queue->front = queue->front->next;
  }

  queue->count--;
  free(front);

  return item;
}


bool IsFullQueue(Queue* queue) {
  Node* temp;

  if ((temp = (Node*)malloc(sizeof(Node)))) {
    free(temp);
    return false;
  }

  return true;
}


bool IsEmptyQueue(Queue* queue) {
  return (queue->count == 0);
}


void DestroyQueue(Queue* queue) {
  if ( queue == NULL )
    return;

  while ( !(IsEmptyQueue(queue)) ) {
    free(Dequeue(queue));
  }

  free(queue);
}


void PrintQueue(Queue* queue, void (*Print)(void* item)) {
  if ( queue == NULL )
    return;

  Node* cur = queue->front;
  int count = 1;

  printf("(");
  while ( cur != NULL ) {
    Print(cur->data);
    printf("%d, ", count++);
    cur = cur->next;
  }
  if ( IsEmptyQueue(queue) )
    printf(")\n");
  else
    printf("\b\b) \n");
}
