#include "dictionary.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int
readWord(FILE* fd, char* buffer)
{
  int c;

  do {
    c = fgetc(fd);
    if (c == EOF)
      return 0;
  } while (!isalpha(c));

  do {
    *buffer = tolower(c);
    buffer++;
    c = fgetc(fd);
    if (c == 146)
      c = '\'';
  } while (isalpha(c) || c == '\'');

  *buffer = '\0';
  return 1;
}

int
filter(Word* w)
{
  if (!w || !w->word)
    return 0;

  return (w->count > 5 && w->count < 10 && strlen(w->word) > 3);
}

void
filterDictionary(Dictionary indict, int (*filter)(Word* w))
{
  if (!indict || !filter)
    return;

  Word* prev = indict;
  Word* cur = indict->next;
  if (cur == NULL) // list empty
    return;

  while (cur != NULL) {
    if (!filter(cur)) {
      Word* del = cur;
      cur = cur->next;
      prev->next = cur;
      free(del->word);
      free(del);
    } else {
      prev = cur;
      cur = cur->next;
    }
  }
}

int
main()
{
  FILE* fd;
  char buffer[1024];
  Dictionary dict;

  fd = fopen("liar.txt", "rt");
  if (fd == NULL) {
    printf("Error opening file.\n");
    return 1;
  }

  dict = create();
  while (readWord(fd, buffer)) {
    // printf("%s\n", buffer);
    add(dict, buffer);
  }

  fclose(fd);

  print(dict);

  printf("filtered:\n");
  filterDictionary(dict, filter);
  print(dict);

  destroy(dict);
  return 0;
}
