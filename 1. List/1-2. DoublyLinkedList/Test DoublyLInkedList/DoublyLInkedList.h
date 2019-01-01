#ifndef DOUBLY_LINKEDLIST_H
#define DOUBLY_LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct tagNode{
    int Data;
    struct tagNode* PrevNode;
    struct tagNode* NextNode;
}Node;

Node* DLL_CreateNode(int NewData);
void DLL_DestroyNode(Node* Node);
void DLL_AppendNode(Node** Head, Node* NewNode);
Node* DLL_GetNodeAt(Node* Head, int Location);
void DLL_RemoveNode(Node** Head, Node* Remove);
void DLL_InsertAfter(Node* Current, Node* NewNode);
int DLL_GetNodeCount(Node* Head);


#endif // DOUBLY_LINKEDLIST_H
