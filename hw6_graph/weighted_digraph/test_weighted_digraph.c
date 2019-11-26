#include "Graph.h"
#include "GraphTraversal.h"

int main( void )
{
  int Mode  = 0;
  Graph* graph;
  Vertex *start, *end;
  Vertex* array[128] = {0};
  char start_char, end_char, temp;
  int weight;
  FILE* fp;

  if (!(fp = fopen( "input.txt", "r" )) ) {
	printf("file open failed.\n");
	return -1;
  }

  fscanf( fp, "%c\n", &start_char );

  graph = CreateGraph();

  start = CreateVertex( start_char );
  array[start_char] = start;
  AddVertex( graph, start );


  while ( fscanf( fp, "%c %c %d\n", &start_char, &end_char, &weight ) == 3 ) {

    if ( !(start = array[start_char]) ) {
      start = CreateVertex( start_char );
      array[start_char] = start;
      AddVertex( graph, start );
    }

    if ( !(end = array[end_char]) ) {
      end = CreateVertex( end_char );
      array[end_char] = end;
      AddVertex( graph, end );
    }

    AddEdge( start, CreateEdge(start, end, 0) );
  }

  fclose(fp);

  printf("Depth-first traversal : ");
  DFS( graph->Vertices );
  ResetVisited( graph );
  printf("\n");

  printf("Breadth-first traversal : ");
  BFS( graph->Vertices );
  ResetVisited( graph );
  printf("\n");


  DestroyGraph( graph );

  return 0;
}
