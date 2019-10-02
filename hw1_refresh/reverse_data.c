// #include "arr_stack.h"
#include "ll_stack.h"
#include <stdio.h>

int main() {

    int i = 0;
    int* item;

    Stack* pStack = CreateStack(100);

    printf("Input 10 numbers : ");

    for (i = 0; i < 10; i++) {
        item = (int*)malloc(sizeof(int));
        scanf("%d", item);
        Push(pStack, item);
    }

    printf("Reversed : ");
    while(!IsEmptyStack(pStack)) {
        item = (int*)Pop(pStack);
        printf("%d ", *item);
        free(item);
    }
    printf("\n");

    DestroyStack(pStack);
    pStack = NULL;

    return 0;
}
