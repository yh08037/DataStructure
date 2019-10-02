#include "ll_stack.h"


Stack* CreateStack(int size) {
    Stack* pStack = (Stack*)malloc(sizeof(Stack));
    if (!pStack)
        return NULL;

    pStack->count = 0;
    pStack->top = NULL;

    return pStack;
}

void Push(Stack* pStack, Element item) {
    Node* pNewNode = (Node*)malloc(sizeof(Node));
    if (pNewNode == NULL)
        return;

    pNewNode->data = item;
    pNewNode->next = pStack->top;
    pStack->top = pNewNode;
    (pStack->count)++;
}

Element Pop(Stack* pStack) {
    if (IsEmptyStack(pStack))
        return NULL;

    Node* temp = pStack->top;
    Element data_out = pStack->top->data;
    pStack->top = pStack->top->next;
    free(temp);
    (pStack->count)--;
    return data_out;
}

Element Top(Stack* pStack) {
    if (IsEmptyStack(pStack))
        return NULL;

    return pStack->top->data;
}

void DestroyStack(Stack* pStack) {
    ClearStack(pStack);
    free(pStack);
}


bool IsFullStack(Stack* pStack) {
    return false;
}


bool IsEmptyStack(Stack* pStack) {
    if (pStack->count == 0)
        return true;
    else
        return false;
}

int CountStackItem(Stack* pStack) {
    return pStack->count;
}

void ClearStack(Stack* pStack) {
    Node* currentNode = pStack->top;
    Node* nextNode = currentNode->next;

    while (nextNode != NULL) {
        nextNode = currentNode->next;
        free(currentNode);
        currentNode = NULL;
    }

    pStack->count = 0;
}
