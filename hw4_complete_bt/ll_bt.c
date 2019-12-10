#include "ll_bt.h"


Node* CreateTree(Node* bt1, Element item, Node* bt2) {
  Node* newNode = (Node*)malloc(sizeof(Node));

  if ( newNode == NULL || item == NULL )
    return NULL;

  newNode->data  = item;
  newNode->left  = bt1;
  newNode->right = bt2;

  return newNode;
}

Node* LeftTree(Node* bt) {
  return bt->left;
}

void* TreeData(Node* bt) {
  return bt->data;
}

Node* RightTree(Node* bt) {
  return bt->right;
}

bool IsEmpty(Node* bt) {
  return bt == NULL;
}

void DestroyTree(Node* bt) {
  if ( bt == NULL ) return;
  if ( bt->left ) DestroyTree(bt->left);
  if ( bt->right ) DestroyTree(bt->right);
  free(bt);
}

Node* CopyTree(Node* bt) {
  if( root == NULL ) return NULL;
  return CreateTree(CopyTree(root->left), root->data, CopyTree(root->right));
}

void Preorder(Node* bt) {
  if ( bt == NULL ) return;
  printf("%c ", bt);
  Preorder(bt->left);
  Preorder(bt->right);
}

void Inorder(Node* bt) {
  if ( bt == NULL ) return;
  Inorder(bt->left);
  printf("%c ", bt);
  Inorder(bt->right);
}

void Postorder(Node* bt) {
    if ( bt == NULL ) return;
    Postorder(bt->left);
    Postorder(bt->right);
    printf("%c ", bt);
}

void BreadthFirst(Node* bt) {

}
