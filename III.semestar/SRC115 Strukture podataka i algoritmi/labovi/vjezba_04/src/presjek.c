#include "presjek.h"
#include "primjer.h"
#include <stddef.h>
#include <stdlib.h>

size_t
presjek(int* a, size_t a_len, int* b, size_t b_len)
{
  shuffle(a, a_len);
  shuffle(b, b_len);

  size_t count = 0;

  for (size_t i = 0; i < a_len; i++) {
    for (size_t j = 0; j < b_len; j++) {
      if (a[i] == b[j]) {
        count++;
        break;
      }
    }
  }

  return count;
}

size_t
presjek_jedan_sortiran(int* a, size_t a_len, int* b, size_t b_len)
{
  shuffle(a, a_len);
  qsort(b, b_len, sizeof(int), cmp);

  size_t count = 0;

  for (size_t i = 0; i < a_len; i++)
    if (bsearch(&a[i], b, b_len, sizeof(int), cmp))
      count++;

  return count;
}

size_t
presjek_oba_sortirana(int* a, size_t a_len, int* b, size_t b_len)
{
  qsort(a, a_len, sizeof(int), cmp);
  qsort(b, b_len, sizeof(int), cmp);

  size_t count = 0;

  size_t i, j;
  i = j = 0;

  while (i < a_len && j < b_len) {
    if (a[i] > b[j])
      j++;
    else if (a[i] < b[j])
      i++;
    else {
      count++;
      i++;
      j++;
    }
  }

  return count;
}

size_t
presjek_po_indexima(int* a, size_t a_len, int* b, size_t b_len)
{
  shuffle(a, a_len);
  shuffle(b, b_len);

  int max_a = max_in_array(a, a_len);
  int max_b = max_in_array(b, b_len);

  int index_len = (max_a > max_b) ? max_a + 1 : max_b + 1;

  int* a_index = (int*)calloc(index_len, sizeof(int));
  int* b_index = (int*)calloc(index_len, sizeof(int));

  if (!a_index || !b_index)
    return 0;

  for (size_t i = 0; i < a_len; i++)
    a_index[a[i]] = 1;
  for (size_t i = 0; i < b_len; i++)
    b_index[b[i]] = 1;

  size_t count = 0;

  for (int i = 0; i < index_len; i++)
    if (a_index[i] & b_index[i])
      count++;

  free(a_index);
  free(b_index);

  return count;
}

int
max_in_array(int* arr, size_t arr_len)
{
  int high = arr[0];

  for (size_t i = 1; i < arr_len; i++)
    if (arr[i] > high)
      high = arr[i];

  return high;
}
