#include "sort.h"

/**
 * swop - swops two items in array
 * @array: array to edit
 * @x: left item index
 * @y: right item index
 */
void swop(int *array, size_t x, size_t y)
{
	int temp;

	if (array != NULL)
	{
		temp = array[x];
		array[x] = array[y];
		array[y] = temp;
	}
}

/**
 * quick_sort - sorts array of ints using quick sort algorithm
 * @array: array of integers
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	if (array != NULL)
		quick_sort_recursive(array, 0, size - 1, size);
}

/**
 * quick_sort_recursive - recursively 'divide and conquer' quick sort
 * @array: array to sort
 * @low: lowest value in the current subarray(ie not main array)
 * @high: highest value in current subarray(ie not main array)
 * @size: size of array
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	int pivot_index;

	if (low >= high || array == NULL)
		return;

	pivot_index = partition(array, low, high, size);
	quick_sort_recursive(array, low, pivot_index - 1, size);
	quick_sort_recursive(array, pivot_index + 1, high, size);
}

/**
 * partition - partitions part of current array around pivot
 * @array: array of integers to sort
 * @low: low value left of pivot
 * @high: high value right of pivot
 * @size: size of array
 * Return: value of pivot
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivot, i, j;

	pivot = array[high];
	i = low;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			if (i != j)
			{
				swop(array, i, j);
				print_array(array, size);
			}
			i++;
		}
	}
	if (i != high)
	{
		swop(array, i, high);
		print_array(array, size);
	}
	return (i);
}
