#include "Queue.h"

Queue* CreateQueue() {
  Queue* queue = (Queue*)malloc(sizeof(Queue));

  queue->front = NULL;
  queue->rear  = NULL;
  queue->count = 0;

  return queue;
}

void DestroyQueue(Queue* queue) {
  Node* Popped;

  while ( !IsEmpty(queue) ) {
    Popped = Dequeue(&queue);
    DestroyNode(Popped);
  }

  free(queue);
}

Node* CreateNode(Vertex* V) {
  Node* NewNode = (Node*)malloc(sizeof(Node));

  NewNode->next = NULL;
  NewNode->data = V;

  return NewNode;
}

void DestroyNode(Node* node) {
  free(node->data);
  free(node);
}

void Enqueue(Queue** queue, Node* NewNode) {
  if ( (*queue)->front == NULL ) {
    (*queue)->front = NewNode;
    (*queue)->rear  = NewNode;
    (*queue)->count++;
  }
  else {
    (*queue)->rear->next = NewNode;
    (*queue)->rear = NewNode;
    (*queue)->count++;
  }
}

Node* Dequeue(Queue** queue) {
  Node* front = (*queue)->front;

  if ( (*queue)->front->next == NULL ) {
    (*queue)->front = NULL;
    (*queue)->rear  = NULL;
  }
  else
    (*queue)->front = (*queue)->front->next;

  (*queue)->count--;

  return front;
}

int IsEmpty(Queue* queue) {
    return (queue->front == NULL);
}
