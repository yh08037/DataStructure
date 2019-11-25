#include "matrix_graph.h"

M_Graph* M_create_graph(int (*compare)(void*, void*)) {
  M_Graph* new_graph;

  if ( !(new_graph = (M_Graph*)malloc(sizeof(M_Graph))) ) return NULL;

  new_graph->matrix     = {0};
  new_graph->data_array = {0};
  new_graph->index      = -1;
  new_graph->compare    = compare;

  return new_graph;
}

void M_insert_vertex(M_Graph* graph, void* data) {
  int flag = 0, i = 0;

  if ( !graph || !data ) return;

  while ( !(flag = (graph->data_array[i++] == data)) && i <= graph->index );

  graph->data_array[graph->index++] = data;
}

int M_delete_vertex(M_Graph* graph, void* key) {

}

int M_insert_arc(M_Graph* graph, void* from_key, void* to_key);

int M_delete_arc(M_Graph* graph, void* from_key, void* to_key);

void M_depth_first(M_Graph* graph, int (*compare)(void*, void*));

void M_breadth_first(M_Graph* graph, int (*compare)(void*, void*));
