#include <stdio.h>

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


void SLL_AppendNode(Node** Head, Node* NewNode){
    if(*Head == NULL){
        *Head = NewNode;
    }
    else{
        Node* Tail = *Head;
        while(Tail->NextNode != NULL){
            Tail = Tail->NextNode;
        }
        Tail->NextNode = NewNode;
    }
}


Node* SLL_GetNodeAt(Node* Head, int Location){
    Node* Current = Head;

    while(Current!=NULL && (--Location)>=0){
        Current = Current->NextNode;
    }
    /*index out of range의 경우 예외 처리가 없다.*/

    return Current;
}


int main(void){
    Node* List = NULL;
    Node* MyNode = NULL;

    SLL_AppendNode(&List, SLL_CreateNode(117));
    SLL_AppendNode(&List, SLL_CreateNode(199));

    MyNode = SLL_GetNodeAt(List, 1);
    printf("%d", MyNode->Data);

    return 0;
}

