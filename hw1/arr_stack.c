#include "arr_stack.h"


Stack* CreateStack(int size) {
    Stack* pStack;
    pStack = (Stack*)malloc(sizeof(Stack));
    if (pStack == NULL)
        return NULL;

    pStack->stack = (Element*)malloc(sizeof(Element)*size);
    if (pStack->stack == NULL) {
        free(pStack);
        return NULL;
    }

    pStack->size = size;
    pStack->top = -1;

    return pStack;
}

void Push(Stack* pStack, Element item) {
    if (IsFullStack(pStack))
        return;

    pStack->stack[++pStack->top] = item;
}

Element Pop(Stack* pStack) {
    if (IsEmptyStack(pStack))
        return NULL;

    return pStack->stack[pStack->top--];
}

Element Top(Stack* pStack) {
    if (IsEmptyStack(pStack))
        return NULL;

    return pStack->stack[pStack->top];
}

void DestroyStack(Stack* pStack) {
    free(pStack->stack);
    free(pStack);
}

bool IsFullStack(Stack* pStack) {
    if (pStack->top == pStack->size - 1)
        return true;

    return false;
}

bool IsEmptyStack(Stack* pStack) {
    if (pStack->top == -1)
        return true;

    return false;
}

int CountStackItem(Stack* pStack) {
    return pStack->top + 1;
}

void ClearStack(Stack* pStack) {
    pStack->top = -1;
}
