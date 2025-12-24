#include "hash.h"
#include <malloc.h>
#include <stdio.h>
#include <string.h>

#define HCONST 3567892

HashTable *NewTable(int size)
{
	// kreira novu hash tablicu (alocira samu strukturu i niz pokaziva�a)

	HashTable *new = malloc(sizeof(HashTable));

	new->table = malloc(sizeof(Bin) * size);
	for (int i = 0; i < size; i++)
	{
		new->table[i]->next = NULL;
		new->table[i]->word = NULL;
	}
	new->size = size;
	new->load = 0;

	return NULL;
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
	int index = hash(word) % ht->size;
	Bin *bin_ptr = ht->table[index];
	if (bin_ptr->word == NULL)
	{
		bin_ptr->word = word;
	}
	else
	{
		while (bin_ptr->next != NULL)
		{
			if (strcmp(bin_ptr->word, word) == 0)
				return;

			bin_ptr = bin_ptr->next;
		}
		Bin *new = malloc(sizeof(Bin));
		new->word = NULL;
		new->next = NULL;

		bin_ptr->word = word;
		bin_ptr->next = new;
	}
}

int Get(HashTable *ht, char *word)
{
	// vraca 0 ili 1 ovisno o tome da li rijec postoji u tablici
	return 0;
}

void DeleteTable(HashTable *ht)
{
	// brise cijelu hash tablicu (liste na svim pretincima (rijec i element liste), pretince ...)
}