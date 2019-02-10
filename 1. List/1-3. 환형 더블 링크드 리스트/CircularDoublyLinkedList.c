#include "CircularDoublyLinkedList.h"

/*��� ����*/
Node* CDLL_CreateNode(int NewData){
    Node* NewNode = (Node*)malloc(sizeof(Node));

    NewNode->Data = NewData;
    NewNode->PrevNode = NULL;
    NewNode->NextNode = NULL;

    return NewNode;
}

/*��� �Ҹ�*/
void CDLL_DestroyNode(Node* Node) {
    free(Node);
}

/*��� �߰�*/
void CDLL_AppendNode(Node** Head, Node* NewNode) {
    /*��� ��尡 NULL�̶�� ���ο� ��尡 Head*/
    if ( (*Head) == NULL ) {
        *Head = NewNode;
        (*Head)->NextNode = *Head;
        (*Head)->PrevNode = *Head;
    }
    else {
        /*���� ���� ���̿� ���ο� ��带 �߰��Ѵ�*/
        Node* Tail = (*Head)->PrevNode;

        Tail->NextNode->PrevNode = NewNode;
        Tail->NextNode = NewNode;

        NewNode->NextNode = (*Head);
        NewNode->PrevNode = Tail;
    }
}

/*��� ����*/
void CDLL_InsertNode(Node* Current, Node* NewNode) {
    NewNode->NextNode = Current->NextNode;
    NewNode->PrevNode = Current;

    Current->NextNode->PrevNode = NewNode;
    Current->NextNode = NewNode;
}

/*��� ����*/
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

/*��� Ž��*/
Node* CDLL_GetNodeAt(Node* Head, int Location) {
    Node* Current = Head;
    while( Current != NULL && (--Location) >= 0 ) {
        Current = Current->NextNode;
    }
    return Current;
}

/*��� �� ����*/
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
