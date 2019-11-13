#include "bst.h"
#include <string.h>


#define MAX_LEN 256


int compare_string(void* a, void* b) {
  return strcmp((char*)a, (char*)b);
}

void print_string(void* a) {
  printf("%s ", (char*)a);
}


int main() {

  BST* bst = create_bst(compare_string, print_string);
  int input;
  char* string;
  char buffer[MAX_LEN];

  while ( 1 ) {
    input = -1;

    printf("1)insert 2)delete 3)search 4)print 0)quit : ");
    scanf("%d", &input);
    while ( getchar() != '\n');
    printf("\n");

    switch ( input ) {
      case 0: // quit
        printf("exit.\n");
        return 0;

      case 1: // insert
        string = (char*)malloc(sizeof(char)*MAX_LEN);
        printf("string : ");
        scanf("%[^\n]", string);
        while ( getchar() != '\n');

        if ( insert_data(bst, string) )
          printf("insert : successed.\n");
        else
          printf("insert : failed.\n");
        break;

      case 2: // delete
        printf("string : ");
        scanf("%[^\n]", buffer);
        while ( getchar() != '\n');

        if ( delete_data(bst, buffer) )
          printf("delete : successed.\n");
        else
          printf("delete : failed.\n");
        break;

      case 3: // search
        printf("string : ");
        scanf("%[^\n]", buffer);
        while ( getchar() != '\n');

        if ( search_data(bst, buffer) )
          printf("search : \"%s\" exists.\n", buffer);
        else
          printf("search : \"%s\" does not exists.\n", buffer);
        break;

      case 4: // print
        printf("1)preorder 2)inorder 3)postorder 4)breadth first : ");
        scanf("%d", &input);
        while ( getchar() != '\n');
        printf("\n");

        switch ( input ) {
          case 1: preorder(bst);      break;
          case 2: inorder(bst);       break;
          case 3: postorder(bst);     break;
          case 4: breadth_first(bst); break;
          default: printf("invalid option number.\n");
        }
        printf("\n");
        break;

      default:
        printf("invalid option number. retry.\n");
    }

    printf("\n\n");
  }

  destroy_bst(bst);

  return 0;
}
