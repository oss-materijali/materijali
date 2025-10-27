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
FILE *write_stl_bin(Object3D object);
// Funkcija koja Objekt3D strukturu zapisuje u tekstualnu STL datoteku
FILE *write_stl_text(Object3D object);
// Funkciju koja briše Objekt3D strukturu
void free_object3d(Object3D *object) {
  free(object->arr);
  object->arr = NULL;
  object->n = 0;
}
