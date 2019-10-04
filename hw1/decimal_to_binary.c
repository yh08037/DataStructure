#include "arr_stack.h"
// #include "ll_stack.h"
#include <stdio.h>

int main() {
    int decimal_number;
    int data;

    printf("Enter an integer : ");
    scanf("%d", &decimal_number);

    Stack* pStack = CreateStack(100);

    while (decimal_number != 0) {
        data = decimal_number % 2;
        if (IsFullStack(pStack)) {
            printf("Input number is larger than size of stack. Program terminates.\n");
            return -1;
        }
        Push(pStack, data);
        decimal_number /= 2;
    }

    printf("The binary number is : ");

    while (!IsEmptyStack(pStack)) {
        data = Pop(pStack);
        printf("%d", data);
    }
    printf("\n");

    return 0;
}
