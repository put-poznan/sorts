#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

int selection_sort(int arr[], int size) {
  for (int i = 0; i < size - i; i++) {
    int min_idx = i + 1;
    for (int j = min_idx; j < size; j++)
      if (arr[min_idx] > arr[j]) min_idx = j;
    if (arr[i] > arr[min_idx]) swap(arr + i, arr + min_idx);
  }
}

int main(int argc, char* argv[]) {
  if (argc < 2) return 1;

  int size = atoi(argv[1]);
  int *arr = (int*)malloc(sizeof(int) * size);

  for (int i = 0; i < size; i++)
    scanf("%d", arr + i);

  selection_sort(arr, size);

  free(arr);

  return 0;
}

