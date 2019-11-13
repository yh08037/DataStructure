#include "bst.h"


BST* create_bst(int (*compare)(void*, void*), void (*print)(void*)) {

  BST* bst = (BST*) malloc(sizeof(BST));

  if ( !bst ) return NULL;

  bst->root = NULL;
  bst->compare = compare;
  bst->print = print;

  return bst;
}

void destroy_bst(BST* bst) {
  _free_node(bst->root);
  free(bst);
}

bool insert_data(BST* bst, void* new_data) {

  Node* new_node;
  int is_exist = 0;

  if ( !bst || !new_data ) return false;
  if ( !(new_node = _create_node(new_data)) ) return false;

  bst->root = _insert_node(bst->root, new_node, &is_exist, bst->compare);

  return !is_exist;
}

void* search_data(BST* bst, void* key) {

  Node* found;

  if ( !bst || !key ) return NULL;

  found = _search_node(bst->root, key, bst->compare);

  if ( !found ) return NULL;

  return found->data;
}

bool delete_data(BST* bst, void* key) {

  if ( !bst || !key ) return false;
  if ( !search_data(bst, key) ) return false;

  bst->root = _delete_node(bst->root, key, bst->compare);

  return true;
}


Node* _create_node(void* new_data) {

  Node* new_node = (Node*)malloc(sizeof(Node));

  if ( !new_data || !new_node ) return NULL;

  new_node->data = new_data;
  new_node->left = new_node->right = NULL;

  return new_node;
}

Node* _insert_node(Node* parent, Node* new_node, int* flag, int (*compare)(void*, void*)) {

  if ( !parent ) return new_node;
  if ( !new_node ) return parent;

  if ( compare(parent->data, new_node->data) < 0 )
    parent->right = _insert_node(parent->right, new_node, flag, compare);
  else if ( compare(parent->data, new_node->data) > 0 )
    parent->left = _insert_node(parent->left, new_node, flag, compare);
  else
    *flag = 1;

  return parent;
}

Node* _search_node(Node* node, void* key, int (*compare)(void*, void*)) {

  if ( !node || !key ) return NULL;

  if ( compare(node->data, key) < 0 )
    return _search_node(node->right, key, compare);
  else if ( compare(node->data, key) > 0 )
    return _search_node(node->left, key, compare);
  else
    return node;
}

Node* _delete_node(Node* node, void* key, int (*compare)(void*, void*)) {

  Node* temp;

  if ( !node ) return node;
  else if ( compare(key, node->data) < 0 )
    node->left = _delete_node(node->left, key, compare);
  else if ( compare(key, node->data) > 0 )
    node->right = _delete_node(node->right, key, compare);
  else {
    if ( !node->left && !node->right ) {
      free(node);
      node = NULL;
    }
    else if ( !node->left ) {
      temp = node;
      node = node->right;
      free(temp);
    }
    else if ( !node->right ) {
      temp = node;
      node = node->left;
      free(temp);
    }
    else {
      temp = _find_minimum(node->right);
      node->data = temp->data;
      node->right = _delete_node(node->right, temp->data, compare);
    }
  }

  return node;
}

Node* _find_minimum(Node* node) {

  while ( node->left != NULL )
    node = node->left;

  return node;
}

void _free_node(Node* node) {
  if ( node ) {
    _free_node(node->left);
    _free_node(node->right);
    free(node->data);
    free(node);
  }
}


void preorder(BST* bst) {
  _preorder(bst->root, bst->print);
}

void inorder(BST* bst) {
  _inorder(bst->root, bst->print);
}

void postorder(BST* bst) {
  _postorder(bst->root, bst->print);
}

void breadth_first(BST* bst) {
  Queue* queue;
  Node* node;

  if ( bst && (node = bst->root) && (queue = CreateQueue(0)) ) {
    while ( node ) {
      (bst->print)(node->data);
      if ( node->left )  Enqueue(queue, node->left);
      if ( node->right ) Enqueue(queue, node->right);
      if ( !IsEmptyQueue(queue) ) node = Dequeue(queue);
      else node = NULL;
    }
  }
}

void _preorder(Node* node, void (*print)(void*)) {
  if ( node ) {
    print(node->data);
    _preorder(node->left, print);
    _preorder(node->right, print);
  }
}

void _inorder(Node* node, void (*print)(void*)) {
  if ( node ) {
    _inorder(node->left, print);
    print(node->data);
    _inorder(node->right, print);
  }
}

void _postorder(Node* node, void (*print)(void*)) {
  if ( node ) {
    _postorder(node->left, print);
    _postorder(node->right, print);
    print(node->data);
  }
}
