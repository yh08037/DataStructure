#include "LinkedListStack.h"

int main(void) {

    LinkedListStack* Stack;

    LLS_CreateStack(&Stack);

    LLS_Push(Stack, LLS_CreateNode("abc"));
    LLS_Push(Stack, LLS_CreateNode("def"));
    LLS_Push(Stack, LLS_CreateNode("ghi"));
    LLS_Push(Stack, LLS_CreateNode("jkl"));

    printf("Size : %d, Top : %s\n\n", LLS_GetSize(Stack), LLS_Top(Stack)->Data);

    while ( !LLS_IsEmpty(Stack) ) {
        printf("Popped : %s, ", LLS_Pop(Stack)->Data);

        if( !LLS_IsEmpty(Stack) ) {
            printf("Current Top : %s\n", LLS_Top(Stack)->Data);
        }
        else {
            printf("Stack Is Empty.\n");
        }
    }

    LLS_DestroyStack(Stack);

    return 0;
}
