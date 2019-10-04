#include "arr_stack.h"
// #include "ll_stack.h"
#include <stdio.h>

int main() {

    int i = 0;

    Stack* pStack = CreateStack(100);

    printf("Input 10 numbers : ");

    for (i = 0; i < 10; i++) {
        int item;
        scanf("%d", &item);
        Push(pStack, item);
    }

    printf("Reversed : ");
    while(!IsEmptyStack(pStack)) {
        int item = Pop(pStack);
        printf("%d ", item);
    }
    printf("\n");

    DestroyStack(pStack);
    pStack = NULL;

    return 0;
}
