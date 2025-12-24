#include <stdio.h>
#include <malloc.h>
#include "bstree.h"

BSTree NewBSTree()
{
	// Novo prazno stablo
	return NULL;
}

void AddNode(BSTree *bst, char *word)
{
	// Rekurzivno se tra�i mjesto za novi �vor u stablu. Ako rije� postoji u stablu, ne dodaje se.
	// bst parametar je dvostruki pokaziva�.

	BSTree *tmp = bst;
	while (1)
	{
		if (*bst = NULL)
		{
			Node *new = malloc(sizeof(Node));
			new->word = word;
			new->left = NULL;
			new->right = NULL;
			*tmp = new;
			return; // adds leaf
		}
		int word_cmp = strcmp(word, (*tmp)->word);
		if (word_cmp < 0)
		{
			tmp = &((*tmp)->left);
		}
		else if (word_cmp > 0)
		{
			tmp = &((*tmp)->left);
		}
	}
}

int BSTHeight(BSTree bst)
{
	// Rekurzivno se prolazi cijelo stablo da bi se prona�la najdu�a grana (visina stabla).

	if (bst == NULL)
		return 0;

	int l_height = BSTHeight(bst->left);
	int r_height = BSTHeight(bst->right);

	return 1 + (l_height > r_height ? l_height : r_height);
}

void PrintBSTree(BSTree bst)
{
	// Ispisuje rije�i u stablu na ekran po abecednom redu.
	// In-order �etnja po stablu (lijevo dijete, �vor, desno dijete)

	if (bst == NULL)
		return;

	PrintBSTree(bst->left);
	printf("%s ", bst->word);
	PrintBSTree(bst->right);
}

void SaveBSTree(BSTree bst, FILE *fd)
{
	// Snima rije� po rije� iz stabla u tekstualnu datoteku. Rije�i su odvojene razmakom.
	// Pre-order �etnja po stablu (ttenutni �vor pa djeca)

	if (bst == NULL)
		return;

	fprintf(fd, "%s ", bst->word);
	SaveBSTree(bst->left, fd);
	SaveBSTree(bst->right, fd);
}

void DeleteBSTree(BSTree bst)
{
	// Bri�e stablo (string word i sam �vor) iz memorije.
	// Post-order �etnja po stablu (prvo djeca pa trenutni �vor)

	if (bst == NULL)
		return;

	DeleteBSTree(bst->left);
	DeleteBSTree(bst->right);

	free(bst->word);
	free(bst);
}

int readWord(FILE *fd, char *buffer);

BSTree LoadBSTree(FILE *fd)
{
	// U�itava rije� po rije� iz tekstualne datoteke i dodaje ih u stablo preko AddNode() funkcije.
	// Rije� duplicirati sa strdup().

	char buffer[1024];
	BSTree bst = NewBSTree();

	while (readWord(fd, buffer))
	{
		AddNode(&bst, buffer);
	}

	return bst;
}

int readWord(FILE *fd, char *buffer)
{
	int c;

	do
	{
		c = fgetc(fd);
		if (c == EOF)
			return 0;
	} while (!isalpha(c));

	do
	{
		*buffer = tolower(c);
		buffer++;
		c = fgetc(fd);
		if (c == 146)
			c = '\'';
	} while (isalpha(c) || c == '\'');

	*buffer = '\0';
	return 1;
}