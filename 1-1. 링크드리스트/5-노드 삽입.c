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
    /*인덱스가 범위를 벗어날 경우의 예외 처리가 없다.*/

    return Current;
}

void SLL_RemoveNode(Node** Head, Node* Remove){
    if(*Head==Remove){
        *Head = Remove->NextNode;
    }
    else{
        Node* Current = *Head;
        while(Current!=NULL && Current->NextNode!=Remove){
            Current = Current->NextNode;
        }
        if(Current!=NULL){
            Current->NextNode = Remove->NextNode;
        }
    }
}

void SLL_InsertNode(Node* Current, Node* NewNode){
    NewNode->NextNode = Current->NextNode;
    Current->NextNode = NewNode;
}


int main(void){
    Node* List = NULL;
    Node* Current =NULL;
    Node* MyNode = NULL;

    SLL_AppendNode(&List, SLL_CreateNode(117)); //117
    SLL_AppendNode(&List, SLL_CreateNode(199)); //117, 199
    SLL_AppendNode(&List, SLL_CreateNode(212)); //117, 199, 212

    Current = SLL_GetNodeAt(List, 1);
    MyNode = SLL_CreateNode(327);

    SLL_InsertNode(Current, MyNode); //117, 199, 327, 212

    printf("%d", SLL_GetNodeAt(List, 2)->Data); //327

    return 0;
}

