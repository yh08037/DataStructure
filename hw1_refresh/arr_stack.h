#ifndef ARR_STACK_H
#define ARR_STACK_H

#include <stdlib.h>
#include <stdbool.h>

typedef char* Element;

typedef struct {
  Element* data;
  int size;
  int top;
} Stack;

Stack CreateStack(int size);
void Push(Stack* stack, Element item);
Element Pop(Stack* stack);
Element Top(Stack* stack);
void DestroyStack(Stack* stack);
bool IsFullStack(Stack* Stack);
bool IsEmptyStack(Stack* stack);
int CountStackItem(Stack* stack);
void ClearStack(Stack* stack);

#endif
