#include <stdio.h>

/*
4) Napisati program koji od korisnika cita jedan broj odnosno indeks.
Program iz datoteke iz prethodnog zadatka cita i ispisuje na ekran
koordinatu koja odgovara tom indeksu. (koristite fseek)
*/

typedef struct {
  float x, y;
} Coordinate;

int main(void) {
  FILE *file;
  file = fopen("03.bin", "rb");
  if (!file) {
    perror("");
    return 1;
  }

  int index;
  printf("unesi index: ");
  scanf(" %d", &index);

  Coordinate indexed_coordinate;
  if (fseek(file, sizeof(Coordinate) * index + sizeof(int), SEEK_SET))
    return 2;

  int check;
  check = fread(&indexed_coordinate.x, sizeof(indexed_coordinate.x), 1, file);
  if (check < 1) {
    puts("Error reading coordinate.x from file. (might be an overflow, check "
         "the index)");
    return 3;
  }
  check = fread(&indexed_coordinate.y, sizeof(indexed_coordinate.x), 1, file);
  if (check < 1) {
    puts("Error reading coordinate.y from file. (might be an overflow, check "
         "the index)");
    return 4;
  }

  fclose(file);
  // print

  printf("\n[%d]: (%f, %f)\n", index, indexed_coordinate.x,
         indexed_coordinate.y);

  return 0;
}
