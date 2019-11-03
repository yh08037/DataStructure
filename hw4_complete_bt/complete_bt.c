#include "complete_bt.h"


Tree* create_bt_from_string(char* str) {
  Tree* bt = (Tree*)malloc(sizeof(Tree));

  if ( bt == NULL || str == NULL )
    return NULL;

  bt->num_node = strlen(str);
  bt->tree = (char*)malloc(sizeof(char)*(bt->num_node+2));

  strcpy(bt->tree+1, str);
  bt->tree[0] = bt->tree[bt->num_node+1] = '\0';

  return bt;
}

int get_right_child(Tree* bt, int index) {
   if (bt->tree[index] != '\0' &&  ((2*index)+1) <= bt->num_node)
      return (2*index)+1;
   return -1;
}


int get_left_child(Tree* bt, int index) {
   if (bt->tree[index] != '\0' && (2*index) <= bt->num_node)
      return 2*index;
   return -1;
}


// Preorder traverasal : 전위순회
void preorder(Tree* bt, int index) {
  if (index <= 0 || bt->tree[index] == '\0') return;

  printf("%c", bt->tree[index]);
  preorder(bt, get_left_child(bt, index));
  preorder(bt, get_right_child(bt, index));
}


// Inorder traversal : 중위순회
void inorder(Tree* bt, int index) {
  if (index <= 0 || bt->tree[index] == '\0') return;

  inorder(bt, get_left_child(bt, index));
  printf("%c", bt->tree[index]);
  inorder(bt, get_right_child(bt, index));
}


// Post traversal : 후위순회
void postorder(Tree* bt, int index) {
  if (index <= 0 || bt->tree[index] == '\0') return;

  postorder(bt, get_left_child(bt, index));
  postorder(bt, get_right_child(bt, index));
  printf("%c", bt->tree[index]);
}

// Breadth-first traversal : 너비 우선 순회
void breadth_first(Tree* bt, int index) {
  while ( index > 0 && bt->tree[index] != '\0' )
    printf("%c", bt->tree[index++]);
}


void destroy_tree(Tree* bt) {
  free(bt->tree);
  free(bt);
}
