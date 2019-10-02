#ifndef LL_STACK_H
#define LL_STACK_H

#include <stdlib.h>
#include <stdbool.h>

typedef char* Element;

typedef struct _node {
    Element data;
    struct _node* next;
} Node;

typedef struct {
    int count;
    Node* top;
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


#endif // LL_STACK_H
