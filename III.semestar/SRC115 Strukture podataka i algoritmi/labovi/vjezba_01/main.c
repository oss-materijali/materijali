#include <stdio.h>
#include <stdlib.h>

#define _CRT_SECURE_NO_WARNINGS

int mystrlen(char *str) {
  int i = 0;
  while (str[i] != '\0')
    i++;
  return i;
}

void mystrcpy(char *dest, char *src) {
  int i = 0;
  while (src[i] != '\0') {
    dest[i] = src[i];
    i++;
  }
  dest[i] = '\0';
}

int mystrcmp(char *str_a, char *str_b) {
  int i = 0;
  while (str_a[i] != '\0' || str_b[i] != '\0') {
    if (str_a[i] < str_b[i])
      return -1;
    else if (str_b[i] < str_a[i])
      return 1;
    i++;
  }
  return 0;
}

void mystrcat(char *dest, char *src) {
  int j = mystrlen(dest);
  int i = 0;
  while (src[i] != '\0')
    dest[j++] = src[i++];
  dest[j] = '\0';
}

char *mystrstr(char *str_a, char *str_b) {
  int i = 0;
  int j = 0;
  while (str_a[i] != '\0') {
    if (str_a[i] == str_b[j])
      j++;
    else
      j = 0;

    if (str_b[j] == '\0') {
      // moves the pointer to begining of str_b in str_a
      return (str_a + i - (j - 1));
    }
    i++;
  }
  return NULL;
}

void reverse(char *dest, char *src) {
  int i = mystrlen(src) - 1;
  int j = 0;
  while (i + 1)
    dest[j++] = src[i--];
  dest[j] = '\0';
}

int main(void) {
  // this is a mess.

  // mystrlen
  printf("\n### mystrlen ###\n");
  char str[100] = "abcd";
  char str_a[] = "ef";
  printf("%s (len: %d)\n", str, mystrlen(str));

  // mystrcpy (dest needs to have enough space to store src)
  printf("\n### mystrcpy ###\n");
  printf("str: %s, str_a: %s\n", str, str_a);
  mystrcpy(str, str_a);
  printf("str: %s, str_a: %s\n", str, str_a);

  // mystrcmp
  printf("\n### mystrcmp ###\n");
  char str_h[100] = "123";
  char str_j[] = "133";
  char str_i[] = "1135";
  char str_k[] = "1234";
  printf("%s, %s (%d)\n", str_h, str_j, mystrcmp(str_h, str_j));
  printf("%s, %s (%d)\n", str_h, str_i, mystrcmp(str_h, str_i));
  printf("%s, %s (%d)\n", str, str_a, mystrcmp(str, str_a));
  printf("%s, %s (%d)\n", str_h, str_k, mystrcmp(str_h, str_k));

  // mystrcat
  printf("\n### mystrcat ###\n");
  printf("%s, %s \n", str_h, str_i);
  mystrcat(str_h, str_i);
  printf("%s, %s \n", str_h, str_i);

  // mystrstr
  printf("\n### mystrstr ###\n");
  char str_l[] = "fabcffaffabcdff";
  char str_o[] = "abcd";
  printf("%s, %s\n", str_l, str_o);
  printf("%s\n", mystrstr(str_l, str_o));

  // reverse (dest needs to have enough space to store src)
  char str_m[100] = "fffffffff";
  char str_n[] = "abcd";
  printf("\n### reverse ###\n");
  printf("%s, %s\n", str_m, str_n);
  reverse(str_m, str_n);
  printf("%s, %s\n", str_m, str_n);

  return 0;
}
