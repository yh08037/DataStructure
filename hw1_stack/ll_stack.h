#ifndef LL_STACK_H
#define LL_STACK_H

#include <stdlib.h>
#include <stdbool.h>


typedef struct node {
    void* data;
    struct node* next;
} Node;

typedef struct {
    int count;
    Node* top;
} Stack;


Stack* CreateStack(int size);
bool Push(Stack* stack, void* newData);
void* Pop(Stack* stack);

void* Top(Stack* stack);
void DestroyStack(Stack* stack);
bool IsFullStack(Stack* stack);
bool IsEmptyStack(Stack* stack);
int CountStackItem(Stack* stack);
void ClearStack(Stack* stack);

#endif
