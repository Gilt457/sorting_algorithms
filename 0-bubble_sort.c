#include "sort.h"

/**
 * swap - Exchange two integers in an array.
 * @x: The first integer to exchange.
 * @y: The second integer to exchange.
 */
void swap(int *x, int *y)
{
	int aux;

	aux = *x;
	*x = *y;
	*y = aux;
}

/**
 * bubble_sort - Sort an array of integers in ascending order.
 * @array: An array of integers to be sort.
 * @size: The size of the array.
 *
 * Description: Prints the array after each exchange.
 */
void bubble_sort(int *array, size_t size)
{
	size_t j, n = size;
	bool sorted = false;

	if (array == NULL || size <= 1)
		return;

	while (!sorted)
	{
		sorted = true;
		for (j = 0; j < n - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(array + j, array + j + 1);
				print_array(array, size);
				sorted = false;
			}
		}
		n = n-1;
	}
}
