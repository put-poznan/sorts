#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

void insertion_sort(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    int value = arr[i];
    for (int j = i; j >= 1 && arr[j - 1] > value; j--)
      swap(arr + j, arr + j - 1);
    arr[i] = value;
  }
}

int main(int argc, char* argv[]) {
  if (argc < 2) return 1;

  int size = atoi(argv[1]);
  int *arr = (int*)malloc(sizeof(int) * size);

  for (int i = 0; i < size; i++)
    scanf("%d", arr + i);

  insertion_sort(arr, size);

  free(arr);

  return 0;
}
