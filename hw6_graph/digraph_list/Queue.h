#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Graph.h"

typedef struct _Node {
  Vertex*       data;
  struct _Node* next;
} Node;

typedef struct {
  Node* front;
  Node* rear;
  int   count;
} Queue;

Queue* CreateQueue();
void   DestroyQueue(Queue* queue);

Node*  CreateNode(Vertex* V);
void   DestroyNode(Node* node);

void   Enqueue(Queue** queue, Node* new_node);
Node*  Dequeue(Queue** queue);

int    IsEmpty(Queue* queue);

#endif
