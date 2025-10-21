#include <stdio.h>
#include <stdlib.h>

int* podniz(int* niz, int start, int stop) {

	int *slice = (int*)malloc((stop - start + 1) * sizeof(int));
	if (!slice)
		return NULL;

	int j = 0;
	for (int i = start; i <= stop; i++)
	{
		slice[j++] = niz[i];
	}

	return slice;
}

int* filtriraj(int *niz, int n, int th, int *nth) {
	int* filtered = (int*)malloc(n * sizeof(int));
	if (!filtered)
		return NULL;
	int j = 0;
	for (int i = 0; i < n; i++)
	{
		if (niz[i] < th) {
			filtered[j++] = niz[i];
		}
	}
	*nth = j;
	return filtered;
}

// int** podijeli(int *niz, int n) {

// }

int main(void) {
	// podniz()
	printf("podniz():\n");
	int arr_a[] = {1, 2, 3, 4, 5, 6, 7};
	int *slice_a = podniz(arr_a, 1, 4);
	if (!slice_a)
		return 1;

	for (int i = 0; i < 4; i++)
		printf("%d ", slice_a[i]);
	printf("\n");

	printf("\n");

	// filtriraj()
	printf("filtriraj():\n");
	int arr_b[] = { 10, 30, 40, 20, 60, 70, 50 };
	int filtered_b_len;
	int *filtered_b = filtriraj(arr_b, (sizeof(arr_b) / sizeof(arr_b[0])), 40, &filtered_b_len);
	if (!filtered_b)
		return 2;

	for (int i = 0; i < filtered_b_len; i++)
		printf("%d ", filtered_b[i]);
	printf("\n");

	free(filtered_b);
	free(slice_a);
	return 0;
}
