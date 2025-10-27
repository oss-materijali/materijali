#include <stdio.h>
#include <stdlib.h>

/*
2) Napisati program koji cita datoteku iz prethodnog zadatka (sa
fread) i ispisuje brojeve na ekran.
*/

int main(void) {
  FILE *file;
  file = fopen("01.bin", "rb");
  if (!file) {
    perror("");
    return 1;
  }

  int n;
  int check = fread(&n, sizeof(int), 1, file);
  if (check < 1) {
    puts("Error reading n from file.");
    return 2;
  }

  int *arr = (int *)malloc(n * sizeof(int));

  check = fread(arr, sizeof(arr[0]), n, file);
  if (check < 1) {
    puts("Error reading arr from file.");
    return 3;
  }

  fclose(file);

  // output
  printf("n: %d\n", n);
  printf("arr: ");
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  free(arr);
  return 0;
}
