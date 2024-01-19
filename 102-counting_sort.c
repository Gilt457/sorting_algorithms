#include "sort.h"

/**
 * find_max - Find the maximum value in an integer array.
 * @arr: A reference to an array of interger.
 * @n: The count of components comprising the array.
 *
 * Return: The largest integer in the array.
 */
int find_max(int *arr, int n)
{
	int i, max;

	max = arr[0];
	for (i = 1; i < n; i++)
	{
		if (arr[i] > max)
			max = arr[i];
	}

	return (max);
}

/**
 * counting_sort - Sort an integer array in ascending order
 *                 using the counting sort algorithm.
 * @arr: A reference to an array of intergers.
 * @n: The count of components comprising the array.
 *
 * Description: Prints the counting array after setting it up.
 */
void counting_sort(int *arr, size_t n)
{
	int *cnt, *srt, max, i;

	if (arr == NULL || n < 2)
		return;

	srt = malloc(sizeof(int) * n);
	if (srt == NULL)
		return;
	max = find_max(arr, n);
	cnt = malloc(sizeof(int) * (max + 1));
	if (cnt == NULL)
	{
		free(srt);
		return;
	}

	for (i = 0; i <= max; i++)
		cnt[i] = 0;
	for (i = 0; i < (int)n; i++)
		cnt[arr[i]]++;
	for (i = 0; i <= max; i++)
		cnt[i] += cnt[i - 1];
	print_array(cnt, max + 1);

	for (i = 0; i < (int)n; i++)
	{
		srt[cnt[arr[i]] - 1] = arr[i];
		cnt[arr[i]]--;
	}

	for (i = 0; i < (int)n; i++)
		arr[i] = srt[i];

	free(srt);
	free(cnt);
}
