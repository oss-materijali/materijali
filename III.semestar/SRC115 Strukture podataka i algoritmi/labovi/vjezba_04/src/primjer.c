// #include <stdio.h>
#include <stdlib.h>
// #include <time.h>

#define RANDOM (rand() * rand())
// provjera jedinstvenosti elemenata u nizu

int*
generate(int n)
{
  int* niz = (int*)malloc(n * sizeof(int));
  niz[0] = 1 + rand() % 5;
  for (int i = 1; i < n; i++) {
    niz[i] = niz[i - 1] + 1 + rand() % 5;
  }
  return niz;
}

void
shuffle(int* niz, int n)
{
  for (int i = 0; i < n; i++) {
    // int j = RANDOM % n; // jesus christ... no comment.
    int j = rand() % n;
    int tmp = niz[i];
    niz[i] = niz[j];
    niz[j] = tmp;
  }
}

int
check_doubles(int* niz, int n)
{
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++)
      if (niz[i] == niz[j])
        return 1;
  }
  return 0;
}

int
cmp(const void* a, const void* b)
{
  return *((int*)a) - *((int*)b);
}

int
check_doubles_sort(int* niz, int n)
{
  qsort(niz, n, sizeof(int), cmp);
  for (int i = 1; i < n; i++) {
    if (niz[i] == niz[i - 1])
      return 1;
  }
  return 0;
}

// void main() {
// 	for (int n = 10000; n < 100000; n += 10000) {
// 		int* niz = generate(n);
// 		shuffle(niz, n);

// 		int stime = clock();
// 		check_doubles_sort(niz, n);
// 		int etime = clock();

// 		printf("%d\t%f\n", n, ((float)(etime - stime)) /
// CLOCKS_PER_SEC); 		free(niz);
// 	}
// }
