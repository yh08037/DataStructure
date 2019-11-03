#include "arr_stack.h"
// #include "ll_stack.h"
#include <stdio.h>

int main() {

    int i = 0;
    int item;

    Stack* stack;

    if ( !(stack = CreateStack(100)) ) {
      printf("Memory allocation of stack failed. Program terminates.\n");
      return -1;
    }

    printf("Input 10 numbers : ");

    for (i = 0; i < 10; i++) {
        scanf("%d", &item);
        Push(stack, item);
    }

    printf("Reversed : ");
    while( !IsEmptyStack(stack) ) {
        item = Pop(stack);
        printf("%d ", item);
    }
    printf("\n");

    DestroyStack(stack);
    stack = NULL;

    return 0;
}
