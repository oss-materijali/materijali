#ifndef PRIMJER
#define PRIMJER

#define RANDOM (rand() * rand())

int*
generate(int n);
void
shuffle(int* niz, int n);
int
check_doubles(int* niz, int n);
int
cmp(const void* a, const void* b);
int
check_doubles_sort(int* niz, int n);

#endif
