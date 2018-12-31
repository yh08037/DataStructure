#include <stdio.h>
#include <stdlib.h>

typedef struct tagNode{
    int Data;
    struct tagNode* PrevNode;
    struct tagNode* NextNode;
}Node;

/*노드 생성*/
Node* DLL_CreateNode(int NewData){
    Node* NewNode = (Node*)malloc(sizeof(Node));

    NewNode->Data = NewData;
    NewNode->PrevNode = NULL;
    NewNode->NextNode = NULL;

    return NewNode;
}

/*노드 소멸*/
void DLL_DestroyNode(Node* Node){
    free(Node);
}
