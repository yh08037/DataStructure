#include "matrix_graph.h"

M_Graph* M_create_graph(int (*compare)(void*, void*));
void     M_insert_vertex(M_Graph* graph, void* data);
int      M_delete_vertex(M_Graph* graph, void* key);
int      M_insert_arc(M_Graph* graph, void* from_key, void* to_key);
int      M_delete_arc(M_Graph* graph, void* from_key, void* to_key);
void     M_depth_first(M_Graph* graph, int (*compare)(void*, void*));
void     M_breadth_first(M_Graph* graph, int (*compare)(void*, void*));
