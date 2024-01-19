#include "sort.h"

/**
 * swap - Two elements of an arrays are swapped
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
 * selection_sort - Sort an array of integers in ascending order
 *                  using the selection sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap.
 */
void selection_sort(int *array, size_t size)
{
	int *smallest;
	size_t i, k;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		smallest = &array[i];
		for (k = i + 1; k < size; k++)
			smallest = (array[k] < *smallest) ? &array[k] : smallest;

		if (smallest != &array[i])
		{
			swap(&array[i], smallest);
			print_array(array, size);
		}
	}
}
