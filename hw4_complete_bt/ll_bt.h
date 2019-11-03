#ifndef COMPLETE_BT
#define COMPLETE_BT

#ifndef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif // _MSC_VER

#include <stdio.h>
#include <stdlib.h>


typedef enum { false, true } bool;

typedef char Element;

typedef struct _node {
  Element data;
  struct _node *left, *right;
} Node;


Node* CreateTree(Node* bt1, Element item, Node* bt2);
Node* LeftTree(Node* bt);
void* TreeData(Node* bt);
Node* RightTree(Node* bt);
bool  IsEmpty(Node* bt);
void  DestroyTree(Node* bt);
Node* CopyTree(Node* bt);

void Preorder(Node* bt);
void Inorder(Node* bt);
void Postorder(Node* bt);
void BreadthFirst(Node* bt);

#endif // COMPLETE_BT
