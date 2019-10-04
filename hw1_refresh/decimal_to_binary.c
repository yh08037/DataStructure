#include "arr_stack.h"
// #include "ll_stack.h"
#include <stdio.h>

int main() {
    int decimal_number;
    int data;

    Stack* stack;

    printf("Enter an integer : ");
    scanf("%d", &decimal_number);

    if ( !(stack = CreateStack(100)) ) {
      printf("Memory allocation of stack failed. Program terminates.\n");
      return -1;
    }

    while (decimal_number != 0) {
        data = decimal_number % 2;
        if (IsFullStack(stack)) {
            printf("Input number is larger than size of stack. Program terminates.\n");
            return -2;
        }
        Push(stack, data);
        decimal_number /= 2;
    }

    printf("The binary number is : ");

    while ( !IsEmptyStack(stack) ) {
        data = Pop(stack);
        printf("%d", data);
    }
    printf("\n");

    return 0;
}
