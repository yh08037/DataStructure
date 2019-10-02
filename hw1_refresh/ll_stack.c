#include "ll_stack.h"


Stack* CreateStack(int size) {
    Stack* stack;

    stack = (Stack*)malloc(sizeof(Stack));
    if (stack) {                    // stack�� �����Ҵ��� �����Ͽ���
        stack->count = 0;           // stack�� ������� �ʱ�ȭ �����ְ�
        stack->top   = NULL;
    }

    return stack;                   // stack(������)�� ��ȯ�Ѵ�.
}


bool Push(Stack* stack, void* newData) {
    Node* newNode;

    newNode = (Node*)malloc(sizeof(Node));
    if (!newNode)
        return false;               // newNode�� �����Ҵ��� �����ϸ� false ����.

    newNode->data = newData;        // newNoede�� �����͸� ����
    newNode->next = stack->top;     // ������ top�� newNode�� ������ �ȴ�.
    stack->top    = newNode;        // newNode�� ���ο� top�� �ȴ�.

    (stack->count)++;
    return true;                    // ���������� Push ����.
}


void* Pop(Stack* stack) {
    void* dataOut;
    Node* delNode;

    if (stack->count == 0)              // stack�� ����� ��
        dataOut = NULL;                 // NULL ����.

    else {                              // stack�� ������� ���� ��
        delNode    = stack->top;        // ������ top�� ����Ű�� �����Ϳ�
        dataOut    = stack->top->data;  // ������ top�� �����͸� �����Ѵ�.
        stack->top = stack->top->next;  // ������ top�� ������尡 ���ο� top�� �ȴ�.
        free(delNode);                  // ������ top�� �޸𸮸� �����ϰ�
        (stack->count)--;               // stack�� count�� 1 ���δ�.
    }

    return dataOut;                     // ������ top�� �����͸� ��ȯ�Ѵ�.
}


void* Top(Stack* stack) {
    if (stack->count == 0)          // stack�� ����� ��
        return NULL;                // NULL�� �����Ѵ�.

    else                            // stack�� ������� ���� ��
        return stack->top->data;    // stack�� top�� �����͸� ��ȯ�Ѵ�.
}


bool IsEmptyStack(Stack* stack) {
    return (stack->count == 0);
}


bool IsFullStack(Stack* stack) {    // heap ������ ��� ����Ͽ� �����Ҵ翡 ������ ���� ����
    Node* temp;

    if ((temp = (Node*)malloc(sizeof(Node)))) { // ���ο� ����� �Ҵ��� �������� ��
        free(temp);                             // �� ����� �޸𸮸� �����ϰ�
        return false;                           // false�� �����Ѵ�.
    }
                                                // ���ο� ����� �Ҵ��� �������� ��
    return true;                                // true�� �����Ѵ�.
}


int CountStackItem(Stack* stack) {
    return stack->count;    // stack�� count�� ��ȯ�Ѵ�.
}


void DestroyStack(Stack* stack) {
    if (stack) {            // stack�� NULL�� �ƴ� ��
        ClearStack(stack);  // stack�� ������ �޸𸮸� ��� �����ϰ�
        free(stack);        // stack�� �޸𸮸� �����Ѵ�.
    }
}


void ClearStack(Stack* stack) {
    Node* temp;

    while (stack->top != NULL) {        // stack�� ������ ��� ������ �� ����
        free(stack->top->data);         // ���� top�� data�� �޸𸮸� �����ϰ�

        temp = stack->top;              // ���� top�� �����͸� �����صΰ�
        stack->top = stack->top->next;  // ���� top�� ���� ��尡 ���ο� top�� �ǰ�
        free(temp);                     // �����ص� �����ͷ� ���� top�� �޸𸮸� �����Ѵ�.
    }
}
