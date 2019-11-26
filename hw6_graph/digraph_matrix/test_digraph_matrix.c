#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif


#include "digraph_matrix.h"


int main() {
  Graph* graph;
  char start, v1, v2;
  FILE* fp;

  if ( (fp = fopen( "input.txt", "r" )) == NULL ) {
		printf("file open failed.\n");
		return -1;
  }

  fscanf( fp, "%c\n", &start );

  graph = CreateGraph();

  while ( fscanf( fp, "%c %c\n", &v1, &v2 ) == 2 ) {
    AddEdge( graph, v1, v2 );
  }

  fclose(fp);


  printf("Depth-first traversal : ");
  DFS( graph, start );
  ResetVisited( graph );
  printf("\n");

  printf("Breadth-first traversal : ");
  BFS( graph, start );
  ResetVisited( graph );
  printf("\n");


  DestroyGraph( graph );
}
