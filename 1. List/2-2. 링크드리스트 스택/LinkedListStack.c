#include "LinkedListStack.h"


Node* LLS_CreateNode(char* NewData) {
    /*노드를 힙에 생성*/
    Node* NewNode = (Node*)malloc(sizeof(Node));
    /*전달받은 문자열의 크기만큼 메모리 할당*/
    NewNode->Data = (char*)malloc(sizeof(char)*strlen(NewData));
    /*문자열 복사 - 데이터 자장*/
    strcpy(NewNode->Data, NewData);
    /*다음 노드에 대한 정보 초기화*/
    NewNode->NextNode = NULL;
    /*노드 주소 반환*/
    return NewNode;
}

void LLS_DestroyNode(Node* Node) {
    free(Node->Data);
    free(Node);
}

void LLS_Push(LinkedListStack* Stack, Node* NewNode) {
    if ( Stack->List == NULL ) {
        Stack->List = NewNode;
    }
    else {
        /*최상위 노드를 찾아 NewNode를 연결한다*/
        Node* OldTop = Stack->List;
        while ( OldTop->NextNode != NULL ) {
            OldTop = OldTop->NextNode;
        }
        OldTop->NextNode = NewNode;
    }
    /*Stack의 Top 필드에 새 노드의 주소를 등록한다*/
    Stack->Top = NewNode;
}

Node* LLS_Pop(LinkedListStack* Stack) {
    /*함수가 반환할 최상위 노드*/
    Node* TopNode = Stack->Top;

    if ( Stack->List == Stack->Top ) {
        Stack->List = NULL;
        Stack->Top = NULL;
    }
    else {
        /*새로운 최상위 노드를 Stack의 Top필드에 등록한다*/
        Node* CurrentTop = Stack->List;
        while ( CurrentTop != NULL && CurrentTop->NextNode != Stack->Top ) {
            CurrentTop = CurrentTop->NextNode;
        }
        Stack->Top = CurrentTop;
        CurrentTop->NextNode = NULL;
    }

    return TopNode;
}

Node* LLS_Top(LinkedListStack* Stack) {
    return Stack->Top;
}

int LLS_GetSize(LinkedListStack* Stack) {
    int Count = 0;
    Node* Current = Stack->List;
    while ( Current != NULL ) {
        Current = Current->NextNode;
        Count++;
    }

    return Count;
}

int LLS_IsEmpty(LinkedListStack* Stack) {
    return (Stack->List == NULL);
}

void LLS_CreateStack(LinkedListStack** Stack) {
    /*스택을 힙에 생성*/
    (*Stack) = (LinkedListStack*)malloc(sizeof(LinkedListStack));
    (*Stack)->List = NULL;
    (*Stack)->Top = NULL;
}

void LLS_DestroyStack(LinkedListStack* Stack) {
    while ( !LLS_IsEmpty(Stack) ) {
        Node* Popped = LLS_Pop(Stack);
        LLS_DestroyNode(Popped);
    }
    free(Stack);
}

