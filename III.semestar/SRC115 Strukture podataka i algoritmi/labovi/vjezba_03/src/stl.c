#include "../include/stl.h"
#include <stdio.h>
#include <stdlib.h>

#define HEADER 80

// Funkciju koja čita binarnu STL datoteku i vraća ispunjenu Objekt3D strukturu
Object3D read_stl_bin(FILE *file) {
  if (fseek(file, HEADER, SEEK_SET))
    exit(70);

  Object3D object = {NULL, 0};
  int check = fread(&object.n, sizeof(object.n), 1, file);
  if (check < 1) {
    puts("error reading number of triangles from the bin file");
    exit(71);
  }

  object.arr = (Triangle *)malloc(object.n * sizeof(Triangle));

  check = fread(object.arr, sizeof(Triangle), object.n, file);
  if (check < 1) {
    puts("error reading triangles to array");
    exit(72);
  }

  return object;
}

// Funkciju koja Objekt3D strukturu zapisuje u binarnu STL datoteku
// I decided against copying the entire object
void write_stl_bin(Object3D *object, char *file_name) {
  FILE *file = fopen(file_name, "wb");
  if (!file) {
    perror("newbin.stl: ");
    exit(90);
  }

  char zeros[HEADER] = {0};
  int check = fwrite(zeros, 1, HEADER, file);
  if (check < HEADER) {
    puts("Error writing header.");
    exit(91);
  }

  check = fwrite(&(object->n), sizeof(object->n), 1, file);
  if (check < 1) {
    puts("Error writing number of triangles.");
    exit(92);
  }

  check = fwrite(object->arr, sizeof(Triangle), object->n, file);
  if ((unsigned)check < object->n) {
    puts("Error in writing all triangles.");
    exit(93);
  }

  fclose(file);
}

// Funkcija koja Objekt3D strukturu zapisuje u tekstualnu STL datoteku
void write_stl_text(Object3D object, char *file_name);
// Funkciju koja briše Objekt3D strukturu
void free_object3d(Object3D *object) {
  free(object->arr);
  object->arr = NULL;
  object->n = 0;
}
