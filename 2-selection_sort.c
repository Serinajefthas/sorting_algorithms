#include "sort.h"

/**
 * selection_sort - sorts array ints using slection sort algorithm
 * (compares 2 elements in array, and swops their positions so
 * LHS is smaller)
 * @array: pointer to array of integers
 * @size: size of array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, temp, min_index;

	for (i = 0; i < size - 1; i++)
	{
		min_index = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_index])
				min_index = j;
		}
		if (min_index != i)
		{
			temp = array[i];
			array[i] = array[min_index];
			array[min_index] = temp;
			print_array(array, size);
		}
	}
}
