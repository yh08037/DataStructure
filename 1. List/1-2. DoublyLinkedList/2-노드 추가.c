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

/*노드 추가*/
void DLL_AppendNode(Node** Head, Node* NewNode){
    if(*Head == NULL){
        *Head = NewNode;
    }
    else{
        Node* Tail = *Head;
        while(Tail->NextNode != NULL){
            Tail = Tail->NextNode;
        }
        Tail->NextNode = NewNode;
        NewNode->PrevNode = Tail;
    }
}

int main(void){
    Node* List = NULL;

    DLL_AppendNode(&List, DLL_CreateNode(117));
    DLL_AppendNode(&List, DLL_CreateNode(119));

    printf("%d %d %d", List->Data, List->NextNode->Data, List->NextNode->PrevNode->Data);

    return 0;
}
