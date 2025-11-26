#include "dictionary.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// kreaira novi prazni rjecnik
Dictionary
create()
{
  Dictionary dict = malloc(sizeof *dict);
  if (!dict)
    exit(100);

  // sentinel
  dict->word = NULL;
  dict->count = 0;
  dict->next = NULL;

  return dict;
}

// dodaje rijec ili uvecava broj pojavljivanja rijeci u rjecniku
// rijeci se dodaju u abecednom redu
void
add(Dictionary dict, char* str)
{
  if (!dict || !str)
    return;

  Word* prev = dict;
  Word* cur = dict->next;

  Word* new = malloc(sizeof *new);
  if (!new)
    return;

  new->word = strdup(str);
  if (!new->word) {
    free(new);
    return;
  }
  new->count = 1;
  // new->next = NULL;

  while (cur != NULL && strcmp(cur->word, new->word) < 0) {
    prev = cur;
    cur = cur->next;
  }

  if (cur && strcmp(new->word, cur->word) == 0) { // same word
    cur->count += 1;
    free(new->word);
    free(new);
    return;
  }

  // insert between prev and cur
  new->next = cur;
  prev->next = new;
}

// ispisuje sve rijeci i broj pojavljivanja svake rijeci
void
print(Dictionary dict)
{
  if (!dict)
    return;

  Word* cur = dict->next;

  if (cur == NULL) {
    printf("The list is empty\n");
    return;
  }

  while (cur != NULL) {
    printf("%p\t%s\t%d\n", (void*)cur, cur->word, cur->count);
    cur = cur->next;
  }
}

// brise cijeli rjecnik
void
destroy(Dictionary dict)
{
  if (!dict)
    return;
  Word* cur = dict->next;
  while (cur != NULL) {
    Word* del = cur;
    cur = cur->next;
    free(del->word);
    free(del);
  }
  free(dict);
}
