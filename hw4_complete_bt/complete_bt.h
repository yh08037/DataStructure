#ifndef COMPLETE_BT
#define COMPLETE_BT

#ifndef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif // _MSC_VER

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef enum { false, true } bool;

typedef struct {
  char* tree;
  int num_node;
} Tree;


Tree* create_bt_from_string(char* str);
int get_right_child(Tree* bt, int index);
int get_left_child(Tree* bt, int index);
void preorder(Tree* bt, int index);
void inorder(Tree* bt, int index);
void postorder(Tree* bt, int index);
void breadth_first(Tree* bt, int index);
void destroy_tree(Tree* bt);


#endif // COMPLETE_BT
