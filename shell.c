#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

void insertion_sort(int arr[], int step, int size) {
  for (int i = step; i < size; i++) {
    int value = arr[i];
    for (int j = i; j >= step && arr[j - step] > value; j -= step)
      swap(arr + j, arr + j - step);
    arr[i] = value;
  }
}

void shell_sort(int arr[], int size) {
  int step = size / 2;
  for (; step > 0; step /= 2)
    insertion_sort(arr, step, size);
}

int main(int argc, char* argv[]) {
  if (argc < 2) return 1;

  int size = atoi(argv[1]);
  int *arr = (int*)malloc(sizeof(int) * size);

  for (int i = 0; i < size; i++)
    scanf("%d", arr + i);

  shell_sort(arr, size);

  free(arr);

  return 0;
}
