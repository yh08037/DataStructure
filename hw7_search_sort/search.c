#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif


#include <stdio.h>


#define ARRAY_SIZE 256




int binary_search(int* arr, int begin, int end, int item);
// int hashed_search(int* arr, int item);




int main() {

  int arr[ARRAY_SIZE];
  int arr_len, item, i, result;
  int input_number, input_length;



  arr_len = 0;


  while ( 1 ) {

    printf("current numbers : ");
    for ( i = 0; i < arr_len; i++ )
      printf("%d ", arr[i]);
    printf("\n\n");


    input_number = -1;

    printf("(1) insert number, (2) search number, (0) exit : ");
    scanf("%d", &input_number);
    while ( getchar() != '\n' );
    printf("\n");


    switch ( input_number ) {
      case 0:
        printf("exit.\n");
        return 0;

      case 1:
        printf("  input length : ");
        scanf("%d", &input_length);
        while ( getchar() != '\n' );
        printf("\n");

        printf("  numbers : ");

        for ( i = 0; i < input_length; i++ )
          scanf("%d", arr+(arr_len++));
        while ( getchar() != '\n' );
        printf("\n");

        break;

      case 2:
        printf("  (1) binary search, (2) hashed search : ");
        scanf("%d", &input_number);
        while ( getchar() != '\n' );
        printf("\n");

        switch ( input_number ) {
          case 1: // binary search
            printf("    number : ");
            scanf("%d", &item);
            while ( getchar() != '\n' );
            printf("\n");

            if ( (result = binary_search(arr, 0, arr_len-1, item)) == -1 )
              printf("    %d does not exists.\n\n", item);
            else
              printf("    %d is at index %d\n\n", item, result);
            break;

          case 2: // hashed search
            // return number index
            printf("    number : ");
            scanf("%d", &item);
            while ( getchar() != '\n' );
            break;

          default:
            printf("    invalid input number. try again.\n\n");
        }
        break;

      default:
        printf("  invalid input number. try again.\n");
    }

    printf("===========================================================\n\n");
  }



  return 0;
}




int binary_search(int* arr, int begin, int end, int item) {

  int mid;

  if ( begin > end ) return -1;

  mid = begin + (end - begin) / 2;

  if ( arr[mid] == item )
    return mid;
  else if ( item < arr[mid ])
    return binary_search(arr, begin, mid-1, item);
  else
    return binary_search(arr, mid+1, end, item);
}


int hashed_search(int** )
