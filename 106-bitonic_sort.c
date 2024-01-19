#include "sort.h"

void swap_ints(int *x, int *y);
void bitonic_merge(int *array, size_t size, size_t start, size_t len,
		char dir);
void bitonic_seq(int *array, size_t size, size_t start, size_t len, char dir);
void bitonic_sort(int *array, size_t size);

/**
 * swap_ints - an array of two intergers is swapped.
 * @x: The first integer to swap.
 * @y: The second integer to swap.
 */
void swap_ints(int *x, int *y)
{
	int temp;

	temp = *x;
	*x = *y;
	*y = temp;
}

/**
 * bitonic_merge - Sort a bitonic sequence inside an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 * @start: The index at which the array sequence begins to be sorted.
 * @len: The length of the sequence to sort.
 * @dir: The manner in which to organize.
 */
void bitonic_merge(int *array, size_t size, size_t start, size_t len,
		char dir)
{
	size_t i, gap = len / 2;

	if (len > 1)
	{
		for (i = start; i < start + gap; i++)
		{
			if ((dir == UP && array[i] > array[i + gap]) ||
			    (dir == DOWN && array[i] < array[i + gap]))
				swap_ints(array + i, array + i + gap);
		}
		bitonic_merge(array, size, start, gap, dir);
		bitonic_merge(array, size, start + gap, gap, dir);
	}
}

/**
 * bitonic_seq - Partition a sequence of intergers into their bitonic form.
 * @array: An array of integers.
 * @size: The size of the array.
 * @start: block starting index in the building bitonic sequence.
 * @len: The length of a block of the building bitonic sequence.
 * @dir: The direction to sort the bitonic sequence block in.
 */
void bitonic_seq(int *array, size_t size, size_t start, size_t len, char dir)
{
	size_t half = len / 2;
	char *str = (dir == UP) ? "UP" : "DOWN";

	if (len > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", len, size, str);
		print_array(array + start, len);

		bitonic_seq(array, size, start, half, UP);
		bitonic_seq(array, size, start + half, half, DOWN);
		bitonic_merge(array, size, start, len, dir);

		printf("Result [%lu/%lu] (%s):\n", len, size, str);
		print_array(array + start, len);
	}
}

/**
 * bitonic_sort - an interger sorted ascendingly
 *                sorting by means of bitonic algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap. Only works for
 * size = 2^k where k >= 0 (ie. size equal to powers of 2).
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic_seq(array, size, 0, size, UP);
}
