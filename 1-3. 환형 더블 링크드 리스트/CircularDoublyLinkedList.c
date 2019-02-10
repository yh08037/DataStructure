#include "CircularDoublyLinkedList.h"

/*노드 생성*/
Node* CDLL_CreateNode(int NewData){
    Node* NewNode = (Node*)malloc(sizeof(Node));

    NewNode->Data = NewData;
    NewNode->PrevNode = NULL;
    NewNode->NextNode = NULL;

    return NewNode;
}

/*노드 소멸*/
void CDLL_DestroyNode(Node* Node) {
    free(Node);
}

/*노드 추가*/
void CDLL_AppendNode(Node** Head, Node* NewNode) {
    /*헤드 노드가 NULL이라면 새로운 노드가 Head*/
    if ( (*Head) == NULL ) {
        *Head = NewNode;
        (*Head)->NextNode = *Head;
        (*Head)->PrevNode = *Head;
    }
    else {
        /*헤드와 테일 사이에 새로운 노드를 추가한다*/
        Node* Tail = (*Head)->PrevNode;

        Tail->NextNode->PrevNode = NewNode;
        Tail->NextNode = NewNode;

        NewNode->NextNode = (*Head);
        NewNode->PrevNode = Tail;
    }
}

/*노드 삽입*/
void CDLL_InsertNode(Node* Current, Node* NewNode) {
    NewNode->NextNode = Current->NextNode;
    NewNode->PrevNode = Current;

    Current->NextNode->PrevNode = NewNode;
    Current->NextNode = NewNode;
}

/*노드 제거*/
void CDLL_RemoveNode(Node** Head, Node* Remove) {
    if ( (*Head) == Remove ) {
        (*Head)->NextNode->PrevNode = Remove->PrevNode;
        (*Head)->PrevNode->NextNode = Remove->NextNode;

        (*Head) = Remove->NextNode;

        Remove->PrevNode = NULL;
        Remove->NextNode = NULL;
    }
    else {
        Node* Temp = Remove;

        Remove->NextNode->PrevNode = Temp->PrevNode;
        Remove->PrevNode->NextNode = Temp->NextNode;

        Remove->PrevNode = NULL;
        Remove->NextNode = NULL;
    }
}

/*노드 탐색*/
Node* CDLL_GetNodeAt(Node* Head, int Location) {
    Node* Current = Head;
    while( Current != NULL && (--Location) >= 0 ) {
        Current = Current->NextNode;
    }
    return Current;
}

/*노드 수 세기*/
int CDLL_GetNodeCount(Node* Head) {
    int Count = 0;
    Node* Current = Head;

    while ( Current != NULL ) {
        Current = Current->NextNode;
        Count++;

        if (Current == Head) {
            break;
        }
    }
    return Count;
}

void CDLL_PrintNode(Node* Node) {
    if ( Node->PrevNode == NULL ) {
        printf("Prev : NULL ");
    }
    else {
        printf("Prev : &d ", Node->PrevNode->Data);
    }

    printf("Current : %d ", Node->Data);

    if ( Node->NextNode == NULL ) {
        printf("Next : NULL\n");
    }
    else {
        printf("Next : &d\n", Node->NextNode->Data);
    }
}
