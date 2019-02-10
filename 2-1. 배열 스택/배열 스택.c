#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct tagNode {
    ElementType Data;
} Node;

typedef struct tagArrayStack {
    int Capacity;   // ������ �뷮
    int Top;        // �ֻ��� ����� ��ġ
    Node* Nodes;    // ��� �迭
} ArrayStack;


/*���� ����*/
void AS_CreateStack(ArrayStack** Stack, int Capacity) {
    /*������ ���� ����*/
    (*Stack) = (ArrayStack*)malloc(sizeof(ArrayStack));
    /*���޹��� �뷮��ŭ�� ���迭�� ���� ����*/
    (*Stack)->Nodes = (Node*)malloc(sizeof(Node)*Capacity);
    /*�뷮 �� Top �ʱ�ȭ*/
    (*Stack)->Capacity = Capacity;
    (*Stack)->Top = 0;
}

/*���� �Ҹ�*/
void AS_DestroyStack(ArrayStack* Stack) {
    free(Stack->Nodes);
    free(Stack);
}

/*���� ����*/
void AS_Push(ArrayStack* Stack, ElementType Data) {
    int Position = Stack->Top;
    Stack->Nodes[Position].Data = Data;
    Stack->Top++;
}

/*���� ����*/
ElementType AS_Pop(ArrayStack* Stack) {
    int Position = --(Stack->Top);
    return Stack->Nodes[Position].Data;
}

ElementType AS_Top(ArrayStack* Stack) {
    int Position = Stack->Top - 1;
    return Stack->Nodes[Position].Data;
}

int AS_GetSize(ArrayStack* Stack) {
    return Stack->Top;
}

int AS_IsEmpty(ArrayStack* Stack) {
    return (Stack->Top == 0);
}

int AS_IsFull(ArrayStack* Stack) {
    return (Stack->Capacity == Stack->Top);
}

int main(void) {
    ArrayStack* Stack = NULL;

    AS_CreateStack(&Stack, 5);

    for (int i = 0; i < 4; i++){
        AS_Push(Stack, i);
    }

    for (int i = 0; i < 4; i++){
        AS_Pop(Stack);
    }

    printf("%d", AS_IsEmpty(Stack));

    AS_DestroyStack(Stack);

    return 0;
}











