#ifndef PRESJEK
#define PRESJEK

#include <stddef.h>

size_t
presjek(int* a, size_t a_len, int* b, size_t b_len);
size_t
presjek_jedan_sortiran(int* a, size_t a_len, int* b, size_t b_len);
size_t
presjek_oba_sortirana(int* a, size_t a_len, int* b, size_t b_len);
size_t
presjek_po_indexima(int* a, size_t a_len, int* b, size_t b_len);

int
max_in_array(int* arr, size_t arr_len);

#endif
