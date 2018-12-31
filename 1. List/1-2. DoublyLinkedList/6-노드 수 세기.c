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

/*노드 탐색*/
Node* DLL_GetNodeAt(Node* Head, int Location){
    Node* Current = Head;
    \
    while(Current!=NULL && (--Location)>=0){
        Current = Current->NextNode;
    }

    return Current;
}

/*노드 삭제*/
void DLL_RemoveNode(Node** Head, Node* Remove){
    if(*Head == Remove){
        *Head = Remove->NextNode;
        if(*Head != NULL){
            (*Head)->PrevNode = NULL;
        }
        Remove->PrevNode = NULL;
        Remove->NextNode = NULL;
    }
    else{
        Node* Temp = Remove;

        Remove->PrevNode->NextNode = Temp->NextNode;
        if(Remove->NextNode != NULL){
            Remove->NextNode->PrevNode = Temp->PrevNode;
        }
        Remove->PrevNode = NULL;
        Remove->NextNode = NULL;
    }
}

/*노드 삽입*/
void DLL_InsertAfter(Node* Current, Node* NewNode){
    NewNode->NextNode = Current->NextNode;
    NewNode->PrevNode = Current;

    if(Current->NextNode != NULL){
        Current->NextNode->PrevNode = NewNode;
    }
    Current->NextNode = NewNode;
}

int DLL_GetNodeCount(Node* Head){
    int Count = 0;
    Node* Current = Head;

    while(Current != NULL){
        Current = Current->NextNode;
        Count++;
    }

    return Count;
}


int main(void){
    Node* List = NULL;

    DLL_AppendNode(&List, DLL_CreateNode(117)); //117
    DLL_AppendNode(&List, DLL_CreateNode(119)); //117, 119
    DLL_AppendNode(&List, DLL_CreateNode(234)); //117, 119, 234
    DLL_RemoveNode(&List, DLL_GetNodeAt(List, 1)); // 117, 234
    DLL_InsertAfter(DLL_GetNodeAt(List, 0), DLL_CreateNode(215)); //117, 215, 234

    int Length = DLL_GetNodeCount(List);
    Node* Current;

    for(int i=0; i<Length; i++){
        Current = DLL_GetNodeAt(List, i);
        printf("%d ", Current->Data); //117, 215, 234
    }

    return 0;
}
