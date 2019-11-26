#include "weighted_digraph.h"


int main( void )
{
  Graph* graph;
  Vertex *start, *v1, *v2;
  Vertex* array[128] = {0};
  char start_char, v1_char, v2_char;
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


  while ( fscanf( fp, "%c %c %d\n", &v1_char, &v2_char, &weight ) == 3 ) {

    if ( !(v1 = array[v1_char]) ) {
      v1 = CreateVertex( v1_char );
      array[v1_char] = v1;
      AddVertex( graph, v1 );
    }

    if ( !(v2 = array[v2_char]) ) {
      v2 = CreateVertex( v2_char );
      array[v2_char] = v2;
      AddVertex( graph, v2 );
    }

    AddEdge( v1, CreateEdge(v1, v2, weight) );
  }

  fclose(fp);

  printf("Minimum spanning tree : \n");
  Prim(graph, start);


  printf("\n");

  printf("Shortest path from %c : \n", start_char);
  Dijkstra(graph, start);

  printf("\n");


  DestroyGraph( graph );

  return 0;
}
