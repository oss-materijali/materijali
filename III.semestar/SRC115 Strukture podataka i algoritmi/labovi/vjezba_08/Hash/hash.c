#include "hash.h"
#include <malloc.h>
#include <stdio.h>
#include <string.h>

#include "string.h"

#define HCONST 3567892

HashTable *NewTable(int size)
{
	// kreira novu hash tablicu (alocira samu strukturu i niz pokaziva�a)

	HashTable *new = malloc(sizeof(HashTable));
	if (!new)
		return NULL;

	new->table = malloc(sizeof(Bin) * size);
	if (!new->table)
		return NULL;
	new->size = size;
	new->load = 0;

	for (int i = 0; i < new->size; i++)
	{
		new->table[i] = NULL;
	}

	return new;
}

unsigned int hash(char *word)
{
	// od kljuca generira hash kod
	unsigned int key = 0;
	while (*word != '\0')
	{
		key = key * HCONST + *word;
		word++;
	}
	return key;
}

void Insert(HashTable *ht, char *word)
{
	// dodaje novu rijec u listu na odgovarajucem pretincu

	// Adds a new node at the start of the list O(1)
	// Appending to the list is O(N) for collissions

	int index = hash(word) % ht->size;

	// table[i] -> old -> NULL
	Bin *new = malloc(sizeof(Bin));
	if (!new)
		return;
	new->word = word;
	new->next = ht->table[index];
	ht->table[index] = new;

	ht->load++;
	// table[i] -> new -> old -> NULL
}

int Get(HashTable *ht, char *word)
{
	// vraca 0 ili 1 ovisno o tome da li rijec postoji u tablici
	int index = hash(word) % ht->size;
	Bin *cur = ht->table[index];
	while (cur != NULL)
	{
		if (strcmp(cur->word, word) == 0)
			return 1;

		cur = cur->next;
	}

	return 0;
}

void DeleteTable(HashTable *ht)
{
	// brise cijelu hash tablicu (liste na svim pretincima (rijec i element liste), pretince ...)
	if (!ht)
		return;

	for (int i = 0; i < ht->size; i++)
	{
		Bin *cur = ht->table[i];
		while (cur != NULL)
		{
			Bin *del = cur;
			cur = cur->next;

			free(del->word);
			free(del);
		}
	}

	free(ht->table);
	free(ht);
}

/*
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
*/
