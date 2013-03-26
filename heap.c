#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

#define LEFT(i) ((i) * 2 + 1)
#define RIGHT(i) ((i) * 2 + 2)

void heapify(int arr[], int item, int size) {
  int min = item;
  if (LEFT(item) < size && arr[LEFT(item)] < arr[min]) min = LEFT(item);
  if (RIGHT(item) < size && arr[RIGHT(item)] < arr[min]) min = RIGHT(item);
  if (item != min) {
    swap(arr + item, arr + min);
    heapify(arr, min, size);
  }
}

void heap_sort(int arr[], int size) {
  for (int i = size / 2; i >= 0; i--)
    heapify(arr, i, size);

  for (int i = size - 1; i > 0; i--) {
    swap(arr, arr + i);
    heapify(arr, 0, i - 1);
  }
}


int main(int argc, char* argv[]) {
  if (argc < 2) return 1;

  int size = atoi(argv[1]);
  int *arr = (int*)malloc(sizeof(int) * size);

  for (int i = 0; i < size; i++)
    scanf("%d", arr + i);

  heap_sort(arr, size);

  free(arr);

  return 0;
}


