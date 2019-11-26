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
  int i = 0;

  PQNode         StartNode = { 0, start };
  PriorityQueue* PQ        = PQ_Create(10);

  Vertex*  CurrentVertex = NULL;
  Edge*    CurrentEdge   = NULL;

  int*     Weights       = (int*) malloc( sizeof(int) * G->VertexCount );
  Vertex** MSTVertices   = (Vertex**) malloc( sizeof(Vertex*) * G->VertexCount );
  Vertex** Fringes       = (Vertex**) malloc( sizeof(Vertex*) * G->VertexCount );
  Vertex** Precedences   = (Vertex**) malloc( sizeof(Vertex*) * G->VertexCount );
  Graph*   MST           = CreateGraph();

  Vertex *NewVertex, *TargetVertex;
  PQNode Popped, NewNode;
  int FromIndex, ToIndex;

  CurrentVertex = G->Vertices;
  while ( CurrentVertex != NULL ) {
    NewVertex = CreateVertex( CurrentVertex->Data );
    AddVertex( MST, NewVertex);

    Fringes[i]     = NULL;
    Precedences[i] = NULL;
    MSTVertices[i] = NewVertex;
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
           CurrentEdge->Weight < Weights[TargetVertex->Index] ) {
        NewNode.Priority = CurrentEdge->Weight;
        NewNode.Data = TargetVertex;
        PQ_Enqueue ( PQ, NewNode );

        Precedences[TargetVertex->Index] = CurrentEdge->From;
        Weights[TargetVertex->Index]     = CurrentEdge->Weight;
      }

      CurrentEdge = CurrentEdge->Next;
    }
  }

  for ( i=0; i<G->VertexCount; i++ ) {

    if ( Precedences[i] == NULL ) continue;

    FromIndex = Precedences[i]->Index;
    ToIndex   = i;

    AddEdge( MSTVertices[FromIndex],
        CreateEdge( MSTVertices[FromIndex], MSTVertices[ToIndex],   Weights[i] ) );
  }

  PrintGraph( MST );

  free( Fringes );
  free( Precedences );
  free( MSTVertices );
  free( Weights );
  DestroyGraph( MST );

  PQ_Destroy( PQ );
}

void Dijkstra( Graph* G, Vertex* start ) {
  int i = 0;

  PQNode         StartNode = { 0, start };
  PriorityQueue* PQ        = PQ_Create(10);

  Vertex*  CurrentVertex = NULL;
  Edge*    CurrentEdge   = NULL;

  int*     Weights       = (int*) malloc( sizeof(int) * G->VertexCount );
  Vertex** ShortestPathVertices = (Vertex**) malloc( sizeof(Vertex*) * G->VertexCount );
  Vertex** Fringes       = (Vertex**) malloc( sizeof(Vertex*) * G->VertexCount );
  Vertex** Precedences   = (Vertex**) malloc( sizeof(Vertex*) * G->VertexCount );
  Graph*   ShortestPath  = CreateGraph();

  Vertex *NewVertex, *TargetVertex;
  PQNode Popped, NewNode;

  CurrentVertex = G->Vertices;
  while ( CurrentVertex != NULL ) {
    NewVertex = CreateVertex( CurrentVertex->Data );
    AddVertex( ShortestPath, NewVertex);

    Fringes[i]     = NULL;
    Precedences[i] = NULL;
    ShortestPathVertices[i] = NewVertex;
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
           Weights[CurrentVertex->Index] + CurrentEdge->Weight < Weights[TargetVertex->Index] ) {
        NewNode.Priority = CurrentEdge->Weight;
        NewNode.Data = TargetVertex;
        PQ_Enqueue ( PQ, NewNode );

        Precedences[TargetVertex->Index] = CurrentEdge->From;
        Weights[TargetVertex->Index] = Weights[CurrentVertex->Index] + CurrentEdge->Weight;
      }

      CurrentEdge = CurrentEdge->Next;
    }
  }

  for ( i=0; i<G->VertexCount; i++ ) {
    int FromIndex, ToIndex;

    if ( Precedences[i] == NULL ) continue;

    FromIndex = Precedences[i]->Index;
    ToIndex   = i;

    printf("%c %c %d\n", start->Data, ShortestPathVertices[ToIndex]->Data, Weights[i] );
  }

  free( Fringes );
  free( Precedences );
  free( ShortestPathVertices );
  free( Weights );
  DestroyGraph( ShortestPath );

  PQ_Destroy( PQ );
}


void PrintGraph ( Graph* G )
{
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
