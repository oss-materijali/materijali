#include <stdio.h>

/*
1) Napisati program koji od korisnika cita n brojeva u niz i zatim ih
sprema u binarnu datoteku (sa fwrite). Prije samog niza se sprema
broj n. Broj n se isto cita od korisnika prije citanja samih brojeva
niza.
*/

int main(void) {
  int n;
  printf("unesi n: ");
  scanf(" %d", &n);

  int arr[n];
  printf("\nunesi arr: \n");
  for (int i = 0; i < n; i++) {
    printf("\t[%d]: ", i);
    scanf(" %d", &arr[i]);
  }

  FILE *file;
  file = fopen("01.bin", "wb");
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
