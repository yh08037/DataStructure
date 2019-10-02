#ifndef ARR_STACK_H
#define ARR_STACK_H

#include <stdlib.h>
#include <stdbool.h>

typedef int Element;

typedef struct {
    Element* stack;
    int size;
    int top;
} Stack;

Stack* CreateStack(int size);
void Push(Stack* pStack, Element item);
Element Pop(Stack* pStack);
Element Top(Stack* pStack);
void DestroyStack(Stack* pStack);
bool IsFullStack(Stack* pStack);
bool IsEmptyStack(Stack* pStack);
int CountStackItem(Stack* pStack);
void ClearStack(Stack* pStack);


#endif // ARR_STACK_H
