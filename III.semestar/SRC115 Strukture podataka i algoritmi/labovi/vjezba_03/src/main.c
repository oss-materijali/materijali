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
  FILE *file = fopen("prbin.stl", "rb");
  if (!file) {
    perror("");
    return 1;
  }

  Object3D obj = read_stl_bin(file);

  // for (unsigned int i = obj.n-2; i < obj.n; i++) {
  //   printf("(%.2f, %.2f, %.2f)[%.2f %.2f %.2f;%.2f %.2f %.2f;%.2f %.2f %.2f] "
  //          "c: %hu\n",
  //          obj.arr[i].normal.x, obj.arr[i].normal.y, obj.arr[i].normal.z,
  //          obj.arr[i].vertices[0].x, obj.arr[i].vertices[0].y,
  //          obj.arr[i].vertices[0].z, obj.arr[i].vertices[1].x,
  //          obj.arr[i].vertices[1].y, obj.arr[i].vertices[1].z,
  //          obj.arr[i].vertices[2].x, obj.arr[i].vertices[2].y,
  //          obj.arr[i].vertices[2].z, obj.arr[i].color);
  // }

  free_object3d(&obj);
  return 0;
}
