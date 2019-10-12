// #include "arr_queue.h"
#include "ll_queue.h"
#include <string.h>

#define MAX_QUEUE_SIZE 128
#define MAX_INPUT_SIZE 256

void PrintString(void* item) {
  if ( item != NULL )
    printf("%s", (char*)item);
}


int main() {
  Queue* queue;
  int input;
  char name[MAX_INPUT_SIZE];
  char* temp;

  queue = CreateQueue(MAX_QUEUE_SIZE);

  while (1) {
    printf("In (0), Out (1), exit(2) : ");
    scanf("%d", &input);
    while (getchar() != '\n');  // flush buffer

    // input 0 : Enqueue

    if ( input == 0 ) {
      printf("Customer : ");
      gets(name);
      temp = (char*)calloc(MAX_INPUT_SIZE, sizeof(char));
      strcpy(temp, name);
      if ( !Enqueue(queue, temp) ) {
        printf("Queue is full. Enqueue failed.\n");
      }
    }

    // input 1 : Dequeue

    else if ( input == 1 ) {
      if ( (temp = Dequeue(queue)) == NULL ) {
        printf("Queue is empty. Dequeue failed.\n");
      }
      else {
        printf("Customer : %s\n", temp);
        free(temp);
      }
    }

    // input 2 : Quit

    else if ( input == 2 ) {
      DestroyQueue(queue);
      // printf("Queue destroyed. exit.\n");
      printf("\n");
      break;
    }


    // else

    else {
      printf("Invalid input. Try again.\n");
    }


    printf("The current state of Queue : ");
    PrintQueue(queue, PrintString);
    printf("\n");
  }

  return 0;
}
