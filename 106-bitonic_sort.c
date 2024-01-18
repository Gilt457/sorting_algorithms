#include "sort.h"

void swap_ints(int *x, int *y);
void bitonic_merge(int *array, size_t size, size_t start, size_t len,
		char dir);
void bitonic_seq(int *array, size_t size, size_t start, size_t len, char dir);
void bitonic_sort(int *array, size_t size);

/**
 * swap_ints - Swap two integers in an array.
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
 * @start: The starting index of the sequence in array to sort.
 * @len: The length of the sequence to sort.
 * @dir: The direction to sort in.
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
 * bitonic_seq - Convert an array of integers into a bitonic sequence.
 * @array: An array of integers.
 * @size: The size of the array.
 * @start: The starting index of a block of the building bitonic sequence.
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
 * bitonic_sort - Sort an array of integers in ascending
 *                order using the bitonic sort algorithm.
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
