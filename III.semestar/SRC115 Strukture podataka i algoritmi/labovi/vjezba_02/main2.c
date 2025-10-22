#include <stdio.h>
#include <stdlib.h>

typedef struct {
  float x, y;
} Tocka;

typedef struct {
  Tocka *arr;
  int n;
} Poligon;

Poligon *novi_poligon(float *niz_x, float *niz_y, int n) {
  if (n < 3) {
    printf("\nerror: invalid array of points len\n");
    return NULL;
  }

  Poligon *poly = (Poligon *)malloc(sizeof(Poligon));
  if (!poly)
    return NULL;

  poly->arr = (Tocka *)malloc(n * sizeof(Tocka));
  if (!poly->arr)
    return NULL;

  poly->n = n;

  for (int i = 0; i < poly->n; i++) {
    poly->arr[i].x = niz_x[i];
    poly->arr[i].y = niz_y[i];
  }

  return poly;
}

Tocka **pozitivni(Poligon *p, int *np) {
  Tocka **arr = (Tocka **)malloc(p->n * sizeof(Tocka *));
  if (!arr)
    return NULL;

  int j = 0;

  for (int i = 0; i < p->n; i++) {
    if (p->arr[i].x > 0 && p->arr[i].y > 0) {
      arr[j++] = &(p->arr[i]);
    }
  }

  *np = j;

  return arr;
}

int main() {
  float x[] = {-1.1, 2.111111, 3.23, 1};
  float y[] = {4.237, 5.093, -6, 0.00500002};
  int n = sizeof(x) / sizeof(x[0]);

  printf("poligon:\n");
  Poligon *poly = novi_poligon(x, y, n);
  if (!poly)
    return 1;

  for (int i = 0; i < poly->n; i++)
    printf("%.2f, %.2f | ", poly->arr[i].x, poly->arr[i].y);
  printf("\n");

  printf("\npozitivne tocke:\n");
  int np;
  Tocka **arr = pozitivni(poly, &np);
  if (!arr)
    return 2;

  for (int i = 0; i < np; i++) {
    printf("%.2f, %.2f | ", arr[i]->x, arr[i]->y);
  }
  printf("\n");

  free(poly->arr);
  free(poly);
  free(arr);
}
