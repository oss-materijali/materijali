#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int *podniz(int *niz, int start, int stop) {
  int *slice = (int *)malloc((stop - start + 1) * sizeof(int));
  if (!slice)
    return NULL;

  int j = 0;
  for (int i = start; i <= stop; i++) {
    slice[j++] = niz[i];
  }

  return slice;
}

int *filtriraj(int *niz, int n, int th, int *nth) {
  int *filtered = NULL;
  int j = 0;
  for (int i = 0; i < n; i++) {
    if (niz[i] < th) {
      filtered = (int *)realloc(filtered, (j + 1) * sizeof(int));
      filtered[j++] = niz[i];
    }
  }
  *nth = j;
  return filtered;
}

int **podijeli(int *niz, int n) {
  if (n % 2 != 0) {
    printf("error: array can not be split equally\n");
    return NULL;
  }
  int half_n = n / 2;
  int rows = 2;

  int **arr = (int **)malloc(rows * sizeof(int *));
  if (!arr)
    return NULL;

  // alloc half_n lenght int arrays and copy elems from 'niz'
  for (int i = 0, niz_counter = 0; i < rows; i++) {
    arr[i] = (int *)malloc(half_n * sizeof(int));
    if (!arr[i])
      return NULL;

    for (int j = 0; j < half_n; j++) {
      arr[i][j] = niz[niz_counter++];
    }
  }

  return arr;
}

int main(void) {
  // podniz()
  printf("podniz():\n");
  int arr_a[] = {1, 2, 3, 4, 5, 6, 7};
  int *slice_a = podniz(arr_a, 1, 4);
  if (!slice_a)
    return 1;

  for (int i = 0; i < 4; i++)
    printf("%d ", slice_a[i]);
  printf("\n");

  printf("\n");

  // filtriraj()
  printf("filtriraj():\n");
  int arr_b[] = {10, 30, 40, 20, 60, 70, 50};

  int filtered_b_len;
  int *filtered_b =
      filtriraj(arr_b, (sizeof(arr_b) / sizeof(arr_b[0])), 40, &filtered_b_len);
  if (!filtered_b)
    return 2;

  for (int i = 0; i < filtered_b_len; i++)
    printf("%d ", filtered_b[i]);
  printf("\n");

  // podijeli
  printf("\npodijeli():\n");
  int arr_c[] = {1, 2, 3, 10, 9, 8};
  int c_len = 6;

  int **split_c = podijeli(arr_c, c_len);
  if (!split_c)
    return 3;

  for (int i = 0; i < 2; i++) {
    printf("[ ");
    for (int j = 0; j < c_len / 2; j++) {
      printf("%d ", split_c[i][j]);
    }
    printf("]\n");
  }

  free(slice_a);
  free(filtered_b);
  for (int i = 0; i < 2; i++)
    free(split_c[i]);
  free(split_c);

  return 0;
}
