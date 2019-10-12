// #include "arr_queue.h"
#include "ll_queue.h"

void PrintInt(void* item) {
  if ( item != NULL )
    printf("%d", *(int*)item);
}


int main() {
  Queue* queue;
  int input, *temp;

  printf("queue size : ");
  scanf("%d", &input);
  queue = CreateQueue(input);
  printf("queue created.\n\n");

  while (1) {
    printf("1.Enqueue, 2.Dequeue, 3.Quit: ");
    scanf("%d", &input);

    // input 1 : Enqueue

    if ( input == 1 ) {
      printf("New data : ");
      scanf("%d", &input);
      temp = (int*)malloc(sizeof(int));
      *temp = input;
      if ( !Enqueue(queue, temp) ) {
        printf("Queue is full. Enqueue failed.\n");
      }
    }

    // input 2 : Dequeue

    else if ( input == 2 ) {
      if ( (temp = Dequeue(queue)) == NULL ) {
        printf("Queue is empty. Dequeue failed.\n");
      }
      else {
        printf("Popped data : %d\n", *temp);
        free(temp);
      }
    }

    // input 3 : Quit

    else if ( input == 3 ) {
      DestroyQueue(queue);
      printf("Queue destroyed. exit.\n");
      break;
    }


    // else

    else {
      printf("Invalid input. Try again.\n");
    }
    printf("Current : ");
    PrintQueue(queue, PrintInt);
    printf("\n");
  }

  return 0;
}
