#include "../include/stl.h"
#include <stdio.h>
#include <stdlib.h>

#define HEADER 80

#define SOLID_START "solid"
#define SOLID_END "endsolid"
#define FACET_START "facet normal"
#define FACET_END "endfacet"
#define LOOP_START "outer loop"
#define LOOP_END "endloop"
#define VERTEX "vertex"

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
    perror("");
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
void write_stl_text(Object3D *object, char *file_name) {
  FILE *file = fopen(file_name, "wt");
  if (!file) {
    perror("");
    exit(50);
  }
  char optional_object_name[] = "new_object";
  int check =
      fprintf(file, "%s %s\n", SOLID_START, optional_object_name); // header
  if (check < 0) {
    puts("Error writing start of object.");
    exit(56);
  }
  for (int i = 0; i < object->n; i++) {
    check = fprintf(file, "\t%s %.5f %.5f %.5f\n", FACET_START,
                    object->arr[i].normal.x, object->arr[i].normal.y,
                    object->arr[i].normal.z); // normal vector
    if (check < 0) {
      puts("Error writing normal vector.");
      exit(51);
    }

    check = fprintf(file, "\t\t%s\n", LOOP_START); // outer loop
    if (check < 0) {
      puts("Error writing start of loop.");
      exit(52);
    }

    for (int j = 0; j < 3; j++) { // single vertex * 3
      check =
          fprintf(file, "\t\t\t%s %.5f %.5f %.5f\n", VERTEX,
                  object->arr[i].vertices[j].x, object->arr[i].vertices[j].y,
                  object->arr[i].vertices[j].z);
      if (check < 0) {
        puts("Error writing vertex.");
        exit(53);
      }
    }
    check = fprintf(file, "\t\t%s\n", LOOP_END); // endloop
    if (check < 0) {
      puts("Error writing end of loop");
      exit(54);
    }
    check = fprintf(file, "\t%s\n", FACET_END); // endfacet
    if (check < 0) {
      puts("Error writing end of facet");
      exit(55);
    }
  } // writing triangles finished

  check = fprintf(file, "%s %s\n", SOLID_END, optional_object_name); // header
  if (check < 0) {
    puts("Error writing end of object.");
    exit(57);
  }

  fclose(file);
}

// Funkciju koja briše Objekt3D strukturu
void free_object3d(Object3D *object) {
  free(object->arr);
  object->arr = NULL;
  object->n = 0;
}
