#include "presjek.h"
#include "primjer.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// #define N 13

#define START 100000
#define END 3000000
#define STEP 300000

int
main(void)
{
  srand((unsigned int)time(NULL));

  printf("presjek() time test: \n");
  for (int n = START; n < END; n += STEP) {
    int* arr_a = generate(n);
    int* arr_b = generate(n);

    shuffle(arr_a, n);
    shuffle(arr_b, n);

    int stime = clock();
    presjek(arr_a, n, arr_b, n);
    int etime = clock();

    printf("%d\t%f\n", n, ((float)(etime - stime)) / CLOCKS_PER_SEC);

    free(arr_a);
    free(arr_b);
  }

  return 0;
}
