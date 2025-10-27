#include <stdio.h>

/*
3) Napisati program koji od korisnika cita n struktura u niz i zatim ih
sprema u binarnu datoteku. Prije samog niza se sprema broj n. Broj
n se isto cita od korisnika prije citanja struktura. Strukture su tipa
Koordinata i sastoje se od dva float broja.
*/

// task 1) but with structs (more complex data type, same shi really)

typedef struct {
  float x, y;
} Coordinate;

int main(void) {
  int n;
  printf("unesi n: ");
  scanf(" %d", &n);

  Coordinate arr[n];
  printf("\nunesi arr struktura: \n");
  for (int i = 0; i < n; i++) {
    printf("\t[%d]: ", i);
    scanf(" %f %f", &arr[i].x, &arr[i].y);
  }

  FILE *file;
  file = fopen("04.bin", "wb");
  if (!file) {
    perror("");
    return 1;
  }

  int check = fwrite(&n, sizeof(n), 1, file);
  if (check < 1) {
    puts("Error writing the n in the file");
    return 2;
  }
  check = fwrite(arr, sizeof(arr[0]), n, file);
  if (check < n) {
    puts("Error writing the array to file");
    return 3;
  }

  // open file in a hex editor to see output

  fclose(file);
  return 0;
}
