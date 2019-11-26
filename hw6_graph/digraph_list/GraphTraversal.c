#include "GraphTraversal.h"

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
  Queue* Queue = CreateQueue();
  Node* Popped;

  printf("%c ", V->Data);
  V->Visited = Visited;

  Enqueue( &Queue, CreateNode( V ) );

  while ( !IsEmpty( Queue ) ) {
    Popped = Dequeue( &Queue );
    V = Popped->data;
    E = V->AdjacencyList;

    while ( E != NULL ) {
      V = E->Target;

      if ( V != NULL && V->Visited == NotVisited ) {
        printf("%c ", V->Data);
        V->Visited = Visited;
        Enqueue( &Queue, CreateNode( V ) );
      }

      E = E->Next;
    }
  }

  DestroyQueue( Queue );
}
