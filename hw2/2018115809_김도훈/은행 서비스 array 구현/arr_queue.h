#ifndef ARR_QUEUE_H
#define ARR_QUEUE_H

#ifndef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdlib.h>
#include <stdio.h>

// #include <stdbool.h>
#pragma once

#define false   0
#define true    1

#define bool int

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
