#ifndef LIST_GRAPH_H
#define LIST_GRAPH_H

#include <stdlib.h>


typedef struct {
  struct _L_vertex* first;
  int count;
  int (*compare)(void*, void*);
} L_Graph;

typedef struct _L_vertex {
  struct _L_vertex* next_vertex;
  struct _L_arc*    first_arc;
  void* data;
  int   in_degree;
  int   out_degree;
  int   processed;
} L_Vertex;

typedef struct _L_arc {
  struct _L_vertex* destination;
  struct _L_arc*    next_arc;
} L_Arc;


L_Graph* L_create_graph(int (*compare)(void*, void*));
void     L_insert_vertex(L_Graph* graph, void* data);
int      L_delete_vertex(L_Graph* graph, void* key);
int      L_insert_arc(L_Graph* graph, void* from_key, void* to_key);
int      L_delete_arc(L_Graph* graph, void* from_key, void* to_key);
void     L_depth_first(L_Graph* graph, int (*compare)(void*, void*));
void     L_breadth_first(L_Graph* graph, int (*compare)(void*, void*));


#endif // LIST_GRAPH_H
