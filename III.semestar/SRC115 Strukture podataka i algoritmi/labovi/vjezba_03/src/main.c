#include "../include/stl.h"
#include <stdio.h>

/*
Translation:
  Trokut => Triangle
  Vrh => Vertex
  Tocke => Vertices
  Objekt => Object
*/

int main(void) {
  // read stl bin to obj
  FILE *stl_rb = fopen("prbin.stl", "rb");
  if (!stl_rb) {
    perror("");
    return 1;
  }

  Object3D obj = read_stl_bin(stl_rb);

  // write obj to stl bin
  write_stl_bin(&obj, "newbin.stl");
  write_stl_text(&obj, "newtxt.stl");

  free_object3d(&obj);
  return 0;
}
