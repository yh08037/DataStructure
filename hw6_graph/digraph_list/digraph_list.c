#include "Graph.h"

Graph* CreateGraph() {
  Graph* graph = (Graph*)malloc( sizeof( Graph ) );
  graph->Vertices = NULL;
  graph->VertexCount = 0;

  return graph;
}

void DestroyGraph( Graph* G ) {
  Vertex* Vertices;

  while ( G->Vertices ) {
    Vertices = G->Vertices->Next;
    DestroyVertex( G->Vertices );
    G->Vertices = Vertices;
  }

  free( G );
}

Vertex* CreateVertex( ElementType Data ) {
  Vertex* V = (Vertex*)malloc( sizeof( Vertex ) );

  V->Data = Data;
  V->Next = NULL;
  V->AdjacencyList = NULL;
  V->Visited = NotVisited;
  V->Index = -1;

  return V;
}

void DestroyVertex( Vertex* V ) {
  Edge* edge;

  while ( V->AdjacencyList != NULL ) {
    edge = V->AdjacencyList->Next;

    DestroyEdge ( V->AdjacencyList );

    V->AdjacencyList = edge;
  }

  free( V );
}

Edge* CreateEdge( Vertex* From, Vertex* Target, int Weight ) {
  Edge* E   = (Edge*)malloc( sizeof( Edge ) );
  E->From   = From;
  E->Target = Target;
  E->Next   = NULL;
  E->Weight = Weight;

  return E;
}

void DestroyEdge( Edge* E ) {
  free( E );
}

void AddVertex( Graph* G, Vertex* V ) {
  Vertex* VertexList = G->Vertices;

  if ( !VertexList )
    G->Vertices = V;
  else {
    while ( VertexList->Next )
        VertexList = VertexList->Next;

    VertexList->Next = V;
  }

  V->Index = G->VertexCount++;
}

void AddEdge( Vertex* V, Edge* E ) {
  Edge* AdjacencyList;

  if ( !V->AdjacencyList )
    V->AdjacencyList = E;
  else {
    AdjacencyList = V->AdjacencyList;

    while ( AdjacencyList->Next )
      AdjacencyList = AdjacencyList->Next;

    AdjacencyList->Next = E;
  }
}

void ResetVisited( Graph* G ) {
  Vertex* V = NULL;
  Edge*   E = NULL;

  if ( ( V = G->Vertices ) == NULL )
      return;

  while ( V != NULL ) {
    V->Visited = NotVisited;

    if ( (E = V->AdjacencyList) == NULL ) {
      V = V->Next;
      continue;
    }

    while ( E != NULL ) {
      E->Target->Visited = NotVisited;
      E = E->Next;
    }

    V = V->Next;
  }
}

void DFS( Vertex* V ) {
  Edge* E = NULL;

  printf("%c ", V->Data);
  V->Visited = Visited;

  for ( E = V->AdjacencyList; E != NULL; E = E->Next ) {
    if ( E->Target->Visited == NotVisited )
      DFS( E->Target );
  }
}

void BFS( Vertex* V ) {
  Edge* E = NULL;
  Queue* queue = CreateQueue();

  printf("%c ", V->Data);
  V->Visited = Visited;

  Enqueue( queue, _alloc_Vertex( V ) );

  while ( !IsEmptyQueue( queue ) ) {
    V = _free_Vertex(Dequeue( queue ));
    E = V->AdjacencyList;

    while ( E != NULL ) {
      V = E->Target;

      if ( V != NULL && V->Visited == NotVisited ) {
        printf("%c ", V->Data);
        V->Visited = Visited;
        Enqueue( queue, _alloc_Vertex( V ) );
      }

      E = E->Next;
    }
  }

  DestroyQueue( queue );
}

Vertex** _alloc_Vertex( Vertex* V ) {
  Vertex** pV = (Vertex**)malloc(sizeof(Vertex*));
  *pV = V;
  return pV;
}

Vertex* _free_Vertex( void* pV ) {
  Vertex* V = *(Vertex**)pV;
  free(pV);
  return V;
}
