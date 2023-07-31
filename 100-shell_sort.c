#include "sort.h"

/**
 * shell_sort - sorts array of ints in ascending order using shell sort
 * @array: array of integers to sort using Knuth seq
 * @size: size of array
 */
void shell_sort(int *array, size_t size)
{
	size_t i, j, h;
	int temp;

	if (size < 2)
		return;

	while (h <= size / 3)
		h = (h * 3) + 1;

	while (h >= 1)
	{
		for (i = h; i < size; i++)
		{
			temp = array[i];
			j = i;
			while (j >= h && temp < array[j - h])
			{
				array[j] = array[j - h];
				j -= h;
			}
			array[j] = temp;
		}
		h = (h - 1)/ 3;
		print_array(array, size);
	}
}
