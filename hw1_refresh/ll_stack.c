#include "ll_stack.h"


Stack* CreateStack(int size) {
    Stack* stack;

    stack = (Stack*)malloc(sizeof(Stack));
    if (stack) {                    // stack의 동적할당이 성공하였을
        stack->count = 0;           // stack의 멤버들을 초기화 시켜주고
        stack->top   = NULL;
    }

    return stack;                   // stack(포인터)을 반환한다.
}


bool Push(Stack* stack, void* newData) {
    Node* newNode;

    newNode = (Node*)malloc(sizeof(Node));
    if (!newNode)
        return false;               // newNode의 동적할당이 실패하면 false 리턴.

    newNode->data = newData;        // newNoede에 데이터를 대입
    newNode->next = stack->top;     // 기존의 top이 newNode의 다음이 된다.
    stack->top    = newNode;        // newNode가 새로운 top이 된다.

    (stack->count)++;
    return true;                    // 정상적으로 Push 종료.
}


void* Pop(Stack* stack) {
    void* dataOut;
    Node* delNode;

    if (stack->count == 0)              // stack이 비었을 때
        dataOut = NULL;                 // NULL 리턴.

    else {                              // stack이 비어있지 않을 때
        delNode    = stack->top;        // 기존의 top을 가리키는 포인터와
        dataOut    = stack->top->data;  // 기존의 top의 데이터를 저장한다.
        stack->top = stack->top->next;  // 기존의 top의 다음노드가 새로운 top이 된다.
        free(delNode);                  // 기존의 top의 메모리를 해제하고
        (stack->count)--;               // stack의 count를 1 줄인다.
    }

    return dataOut;                     // 기존의 top의 데이터를 반환한다.
}


void* Top(Stack* stack) {
    if (stack->count == 0)          // stack이 비었을 때
        return NULL;                // NULL을 리턴한다.

    else                            // stack이 비어있지 않을 때
        return stack->top->data;    // stack의 top의 데이터를 반환한다.
}


bool IsEmptyStack(Stack* stack) {
    return (stack->count == 0);
}


bool IsFullStack(Stack* stack) {    // heap 공간을 모두 사용하여 동적할당에 실패할 때로 정의
    Node* temp;

    if ((temp = (Node*)malloc(sizeof(Node)))) { // 새로운 노드의 할당이 성공했을 떄
        free(temp);                             // 그 노드의 메모리를 해제하고
        return false;                           // false를 리턴한다.
    }
                                                // 새로운 노드의 할당이 실패했을 때
    return true;                                // true를 리턴한다.
}


int CountStackItem(Stack* stack) {
    return stack->count;    // stack의 count를 반환한다.
}


void DestroyStack(Stack* stack) {
    if (stack) {            // stack이 NULL이 아닐 때
        ClearStack(stack);  // stack의 노드들의 메모리를 모두 해제하고
        free(stack);        // stack의 메모리를 해제한다.
    }
}


void ClearStack(Stack* stack) {
    Node* temp;

    while (stack->top != NULL) {        // stack의 노드들이 모두 해제될 때 까지
        free(stack->top->data);         // 기존 top의 data의 메모리를 해제하고

        temp = stack->top;              // 기존 top의 포인터를 저장해두고
        stack->top = stack->top->next;  // 기존 top의 다음 노드가 새로운 top이 되고
        free(temp);                     // 저장해둔 포인터로 기존 top의 메모리를 해제한다.
    }
}
