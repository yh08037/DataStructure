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



/*AppendNode() 사용 예시*/

int main(void){

    Node* List = NULL;
    Node* NewNode = NULL;

    NewNode = SLL_CreateNode(117);
    SLL_AppendNode(&List, NewNode);

    NewNode = SLL_CreateNode(199);
    SLL_AppendNode(&List, NewNode);

    printf("%d ", List->Data);
    printf("%d ", List->NextNode->Data);

    return 0;
}



