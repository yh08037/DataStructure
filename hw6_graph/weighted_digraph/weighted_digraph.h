#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#ifndef WEIGHTED_DIGRAPH_H
#define WEIGHTED_DIGRAPH_H

#include "ll_queue.h"
#include <stdio.h>
#include <stdlib.h>

enum VisitMode { Visited, NotVisited };

typedef char ElementType;

typedef struct tagVertex {
  ElementType       Data;
  int               Visited;
  int               Index;
  struct tagVertex* Next;
  struct tagEdge*   AdjacencyList;
} Vertex;

typedef struct tagEdge {
  struct tagEdge* Next;
  int             Weight;
  Vertex*         From;
  Vertex*         Target;
} Edge;

typedef struct tagGraph {
  Vertex* Vertices;
  int     VertexCount;
} Graph;

Graph* CreateGraph();
void   DestroyGraph( Graph* G );

Vertex* CreateVertex( ElementType Data );
void    DestroyVertex( Vertex* V );

Edge*   CreateEdge( Vertex* From, Vertex* Target, int Weight );
void    DestroyEdge( Edge* E );

void   AddVertex( Graph* G, Vertex* V );
void   AddEdge( Vertex* V, Edge* E );
void   ResetVisited( Graph* G );

void DFS( Vertex* V );
void BFS( Vertex* V );

Vertex** _alloc_Vertex( Vertex* V );
Vertex* _free_Vertex( void* pV );

#endif // WEIGHTED_DIGRAPH_H
