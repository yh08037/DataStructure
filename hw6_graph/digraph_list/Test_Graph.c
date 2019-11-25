#include "Graph.h"


int main( void )
{
    int Mode = 0;
    Graph* graph = CreateGraph();
    LinkedQueue* Queue;

    Vertex* A = CreateVertex( 1 );
    Vertex* B = CreateVertex( 2 );
    Vertex* C = CreateVertex( 3 );
    Vertex* D = CreateVertex( 4 );
    Vertex* E = CreateVertex( 5 );
    Vertex* F = CreateVertex( 6 );
    Vertex* G = CreateVertex( 7 );
    Vertex* H = CreateVertex( 8 );

    AddVertex( graph, A );
    AddVertex( graph, B );
    AddVertex( graph, C );
    AddVertex( graph, D );
    AddVertex( graph, E );
    AddVertex( graph, F );
    AddVertex( graph, G );
    AddVertex( graph, H );

    /*  정점과 정점을 간선으로 잇기 */
    AddEdge( A, CreateEdge(A, B, 0) );
    AddEdge( A, CreateEdge(A, C, 0) );
    AddEdge( B, CreateEdge(B, D, 0) );
    AddEdge( B, CreateEdge(B, E, 0) );
    AddEdge( C, CreateEdge(C, F, 0) );
    AddEdge( E, CreateEdge(E, G, 0) );
    AddEdge( F, CreateEdge(F, G, 0) );
    AddEdge( G, CreateEdge(G, H, 0) );
    AddEdge( D, CreateEdge(D, H, 0) );


    printf("DFS\n");

    DFS( graph->Vertices );

    Queue = LQ_CreateQueue();

    printf("BFS\n");

    BFS(A, Queue);

    LQ_DestroyQueue( Queue );

    DestroyGraph( graph );

    return 0;
}
