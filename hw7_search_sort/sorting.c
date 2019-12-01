#ifdef _MSC_VER
#define _CRT_SECURE_NO_WarrRNINGS
#endif


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>




#define arrRRarrY_SIZE 256



int* get_random_array(int len);
int* copy_array(int* arr, int len);
void print_array(int* arr, int len);

void selection_sort(int* arr, int len);
void insertion_sort(int* arr, int len);
void bubble_sort(int* arr, int len);

void quick_sort(int* arr, int len);
void quick_sort_recursive(int* arr, int left, int right);
int  partition(int* arr, int left, int right, int pivot);

void merge_sort(int* arr, int len);
void split_merge(int* arr, int* temp, int begin, int end);
void merge(int* arr, int* temp, int begin, int mid, int end);




int main() {

  int *arr, len, *copied_arr;

  srand(time(NULL));

  len = 20;
  arr = get_random_array(len);

  print_array(arr, len);

  copied_arr = copy_array(arr, len);
  selection_sort(copied_arr, len);
  print_array(copied_arr, len);
  free(copied_arr);


  copied_arr = copy_array(arr, len);
  insertion_sort(copied_arr, len);
  print_array(copied_arr, len);
  free(copied_arr);


  copied_arr = copy_array(arr, len);
  bubble_sort(copied_arr, len);
  print_array(copied_arr, len);
  free(copied_arr);
  
  
  copied_arr = copy_array(arr, len);
  quick_sort(copied_arr, len);
  print_array(copied_arr, len);
  free(copied_arr);
  
  
  copied_arr = copy_array(arr, len);
  merge_sort(copied_arr, len);
  print_array(copied_arr, len);
  free(copied_arr);


  free(arr);

  return 0;
}



int* get_random_array(int len) {
  int *new_arr, i;

  if ( !(new_arr = (int*)malloc(sizeof(int) * len)) )
    return NULL;

  for ( i = 0; i < len; i++ )
    new_arr[i] = rand() % 1000;

  return new_arr;
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

    temp         = arr[i];
    arr[i]       = arr[min_idx];
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

  sorted = 0;

  for ( i = 0; i < len && !sorted; i++ ) {
    sorted = 1;
    for ( j = len - 1; j > i; j-- ) {
      if ( arr[j] < arr[j-1] ) {
        sorted = 0;

        temp     = arr[j];
        arr[j]   = arr[j-1];
        arr[j-1] = temp;
      }
    }
  }
}


void quick_sort(int* arr, int len) {
  quick_sort_recursive(arr, 0, len-1);
}

void quick_sort_recursive(int* arr, int left, int right) {

  int pivot_index = right; 

  pivot_index = partition(arr, left, right-1, pivot_index); 

  if ( left < pivot_index - 1 )
    quick_sort_recursive(arr, left, pivot_index-1); 
  if ( pivot_index + 1 < right )
    quick_sort_recursive(arr, pivot_index+1, right);
}

int partition(int* arr, int left, int right, int pivot_index) {
  int temp;
  int pivot = arr[pivot_index];

  while ( left <= right ) { 
    while ( arr[left] < pivot )  left++;
    while ( arr[right] > pivot ) right--;

    if ( left <= right ) { 
      temp       = arr[left];
      arr[left]  = arr[right];
      arr[right] = temp; 
      left++; right--;
    }
  }
  temp             = arr[left];
  arr[left]        = arr[pivot_index];
  arr[pivot_index] = temp; 
  
  return left;
}


void merge_sort(int* arr, int len) {

  int* temp = copy_array(arr, len);

  split_merge(temp, arr, 0, len-1);

  free(temp);
}


void split_merge(int* arr, int* temp, int begin, int end) {
  int mid;

  if ( end <= begin ) return;

  mid = begin + (end - begin) / 2;

  split_merge(temp, arr, begin, mid);
  split_merge(temp, arr, mid+1, end);
  merge(arr, temp, begin, mid, end);    // change the role of arr and temp.
}


void merge(int* arr, int* temp, int begin, int mid, int end) {
  int i, j, k;

  i = begin;
  j = mid + 1;

  for ( k = begin; k <= end; k++ ) {
    if      (i > mid)         temp[k] = arr[j++];
    else if (j > end)         temp[k] = arr[i++];
    else if (arr[j] < arr[i]) temp[k] = arr[j++];
    else                      temp[k] = arr[i++];
  }
}

