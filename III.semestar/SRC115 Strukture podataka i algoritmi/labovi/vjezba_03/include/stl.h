#ifndef STL
#define STL

#include <stdio.h>
#include <stdlib.h>

typedef struct {
  float x, y, z; // 4 bytes * 3 = 12
} Vertex;

#pragma pack(push, 1)
typedef struct {
  Vertex normal;        // 12
  Vertex vertices[3];   // 12 * 3 = 36
  unsigned short color; // 2
} Triangle;
// 12 + 36 + 2 = 50
// cpu: 4-byte alloc, 4*13=52, need 50 bytes EXACTLY
// pragma to force cpu to 1-byte alloc for this struct only
#pragma pack(pop)

typedef struct {
  Triangle *arr;
  unsigned int n;
} Object3D;

// Funkciju koja čita binarnu STL datoteku i vraća ispunjenu Objekt3D strukturu
Object3D read_stl_bin(FILE *file);
// Funkciju koja Objekt3D strukturu zapisuje u binarnu STL datoteku
void write_stl_bin(Object3D *object, char *file_name);
// Funkcija koja Objekt3D strukturu zapisuje u tekstualnu STL datoteku
void write_stl_text(Object3D object, char *file_name);
// Funkciju koja briše Objekt3D strukturu
void free_object3d(Object3D *object);

#endif
