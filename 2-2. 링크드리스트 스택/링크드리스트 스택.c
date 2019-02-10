#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tagNode {
    char* Data;
    struct tagNode* NextNode;
} Node;

typedef struct tagLinkedListStack {
    Node* List; // ��� ������
    Node* Top;  // ���� ������
} LinkedListStack;


Node* LLS_CreateNode(char* NewData) {
    /*��带 ���� ����*/
    Node* NewNode = (Node*)malloc(sizeof(Node));
    /*���޹��� ���ڿ��� ũ�⸸ŭ �޸� �Ҵ�*/
    NewNode->Data = (char*)malloc(sizeof(char)*strlen(NewData));
    /*���ڿ� ���� - ������ ����*/
    strcpy(NewNode->Data, NewData);
    /*���� ��忡 ���� ���� �ʱ�ȭ*/
    NewNode->NextNode = NULL;
    /*��� �ּ� ��ȯ*/
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
        /*�ֻ��� ��带 ã�� NewNode�� �����Ѵ�*/
        Node* OldTop = Stack->List;
        while ( OldTop->NextNode != NULL ) {
            OldTop = OldTop->NextNode;
        }
        OldTop->NextNode = NewNode;
    }
    /*Stack�� Top �ʵ忡 �� ����� �ּҸ� ����Ѵ�*/
    Stack->Top = NewNode;
}

Node* LLS_Pop(LinkedListStack* Stack) {
    /*�Լ��� ��ȯ�� �ֻ��� ���*/
    Node* TopNode = Stack->Top;

    if ( Stack->List == Stack->Top ) {
        Stack->List = NULL;
        Stack->Top = NULL;
    }
    else {
        /*���ο� �ֻ��� ��带 Stack�� Top�ʵ忡 ����Ѵ�*/
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
    /*������ ���� ����*/
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


int main(void) {


    LinkedListStack* Stack;

    LLS_CreateStack(&Stack);

    LLS_Push(Stack, LLS_CreateNode("abc"));
    LLS_Push(Stack, LLS_CreateNode("def"));
    LLS_Push(Stack, LLS_CreateNode("ghi"));
    LLS_Push(Stack, LLS_CreateNode("jkl"));

    printf("Size : %d, Top : %s\n\n", LLS_GetSize(Stack), LLS_Top(Stack)->Data);

    while ( !LLS_IsEmpty(Stack) ) {
        printf("Popped : %s, ", LLS_Pop(Stack)->Data);

        if( !LLS_IsEmpty(Stack) ){
            printf("Current Top : %s\n", LLS_Top(Stack)->Data);
        }
        else {
            printf("Stack Is Empty.\n");
        }
    }

    LLS_DestroyStack(Stack);

    return 0;
}
