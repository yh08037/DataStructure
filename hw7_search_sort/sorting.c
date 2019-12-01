#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>




#define ARRAY_SIZE 256



int* get_random_array(int len);
int* copy_array(int* arr, int len);
void print_array(int* arr, int len);

void selection_sort(int* arr, int len);
void insertion_sort(int* arr, int len);
void bubble_sort(int* arr, int len);
// void quick_sort(int* arr, int len);
// void merge_sort(int* arr, int len);




int main() {

  int *arr, len, *copied_arr;

  srand(time(NULL));

  len = 10;
  arr = get_random_array(len);

  print_array(arr, len);

  copied_arr = copy_array(arr, len);
  selection_sort(copied_arr, len);
  print_array(copied_arr, len);
  free(copied_arr);

  print_array(arr, len);

  copied_arr = copy_array(arr, len);
  insertion_sort(copied_arr, len);
  print_array(copied_arr, len);
  free(copied_arr);




  // copied_arr = copy_array(arr, len);
  // bubble_sort(copied_arr, len);
  // print_array(copied_arr, len);
  // free(copied_arr);
  //
  //
  // copied_arr = copy_array(arr, len);
  // quick_sort(copied_arr, len);
  // print_array(copied_arr, len);
  // free(copied_arr);
  //
  //
  // copied_arr = copy_array(arr, len);
  // merge_sort(copied_arr, len);
  // print_array(copied_arr, len);
  // free(copied_arr);


  free(arr);

  return 0;
}



int* get_random_array(int len) {
  int *new_array, i;

  if ( !(new_array = (int*)malloc(sizeof(int) * len)) )
    return NULL;

  for ( i = 0; i < len; i++ )
    new_array[i] = rand() % 1000;

  return new_array;
}


int* copy_array(int* arr, int len) {
  int *new_array, i;

  if ( !(new_array = (int*)malloc(sizeof(int) * len)) )
    return NULL;

  memcpy(new_array, arr, sizeof(int) * len);

  return new_array;
}


void print_array(int* arr, int len) {
  int i;

  for ( i = 0; i < len; i++ )
    printf("%d ", arr[i]);
  printf("\n");
}


void selection_sort(int* arr, int len) {
  int i, j, min_idx, temp;

  for ( i = 0; i < len - 1; i++ ) {
    min_idx = i;

    for ( j = i+1; j < len; j++ )
      if (arr[j] < arr[min_idx])
        min_idx = j;

    temp = arr[i];
    arr[i] = arr[min_idx];
    arr[min_idx] = temp;
  }
}


void insertion_sort(int* arr, int len) {
  int i, j, temp;

  for ( i = 1; i < len; i++ ) {
    temp = arr[i];

    for ( j = i ; j > 0 && temp < arr[j-1]; j-- )
      arr[j] = arr[j-1];

    arr[j] = temp;
  }
}


void bubble_sort(int* arr, int len) {
  int i, j, temp, sorted;

  sorted = FALSE;

  for ( i = 0; i < n && !sorted; i++ ) {
    for ( j = n–1, sorted = TRUE; j > i; j-- ) {
      if ( arr[j] < arr[j-1] ) {
        sorted = FALSE; // Any exchange means arr is not sorted
        temp = arr[j];
        arr[j] = arr[j-1];
        arr[j-1] = temp;
      }
    }
  }
}
