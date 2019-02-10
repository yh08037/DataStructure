#include "CircularDoublyLinkedList.h"

int main(void) {
    Node* List = NULL;

    for ( int i = 0; i < 5; i++ ) {
        CDLL_AppendNode(&List, CDLL_CreateNode(i));
    }

    for (int i = 0; i < 2 * CDLL_GetNodeCount(List); i++ ) {
        printf("%d ", CDLL_GetNodeAt(List, i)->Data);
    }

    getchar();

    return 0;
}
