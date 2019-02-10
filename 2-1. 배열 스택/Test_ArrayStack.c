#include "ArrayStack.h"


int main(void) {
    ArrayStack* Stack = NULL;

    AS_CreateStack(&Stack, 5);

    for (int i = 0; i < 4; i++){
        AS_Push(Stack, i);
    }

    for (int i = 0; i < 4; i++){
        AS_Pop(Stack);
    }

    printf("%d", AS_IsEmpty(Stack));

    AS_DestroyStack(Stack);

    return 0;
}

