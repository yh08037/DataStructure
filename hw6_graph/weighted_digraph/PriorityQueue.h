#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include <stdio.h>
#include <memory.h>
#include <stdlib.h>

typedef int PriorityType;

typedef struct {
    PriorityType Priority;
    void*        Data;
} Node;

typedef struct {
    Node* array;
    int   max_size;
    int   size;
} PriorityQueue;

PriorityQueue* PQ_Create( int InitialSize );
void           PQ_Destroy( PriorityQueue* PQ );
void           PQ_Enqueue( PriorityQueue* PQ, Node NewData );
void           PQ_Dequeue( PriorityQueue* PQ, Node* Root );
int            PQ_GetParent( int Index );
int            PQ_GetLeftChild( int Index );
void           PQ_SwapNodes( PriorityQueue* PQ, int Index1, int Index2 );
int            PQ_IsEmpty( PriorityQueue* PQ );

#endif
