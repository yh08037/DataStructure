#include "arr_stack.h"

Stack* CreateStack(int size) {
  Stack* newStack;
  Element* newArray;

  if ( !(newStack = (Stack*)malloc(sizeof(Stack))) )
    return NULL;

  if ( !(newArray = (Element*)malloc(sizeof(Element)*size)) ) {
    free(newStack);
    return NULL;
  }

  newStack->data = newArray;
  newStack->size = size;
  newStack->top = -1;

  return newStack;
}


void Push(Stack* stack, Element item) {
  if ( !IsFullStack(stack) )
    stack->data[++stack->top] = item;
}


Element Pop(Stack* stack) {
  if ( !IsEmptyStack(stack) )
    return stack->data[stack->top--];
  return NULL;
}


Element Top(Stack* stack) {
  if ( !IsEmptyStack(stack) )
    return stack->data[stack->top];
  return NULL;
}


void DestroyStack(Stack* stack) {
  ClearStack(stack);
  free(stack);
}


bool IsFullStack(Stack* stack) {
  return stack->top == stack->size - 1;
}


bool IsEmptyStack(Stack* stack) {
  return stack->top == -1;
}


int CountStackItem(Stack* stack) {
  return stack->top + 1;
}


void ClearStack(Stack* stack) {
  stack->top = -1;
}
