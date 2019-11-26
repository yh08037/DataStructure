#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#ifndef DIGRAPH_MATRIX_H
#define DIGRAPH_MATRIX_H

#include "ll_queue.h"
#include <stdlib.h>
#include <stdio.h>

#define MAX__NUM 128


typedef struct {
  int  matrix[MAX__NUM][MAX__NUM];
  int  visited[MAX__NUM];
} Graph;

Graph* CreateGraph( void );
void AddEdge( Graph* graph, int start, int end );
void DFS( Graph* graph, int start );
void BFS( Graph* graph, int start );
void ResetVisited( Graph* graph );
void DestroyGraph( Graph* graph );

int* _alloc_int( int num );
int _free_int( void* data );


#endif // DIGRAPH_MATRIX_H
