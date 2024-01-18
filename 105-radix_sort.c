#include "sort.h"

int find_max(int *array, int size);
void counting_sort_radix(int *array, size_t size, int sig, int *buff);
void radix_sort(int *array, size_t size);

/**
 * find_max - Find the largest element in an integer array.
 * @array: A pointer to an integer array.
 * @size: The number of elements in the array.
 *
 * Return: The largest integer in the array.
 */
int find_max(int *array, int size)
{
	int max, i;

	for (max = array[0], i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	return (max);
}

/**
 * counting_sort_radix - Sort an integer array by a specific digit
 *                        using the counting sort algorithm.
 * @array: A pointer to an integer array.
 * @size: The number of elements in the array.
 * @sig: The digit to sort by.
 * @buff: A pointer to a buffer array to store the sorted array.
 */
void counting_sort_radix(int *array, size_t size, int sig, int *buff)
{
	int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t i;

	for (i = 0; i < size; i++)
		count[(array[i] / sig) % 10] += 1;

	for (i = 0; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size - 1; (int)i >= 0; i--)
	{
		buff[count[(array[i] / sig) % 10] - 1] = array[i];
		count[(array[i] / sig) % 10] -= 1;
	}

	for (i = 0; i < size; i++)
		array[i] = buff[i];
}

/**
 * radix_sort - Sort an integer array in ascending order
 *              using the radix sort algorithm.
 * @array: A pointer to an integer array.
 * @size: The number of elements in the array.
 *
 * Description: Uses the LSD radix sort algorithm. Prints
 * the array after each digit increment.
 */
void radix_sort(int *array, size_t size)
{
	int max, sig, *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	max = find_max(array, size);
	for (sig = 1; max / sig > 0; sig *= 10)
	{
		counting_sort_radix(array, size, sig, buff);
		print_array(array, size);
	}

	free(buff);
}
