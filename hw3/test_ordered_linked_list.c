#include "ordered_linked_list.h"
// #include "ordered_array_list.h"

int compareInt(void* arg1, void* arg2) {
  return (*(int*)arg1 - *(int*)arg2);
}

void printInt(void* item) {
  printf("%d", *(int*)item);
}


int main() {
  OrderedList* list = CreateList(compareInt);

  if ( list == NULL ) {
    printf("List allocation failed. Program terminates.\n");
    return -1;
  }

  // printf("List created.\n");

  int input, *temp;

  while ( true ) {
    printf("In (0), Search (1), Out(2), Exit (3) : ");
    scanf("%d", &input);

    if ( input == 0 ) {
      if ( IsFullList(list) ) {
        printf("Cannot add. List is full.\n");
      }
      else {
        printf("In : ");
        scanf("%d", &input);
        temp = (int*)malloc(sizeof(int));
        *temp = input;
        AddNode(list, temp);
      }
    }

    else if ( input == 1 ) {
      printf("Search : ");
      scanf("%d", &input);
      if ( SearchList(list, &input))
        printf("My List has %d.\n", input);
      else
        printf("My List does not have %d\n", input);
    }

    else if ( input == 2 ) {
      if ( IsEmptyList(list) ) {
        printf("Cannot remove. List is empty.\n");
      }
      else {
        printf("Out : ");
        scanf("%d", &input);
        if ( RemoveNode(list, &input) )
          printf("%d was removed.\n", input);
        else
          printf("My List does not have %d\n", input);
      }
    }

    else if ( input == 3 ) {
      DestroyList(list);
      // printf("List destroyed. exit.\n");
      printf("\n");
      break;
    }

    else {
      printf("Invalid input. Try again.\n");
      continue;
    }

    printf("The current status of List : ");
    TraverseList(list, printInt);
    printf("\n");
  }

  return 0;
}
