#ifndef MATRIX_GRAPH_H
#define MATRIX_GRAPH_H

#include <stdlib.h>

#define MAX_NODE_NUM 256


typedef struct _matrix_graph {
  int   matrix[MAX_NODE_NUM][MAX_NODE_NUM];
  void* data_array[MAX_NODE_NUM];
  int   index;
  int (*compare)(void*, void*);
} M_graph;


M_Graph* M_create_graph(int (*compare)(void*, void*));
void     M_insert_vertex(M_Graph* graph, void* data);
int      M_delete_vertex(M_Graph* graph, void* key);
int      M_insert_arc(M_Graph* graph, void* from_key, void* to_key);
int      M_delete_arc(M_Graph* graph, void* from_key, void* to_key);
void     M_depth_first(M_Graph* graph, int (*compare)(void*, void*));
void     M_breadth_first(M_Graph* graph, int (*compare)(void*, void*));


#endif // MATRIX_GRAPH_H
