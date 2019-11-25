#include "Graph.h"

Graph* CreateGraph()
{
    Graph* graph = (Graph*)malloc( sizeof( Graph ) );
    graph->Vertices = NULL;
    graph->VertexCount = 0;

    return graph;
}

void DestroyGraph( Graph* G )
{
    while ( G->Vertices != NULL )
    {
        Vertex* Vertices = G->Vertices->Next;
        DestroyVertex( G->Vertices );
        G->Vertices = Vertices;
    }

    free( G );
}

Vertex* CreateVertex( ElementType Data )
{
    Vertex* V = (Vertex*)malloc( sizeof( Vertex ) );

    V->Data = Data;
    V->Next = NULL;
    V->AdjacencyList = NULL;
    V->Visited = NotVisited;
    V->Index = -1;

    return V;
}

void DestroyVertex( Vertex* V )
{
    while ( V->AdjacencyList != NULL )
    {
        Edge* Edge = V->AdjacencyList->Next;

        DestroyEdge ( V->AdjacencyList );

        V->AdjacencyList = Edge;
    }

    free( V );
}

Edge*   CreateEdge( Vertex* From, Vertex* Target, int Weight )
{
    Edge* E   = (Edge*)malloc( sizeof( Edge ) );
    E->From   = From;
    E->Target = Target;
    E->Next   = NULL;
    E->Weight = Weight;

    return E;
}

void    DestroyEdge( Edge* E )
{
    free( E );
}

void AddVertex( Graph* G, Vertex* V )
{
    Vertex* VertexList = G->Vertices;

    if ( VertexList == NULL )
    {
        G->Vertices = V;
    }
    else
    {
        while ( VertexList->Next != NULL )
            VertexList = VertexList->Next;

        VertexList->Next = V;
    }

    V->Index = G->VertexCount++;
}

void AddEdge( Vertex* V, Edge* E )
{
    if ( V->AdjacencyList == NULL )
    {
        V->AdjacencyList = E;
    }
    else
    {
        Edge* AdjacencyList = V->AdjacencyList;

        while ( AdjacencyList->Next != NULL )
            AdjacencyList = AdjacencyList->Next;

        AdjacencyList->Next = E;
    }
}

void PrintGraph ( Graph* G )
{
    Vertex* V = NULL;
    Edge*   E = NULL;

    if ( ( V = G->Vertices ) == NULL )
        return;

    while ( V != NULL )
    {
        printf( "%c : ", V->Data );

        if ( (E = V->AdjacencyList) == NULL ) {
            V = V->Next;
            printf("\n");
            continue;
        }

        while ( E != NULL )
        {
            printf("%c[%d] ", E->Target->Data, E->Weight );
            E = E->Next;
        }

        printf("\n");

        V = V->Next;
    }

    printf("\n");
}


void DFS( Vertex* V )
{
    Edge* E = NULL;

    printf("%d ", V->Data);

    V->Visited = Visited;

    E = V->AdjacencyList;

    while ( E != NULL )
    {
        if ( E->Target != NULL && E->Target->Visited == NotVisited )
            DFS( E->Target );

        E = E->Next;
    }
}

void BFS( Vertex* V, LinkedQueue* Queue )
{
    Edge* E = NULL;

    printf("%d ", V->Data);
    V->Visited = Visited;

    /*  큐에 노드 삽입. */
    LQ_Enqueue( &Queue, LQ_CreateNode( V ) );

    while ( !LQ_IsEmpty( Queue ) )
    {
        Node* Popped = LQ_Dequeue( &Queue );
        V = Popped->Data;
        E = V->AdjacencyList;

        while ( E != NULL )
        {
            V = E->Target;

            if ( V != NULL && V->Visited == NotVisited )
            {
                printf("%d ", V->Data);
                V->Visited = Visited;
                LQ_Enqueue( &Queue, LQ_CreateNode( V ) );
            }

            E = E->Next;
        }
    }
}
