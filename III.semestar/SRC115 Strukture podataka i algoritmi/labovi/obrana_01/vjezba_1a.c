#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1. Vježba
// a.) Napisati funkciju koja iz stringa izdvaja zadnju riječ u novi string i
// vraća je.
// b.) Napisati funkciju koja prima string sa dvije riječi i vraća niz
// od dva nova stringa sa svakom riječi posebno.

char *get_last_word(char str[]) {
  int len = strlen(str);
  int new_len = 0;
  int copied_i = 0;
  for (int i = len; i >= 0; i--) {
    new_len++;
    if (str[i] == ' ' || str[i] == '\t') {
      copied_i = i + 1;
      break;
    }
    copied_i = i;
  }
  char *new_str = (char *)malloc((new_len + 1) * sizeof(char));
  if (!new_str)
    return NULL;

  strcat(new_str, str + copied_i);

  return new_str;
}

int main(void) {
  char str_a[] = "example sentence: word1 word2 word3";
  char str_b[] = "examplesentence:word1word2word3";

  char *last_word_a = get_last_word(str_a);
  char *last_word_b = get_last_word(str_b);

  printf("str_a: %s\nstr_b: %s\nlast_word_a: %s\nlast_word_b: %s\n", str_a,
         str_b, last_word_a, last_word_b);
  return 0;
}
