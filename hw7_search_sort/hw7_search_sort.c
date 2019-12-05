#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>





void test_binary_search(int* arr, int len, int max);
void set_array(int** ordered_array, int** index_array, int* arr, int len);

int  binary_search(int* arr, int len, int item);
int  binary_search_recursive(int* arr, int begin, int end, int item);

void test_hashed_search(int* arr, int len, int max);

int  hashed_search(int* hash_table, int* arr, int table_size, int item);
int* create_hash_table(int* arr, int len, int max, int* table_size);
int  hash(int data, int table_size);
int  get_table_size(int max);
int  collision(int hashed_key, int table_size);

void test_sorting(void (*sort)(int*, int), int* arr, int len);

void selection_sort(int* arr, int len);
void insertion_sort(int* arr, int len);
void bubble_sort(int* arr, int len);

void quick_sort(int* arr, int len);
void quick_sort_recursive(int* arr, int left, int right);
int  partition(int* arr, int left, int right, int pivot);

void merge_sort(int* arr, int len);
void split_merge(int* arr, int* temp, int begin, int end);
void merge(int* arr, int* temp, int begin, int mid, int end);

int* get_random_array(int len, int max);
int* copy_array(int* arr, int len);
void print_array(int* arr, int len);




int main() {

  int *arr;
  int len, max;

  srand(time(NULL));


  printf("generate random numbers...\n");
  printf("  set length of sequence : "); scanf("%d", &len);
  printf("  set maximum value : ");      scanf("%d", &max);

  printf("\n\n");


  printf("original random sequence\n");

  arr = get_random_array(len, max);
  print_array(arr, len);
  printf("\n\n");



  printf("Problem 1 : Search\n\n");

  
  printf("binary search\n");
  test_binary_search(arr, len, max);
  printf("\n");


  // hash : pseudorandom, collision : linear probing
  printf("hashed search\n");
  test_hashed_search(arr, len, max);
  printf("\n");



  printf("Problem 2 : Sort\n\n");


  printf("selection sort\n");
  test_sorting(selection_sort, arr, len);
  printf("\n");


  printf("insertion sort\n");
  test_sorting(insertion_sort, arr, len);
  printf("\n");


  printf("bubble sort\n");
  test_sorting(bubble_sort, arr, len);
  printf("\n");

  
  printf("quick sort\n");
  test_sorting(quick_sort, arr, len);
  printf("\n");


  printf("merge sort\n");  
  test_sorting(merge_sort, arr, len);
  printf("\n");


  free(arr);

  return 0;
}





void test_binary_search(int* arr, int len, int max) {
  int item, result, index, re_accessed;
  int *ordered_array, *index_array;

  set_array(&ordered_array, &index_array, arr, len);

  printf("item\tindex\tre-accessed\n");

  for ( item = 0; item <= max; item++ ) {
    result = binary_search(ordered_array, len, item);
    if ( result == -1 ) 
      index = re_accessed = -1;
    else {
      index       = index_array[result];
      re_accessed = arr[index];
    }

    printf("%d\t%d\t%d\n", item, index, re_accessed);
  }
  printf("\n");

  free(ordered_array);
  free(index_array);
}


void set_array(int** ordered_array, int** index_array, int* arr, int len) {
  int i, j, temp1, temp2;
  
  *ordered_array = copy_array(arr, len);
  *index_array = (int*)malloc(sizeof(int) * len);

  for ( i = 0; i < len; i++ ) 
    (*index_array)[i] = i;


  for ( i = 1; i < len; i++ ) {
    temp1 = (*ordered_array)[i];
    temp2 = (*index_array)[i];

    for ( j = i ; j > 0 && temp1 < (*ordered_array)[j-1]; j-- ) {
      (*ordered_array)[j] = (*ordered_array)[j-1];
      (*index_array)[j]   = (*index_array)[j-1];
    }

    (*ordered_array)[j] = temp1;
    (*index_array)[j]   = temp2;
  }
}


int binary_search(int* arr, int len, int item) {
  return binary_search_recursive(arr, 0, len-1, item);
}


int binary_search_recursive(int* arr, int begin, int end, int item) {
  int mid;

  if ( begin > end ) return -1;

  mid = ( begin + end ) / 2;

  if ( arr[mid] == item )
    return mid;
  else if ( arr[mid] > item )
    return binary_search_recursive(arr, begin, mid-1, item);
  else
    return binary_search_recursive(arr, mid+1, end, item);
}






void test_hashed_search(int* arr, int len, int max) {
  int item, result, index, re_accessed;
  int *hash_table, table_size;

  hash_table = create_hash_table(arr, len, max, &table_size);

  printf("item\tindex\tre-accessed\n");

  for ( item = 0; item <= max; item++ ) {
    result = hashed_search(hash_table, arr, table_size, item);
    if ( result == -1 )
      index = re_accessed = -1;
    else {
      index       = hash_table[result];
      re_accessed = arr[index];
    }
    
    printf("%d\t%d\t%d\n", item, index, re_accessed);
  }
  printf("\n");

  free(hash_table);
}


int hashed_search(int* hash_table, int* arr, int table_size, int item) {
  int hashed_key, cnt; 

  hashed_key = hash(item, table_size);

  if ( item != arr[hash_table[hashed_key]] ) {
    cnt = 0;
    while ( (item != arr[hash_table[hashed_key]]) && (cnt++ < table_size) )
      hashed_key = collision(hashed_key, table_size);
  }

  if ( item == arr[hash_table[hashed_key]] ) 
    return hashed_key;
  
  return -1;
}


int* create_hash_table(int* arr, int len, int max, int* table_size) {
  int* hash_table;
  int  hashed_key, index, cnt;

  *table_size = get_table_size(max);
  hash_table = (int*) malloc(sizeof(int) * (*table_size));
  memset(hash_table, -1, sizeof(int) * (*table_size));

  for ( index = 0; index < len; index++ ) {
    hashed_key = hash(arr[index], *table_size);

    if ( hash_table[hashed_key] != -1 ) {
      cnt = 0;
      while ( (hash_table[hashed_key] != -1) && (cnt++ < *table_size) ) 
        hashed_key = collision(hashed_key, *table_size);

      if ( hash_table[hashed_key] != -1 ) {
        printf("fail to hash %d. table is full.\n", arr[index]);
      }
    }
    hash_table[hashed_key] = index;
  }

  return hash_table;
}


int hash(int data, int table_size) {
  return (17 * data + 7) % table_size;
}


int get_table_size(int max) {
  int table_size, is_prime, i;

  table_size = (int) (max * 1.3);

  while ( 1 ) {
    for ( is_prime = 1, i = 2; i <= sqrt(table_size); i++ ) {
      if ( table_size % i == 0 ) {
        is_prime = 0; break;
      }
    }

    if ( is_prime ) break;
    table_size++;
  }

  return table_size;
}

int collision(int hashed_key, int table_size) {
  return hashed_key < table_size - 1 ? hashed_key + 1 : 0;
}





void test_sorting(void (*sort)(int*, int), int* arr, int len) {
  int* copied_array;

  copied_array = copy_array(arr, len);
  sort(copied_array, len);
  print_array(copied_array, len);

  free(copied_array);
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
  merge(arr, temp, begin, mid, end);  // change the role of arr and temp.
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






int* get_random_array(int len, int max) {
  int *new_array, i;

  if ( !(new_array = (int*)malloc(sizeof(int) * len)) )
    return NULL;

  for ( i = 0; i < len; i++ )
    new_array[i] = rand() % (max + 1);

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