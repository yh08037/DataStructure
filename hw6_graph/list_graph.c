#include "list_graph.h"


L_Graph* L_create_graph(int (*compare)(void*, void*));
void     L_insert_vertex(L_Graph* graph, void* data);
int      L_delete_vertex(L_Graph* graph, void* key);
int      L_insert_arc(L_Graph* graph, void* from_key, void* to_key);
int      L_delete_arc(L_Graph* graph, void* from_key, void* to_key);
void     L_depth_first(L_Graph* graph, int (*compare)(void*, void*));
void     L_breadth_first(L_Graph* graph, int (*compare)(void*, void*));
