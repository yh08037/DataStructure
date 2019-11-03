#include "complete_bt.h"

#define BUFFER_SIZE 256

int main() {

  char input_string[BUFFER_SIZE];
  Tree* bt;

  printf("(max input string length : 255)\n\n");

  printf("input : ");
  scanf("%[^\n]s", input_string);

  bt = create_bt_from_string(input_string);

  if ( !bt ) {
    printf("create_bt_from_string failed. program terminates.\n");
    return -1;
  }

  printf("\npreorder\t");
  preorder(bt, 1);

  printf("\ninorder\t\t");
  inorder(bt, 1);

  printf("\npostorder\t");
  postorder(bt, 1);

  printf("\nbreadth-first\t");
  breadth_first(bt, 1);

  printf("\n");

  destroy_tree(bt);

  return 0;
}
