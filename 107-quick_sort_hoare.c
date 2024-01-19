#include "sort.h"

void swap_ints(int *x, int *y);
int partition_hoare(int *arr, size_t len, int low, int high);
void sort_hoare(int *arr, size_t len, int low, int high);
void quick_sort_hoare(int *arr, size_t len);

/**
 * swap_ints - an array of two interger is swapped.
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
 * partition_hoare - Order a subset of an arr of integers
 *                   according to the hoare partition scheme.
 * @arr: The array of integers.
 * @len: The extend in which the array is extended.
 * @low: The starting index of the subset to order.
 * @high: The ending index of the subset to order.
 *
 * Return: The final partition index.
 *
 * Description: Uses the last element of the partition as the pivot.
 * Prints the arr after each swap of two elements.
 */
int partition_hoare(int *arr, size_t len, int low, int high)
{
	int pivot, left, right;

	pivot = arr[high];
	for (left = low - 1, right = high + 1; left < right;)
	{
		do {
			left++;
		} while (arr[left] < pivot);
		do {
			right--;
		} while (arr[right] > pivot);

		if (left < right)
		{
			swap_ints(arr + left, arr + right);
			print_array(arr, len);
		}
	}

	return (left);
}

/**
 * sort_hoare - Implement the quicksort algorithm through recursion.
 * @arr: A sortable array of interger.
 * @len: The extend in which the array is extended.
 * @low: The starting index of the array partition to order.
 * @high: The ending index of the array partition to order.
 *
 * Description: Uses the Hoare partition scheme.
 */
void sort_hoare(int *arr, size_t len, int low, int high)
{
	int part;

	if (high - low > 0)
	{
		part = partition_hoare(arr, len, low, high);
		sort_hoare(arr, len, low, part - 1);
		sort_hoare(arr, len, part, high);
	}
}

/**
 * quick_sort_hoare - an array of interger is sorted ascendingly.
 *                    order using the quicksort algorithm.
 * @arr: An array of integers.
 * @len: The extend in which the array is extended.
 *
 * Description: Uses the Hoare partition scheme. Prints
 * the array after each swap of two elements.
 */
void quick_sort_hoare(int *arr, size_t len)
{
	if (arr == NULL || len < 2)
		return;

	sort_hoare(arr, len, 0, len - 1);
}
