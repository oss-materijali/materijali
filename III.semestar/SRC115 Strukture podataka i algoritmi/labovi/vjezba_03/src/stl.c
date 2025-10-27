#include "../include/stl.h"
#include <stdlib.h>
#include <stdio.h>

#define HEADER 80

// Funkciju koja čita binarnu STL datoteku i vraća ispunjenu Objekt3D strukturu
Object3D *read_stl_bin(FILE *file) {
  if (fseek(file, HEADER, SEEK_SET)) {
    exit(70);
  }

  return object;
}

// Funkciju koja Objekt3D strukturu zapisuje u binarnu STL datoteku
FILE *write_stl_bin(Object3D object);
// Funkcija koja Objekt3D strukturu zapisuje u tekstualnu STL datoteku
FILE *write_stl_text(Object3D object);
// Funkciju koja briše Objekt3D strukturu
void free_object3d(Object3D object);
