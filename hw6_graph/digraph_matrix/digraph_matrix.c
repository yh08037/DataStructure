#include "digraph_matrix.h"


Graph* CreateGraph( void ) {
  return (Graph*) calloc( MAX__NUM, sizeof(Graph) );
}

void AddEdge( Graph* graph, int start, int end ) {
  (graph->matrix)[start][end] = 1;
}

void DFS( Graph* graph, int start ) {
  int i;

  printf("%c ", start);
  (graph->visited)[start] = 1;

  for ( i = 0; i < MAX__NUM; i++ ) {
    if ( (graph->visited)[i] == 0 && (graph->matrix)[start][i] == 1 )
    DFS( graph, i );
  }
}

void BFS( Graph* graph, int start ) {
  Queue* queue = CreateQueue();
  int i, *data;

  Enqueue(queue, _alloc_int(start));
  printf("%c ", start);

  while ( !IsEmptyQueue(queue) ) {
    start = _free_int(Dequeue(queue));

    for ( i = start; i < MAX__NUM; i++ ) {
      if ( !(graph->visited)[i] && (graph->matrix)[start][i] == 1) {
        (graph->visited)[i] = 1;
        Enqueue(queue, _alloc_int(i));
        printf("%c ", i);
      }
    }
  }

  DestroyQueue( queue );
}

void ResetVisited( Graph* graph ) {
  int i;

  for ( i = 0; i < MAX__NUM; i++ )
    (graph->visited)[i] = 0;
}

void DestroyGraph( Graph* graph ) {
  free(graph);
}

int* _alloc_int( int num ) {
  int* data = (int*)malloc(sizeof(int));
  *data = num;

  return data;
}

int _free_int( void* data ) {
  int num = *(int*)(data);
  free(data);

  return num;
}
