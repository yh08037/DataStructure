#include <stdio.h>
#include <stdlib.h>

typedef struct tagNode{
    int Data;
    struct tagNode* NextNode;
}Node;

Node* SLL_CreateNode(int NewData){
    Node* NewNode = (Node*)malloc(sizeof(Node));

    NewNode->Data = NewData;
    NewNode->NextNode = NULL;

    return NewNode;
}


void SLL_DestroyNode(Node* Node){
    free(Node);
}

