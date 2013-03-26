#include <stdio.h>
#include <stdlib.h>

void quick_sort(int *a, int n) {
  if (n < 2) return;
  int p = a[0];
  int *l = a;
  int *r = a + n - 1;
  while (l <= r) {
    if (*l < p) {
      l++;
      continue;
    }
    if (*r > p) {
      r--;
      continue;
    }
    int t = *l;
    *l++ = *r;
    *r-- = t;
  }
  quick_sort(a, r - a + 1);
  quick_sort(l, a + n - l);
}

int main(int argc, char* argv[]) {
  if (argc < 2) return 1;

  int size = atoi(argv[1]);
  int *arr = (int*)malloc(sizeof(int) * size);

  for (int i = 0; i < size; i++)
    scanf("%d", arr + i);

  quick_sort(arr, size);

  free(arr);

  return 0;
}

