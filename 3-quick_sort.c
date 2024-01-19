#include "sort.h"

void swap_ints(int *a, int *b);
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

/**
 * swap_ints - Exchange the values of two integers in an array.
 * @a: The pointer to the first integer to be exchanged.
 * @b: The pointer to the second integer to be exchanged.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * lomuto_partition - Sort a portion of an array of integers using
 *                    the lomuto partition method (last element as pivot).
 * @array: The index into the interger array 
 * @size: The count of components comprising the array
 * @left: The index of the first element of the portion to sort.
 * @right: The index of the last element of the portion to sort.
 *
 * Return: The index of the pivot after partitioning.
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *pivot, above, below;

	pivot = array + right;
	for (above = below = left; below < right; below++)
	{
		if (array[below] < *pivot)
		{
			if (above < below)
			{
				swap_ints(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}

	if (array[above] > *pivot)
	{
		swap_ints(array + above, pivot);
		print_array(array, size);
	}

	return (above);
}

/**
 * lomuto_sort - Apply the quicksort algorithm recursively.
 * @array: The pointer to the array of integers to sort.
 * @size: The count of components comprising the array.
 * @left: The index of the first element of the array segment to be sorted.
 * @right: The index of the last element of the array segment to be sorted.
 *
 * Description: Uses the Lomuto partition method.
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, part - 1);
		lomuto_sort(array, size, part + 1, right);
	}
}

/**
 * quick_sort - Arrange an array of integers in ascending
 *              order using the quicksort algorithm.
 * @array: The index into the integers array.
 * @size: The count of components comprising the array.
 *
 * Description: Uses the Lomuto partition method. Prints
 *              the array after each exchange of two elements.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
