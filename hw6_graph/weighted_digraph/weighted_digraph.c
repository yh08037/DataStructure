#include "weighted_digraph.h"


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


void Prim( Graph* G, Vertex* start ) {
  template( G, start, prim );
}

void Dijkstra( Graph* G, Vertex* start ) {
  template( G, start, dijkstra );
}

void template( Graph* G, Vertex* start, int mode ) {
  int i = 0;

  Node           StartNode = { 0, start };
  PriorityQueue* PQ        = PQ_Create(10);

  Vertex*  CurrentVertex = NULL;
  Edge*    CurrentEdge   = NULL;

  int*     Weights       = (int*) malloc( sizeof(int) * G->VertexCount );
  Vertex** new_Vertices  = (Vertex**) malloc( sizeof(Vertex*) * G->VertexCount );
  Vertex** Fringes       = (Vertex**) malloc( sizeof(Vertex*) * G->VertexCount );
  Vertex** Precedences   = (Vertex**) malloc( sizeof(Vertex*) * G->VertexCount );
  Graph*   new_Graph     = CreateGraph();

  Vertex *NewVertex, *TargetVertex;
  Node Popped, NewNode;
  int FromIndex, ToIndex;

  CurrentVertex = G->Vertices;
  while ( CurrentVertex != NULL ) {
    NewVertex = CreateVertex( CurrentVertex->Data );
    AddVertex( new_Graph, NewVertex);

    Fringes[i]     = NULL;
    Precedences[i] = NULL;
    new_Vertices[i] = NewVertex;
    Weights[i]     = MAX_WEIGHT;
    CurrentVertex  = CurrentVertex->Next;
    i++;
  }

  PQ_Enqueue ( PQ, StartNode );

  Weights[start->Index] = 0;

  while( ! PQ_IsEmpty( PQ ) ) {
    PQ_Dequeue(PQ, &Popped);
    CurrentVertex = (Vertex*)Popped.Data;

    Fringes[CurrentVertex->Index] = CurrentVertex;

    CurrentEdge = CurrentVertex->AdjacencyList;

    while ( CurrentEdge != NULL ) {
      TargetVertex = CurrentEdge->Target;

      if ( Fringes[TargetVertex->Index] == NULL &&
           ((mode == prim     && CurrentEdge->Weight < Weights[TargetVertex->Index]) ||
            (mode == dijkstra && Weights[CurrentVertex->Index] + CurrentEdge->Weight < Weights[TargetVertex->Index])) ) {
        NewNode.Priority = CurrentEdge->Weight;
        NewNode.Data = TargetVertex;
        PQ_Enqueue ( PQ, NewNode );

        Precedences[TargetVertex->Index] = CurrentEdge->From;
        switch ( mode ) {
          case prim:     Weights[TargetVertex->Index] = CurrentEdge->Weight; break;
          case dijkstra: Weights[TargetVertex->Index] = Weights[CurrentVertex->Index] + CurrentEdge->Weight; break;
        }
      }

      CurrentEdge = CurrentEdge->Next;
    }
  }

  for ( i=0; i<G->VertexCount; i++ ) {
    if ( Precedences[i] == NULL ) continue;

    FromIndex = Precedences[i]->Index;
    ToIndex   = i;

    switch ( mode ) {
      case prim:
        AddEdge( new_Vertices[FromIndex], CreateEdge( new_Vertices[FromIndex], new_Vertices[ToIndex], Weights[i] ) );
        break;
      case dijkstra:
        printf("%c %c %d\n", start->Data, new_Vertices[ToIndex]->Data, Weights[i] );
        break;
    }
  }

  if ( mode == prim )
    PrintGraph( new_Graph );

  free( Fringes );
  free( Precedences );
  free( new_Vertices );
  free( Weights );
  DestroyGraph( new_Graph );

  PQ_Destroy( PQ );
}


void PrintGraph ( Graph* G ) {
  Vertex* V = NULL;
  Edge*   E = NULL;

  if ( ( V = G->Vertices ) == NULL ) return;

  while ( V != NULL ) {
    if ( (E = V->AdjacencyList) == NULL ) {
      V = V->Next;
      continue;
    }

    while ( E != NULL ) {
      printf("%c %c\n", V->Data, E->Target->Data );
      E = E->Next;
    }

    V = V->Next;
  }
}
