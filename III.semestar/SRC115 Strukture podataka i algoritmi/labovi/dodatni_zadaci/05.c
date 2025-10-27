#include <stdio.h>

/*
5) Napisati program koji od korisnika čita dvije koordinate. Program
u datoteku (iz zadatka 3) dodaje još jednu točku na kraj datoteke.
Program zatim čita i ispisuje sve koordinate unazad. (otvorite
datoteku za čitanje i pisanje)
*/

typedef struct {
  float x, y;
} Coordinate;

int main(void) {
  FILE *file;
  file = fopen("03.bin", "a+b"); // append binary
  if (!file) {
    perror("");
    return 1;
  }

  Coordinate coord;
  printf("unesi x, y: ");
  scanf(" %f %f", &coord.x, &coord.y);

  int check = fwrite(&coord, sizeof(coord), 1, file);
  if (check < 1) {
    puts("Error appending the coords.");
    return 2;
  }

  if (fseek(file, 0, SEEK_SET))
    return 3;

  int n;
  check = fread(&n, sizeof(n), 1, file);
  if (check < 1) {
    puts("Error reading n.");
    return 4;
  }

  // added a coordinate, but didnt change original n in the file
  // (not specified in the task)
  // WARN: you can only run this program on the previous file ONE TIME beucase
  // of this
  n += 1;

  // read
  if (fseek(file, 0, SEEK_END))
    return 5;

  for (int i = 0; i < n; i++) {
    // seeking with offset is better (idk how to calc it with SEEK_CUR)
    // but if u know how to work this out with SEEK_CUR then good for u
    if (fseek(file, -sizeof(Coordinate) * (i + 1), SEEK_END))
      return 6;

    check = fread(&coord, sizeof(coord), 1, file);
    if (check < 1) {
      printf("Error reading coord at [%d].", i);
      return 7;
    }
    // output
    printf("coord[%d]: (%f,%f)\n", i, coord.x, coord.y);
  }

  fclose(file);
  return 0;
}
