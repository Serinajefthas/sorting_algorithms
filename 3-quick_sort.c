#include "sort.h"

/**
 * quick_sort - sorts array of ints using quick sort algorithm
 * @array: array of integers
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	quick_sort_recursive(array, 0, size - 1, size);
	print_array(array, size);
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

	if (low < high)
	{
		pivot_index = partition(array, low, high, size);
		/* sorts lower part of array < pivot */
		quick_sort_recursive(array, low, pivot_index - 1, size);
		/* sorts higher values of array that > pivot */
		quick_sort_recursive(array, pivot_index + 1, high, size);
	}
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
	int pivot, i, j, temp;

	pivot = array[high];
	i = low;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			i++;
		}
	}
	temp = array[i];
	array[i] = array[high];
	array[high] = temp;
	print_array(array, size);
	return (i);
}

