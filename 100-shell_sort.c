#include "sort.h"

/**
 * swap - Swap two elements in an array.
 * @x: The first element to swap.
 * @y: The second element to swap.
 */
void swap(int *x, int *y)
{
	int temp;

	temp = *x;
	*x = *y;
	*y = temp;
}

/**
 * shell_sort - Sort an array of integers in ascending
 *              order using the shell sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Uses the Knuth interval sequence.
 */
void shell_sort(int *array, size_t size)
{
	size_t interval, k, l;

	if (array == NULL || size < 2)
		return;

	for (interval = 1; interval < (size / 3);)
		interval = interval * 3 + 1;

	for (; interval >= 1; interval /= 3)
	{
		for (k = interval; k < size; k++)
		{
			l = k;
			while (l >= interval && array[l - interval] > array[l])
			{
				swap(array + l, array + (l - interval));
				l -= interval;
			}
		}
		print_array(array, size);
	}
}
