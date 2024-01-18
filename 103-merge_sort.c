#include "sort.h"

void merge_sort(int *array, size_t size);
void merge_sort_recursive(int *array, int *buffer, size_t start, size_t end);
void merge_subarray(int *array, int *buffer, size_t start, size_t middle,
		    size_t end);

/**
 * merge_sort - Sort an array of integers in ascending order
 *              using the merge sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Implements the top-down merge sort algorithm.
 */
void merge_sort(int *array, size_t size)
{
	int *buffer;

	if (array == NULL || size < 2)
		return;

	buffer = malloc(sizeof(int) * size);
	if (buffer == NULL)
		return;

	merge_sort_recursive(array, buffer, 0, size);

	free(buffer);
}

/**
 * merge_sort_recursive - Implement the merge sort algorithm through recursion.
 * @array: An array of integers to sort.
 * @buffer: A buffer to store the sorted result.
 * @start: The start index of the subarray.
 * @end: The end index of the subarray.
 */
void merge_sort_recursive(int *array, int *buffer, size_t start, size_t end)
{
	size_t middle;

	if (end - start > 1)
	{
		middle = start + (end - start) / 2;
		merge_sort_recursive(array, buffer, start, middle);
		merge_sort_recursive(array, buffer, middle, end);
		merge_subarray(array, buffer, start, middle, end);
	}
}

/**
 * merge_subarray - Sort a subarray of integers.
 * @array: An array of integers to sort.
 * @buffer: A buffer to store the sorted subarray.
 * @start: The start index of the array.
 * @middle: The middle index of the array.
 * @end: The end index of the array.
 */
void merge_subarray(int *array, int *buffer, size_t start, size_t middle,
		    size_t end)
{
	size_t i, j, k = 0;

	printf("Merging...\n[left]: ");
	print_array(array + start, middle - start);

	printf("[right]: ");
	print_array(array + middle, end - middle);

	for (i = start, j = middle; i < middle && j < end; k++)
		buffer[k] = (array[i] < array[j]) ? array[i++] : array[j++];
	for (; i < middle; i++)
		buffer[k++] = array[i];
	for (; j < end; j++)
		buffer[k++] = array[j];
	for (i = start, k = 0; i < end; i++)
		array[i] = buffer[k++];

	printf("[Done]: ");
	print_array(array + start, end - start);
}
