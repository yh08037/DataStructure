#ifndef LINKEDLIST_STACK_H
#define LINKEDLIST_STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tagNode {
    char* Data;
    struct tagNode* NextNode;
} Node;

typedef struct tagLinkedListStack {
    Node* List; // ��� ������
    Node* Top;  // ���� ������
} LinkedListStack;

Node* LLS_CreateNode(char* NewData);
void LLS_DestroyNode(Node* Node);
void LLS_Push(LinkedListStack* Stack, Node* NewNode);
Node* LLS_Pop(LinkedListStack* Stack);
Node* LLS_Top(LinkedListStack* Stack);
int LLS_GetSize(LinkedListStack* Stack);
int LLS_IsEmpty(LinkedListStack* Stack);
void LLS_CreateStack(LinkedListStack** Stack);
void LLS_DestroyStack(LinkedListStack* Stack);


#endif // LINKEDLIST_STACK_H
