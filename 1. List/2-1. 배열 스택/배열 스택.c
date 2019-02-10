#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct tagNode {
    ElementType Data;
} Node;

typedef struct tagArrayStack {
    int Capacity;   // 스택의 용량
    int Top;        // 최상위 노드의 위치
    Node* Nodes;    // 노드 배열
} ArrayStack;


/*스택 생성*/
void AS_CreateStack(ArrayStack** Stack, int Capacity) {
    /*스택을 힙에 생성*/
    (*Stack) = (ArrayStack*)malloc(sizeof(ArrayStack));
    /*전달받은 용량만큼의 노드배열을 힙에 생성*/
    (*Stack)->Nodes = (Node*)malloc(sizeof(Node)*Capacity);
    /*용량 및 Top 초기화*/
    (*Stack)->Capacity = Capacity;
    (*Stack)->Top = 0;
}

/*스택 소멸*/
void AS_DestroyStack(ArrayStack* Stack) {
    free(Stack->Nodes);
    free(Stack);
}

/*삽입 연산*/
void AS_Push(ArrayStack* Stack, ElementType Data) {
    int Position = Stack->Top;
    Stack->Nodes[Position].Data = Data;
    Stack->Top++;
}

/*제거 연산*/
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











