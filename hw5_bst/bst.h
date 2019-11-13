#ifndef BST_H
#define BST_H

#ifndef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif // _MSC_VER


#include <stdlib.h>
#include <stdio.h>
#include "ll_queue.h"


// typedef enum {false, true} bool;


typedef struct _node {
  void* data;
  struct _node *left, *right;
} Node;

typedef struct {
  Node *root;
  int (*compare)(void*, void*);
  void (*print)(void*);
} BST;


BST*  create_bst(int (*compare)(void*, void*), void (*print)(void*));
void  destroy_bst(BST* bst);

bool  insert_data(BST* bst, void* new_data);
void* search_data(BST* bst, void* key);
bool  delete_data(BST* bst, void* key);

Node* _create_node(void* new_data);
Node* _insert_node(Node* parent, Node* new_node, int* flag, int (*compare)(void*, void*));
Node* _search_node(Node* node, void* key, int (*compare)(void*, void*));
Node* _delete_node(Node* node, void* key, int (*compare)(void*, void*));
Node* _find_minimum(Node* node);
void  _free_node(Node* node);

void  preorder(BST* bst);
void  inorder(BST* bst);
void  postorder(BST* bst);
void breadth_first(BST* bst);

void  _preorder(Node* node, void (*print)(void*));
void  _inorder(Node* node, void (*print)(void*));
void  _postorder(Node* node, void (*print)(void*));


#endif // BST_H
