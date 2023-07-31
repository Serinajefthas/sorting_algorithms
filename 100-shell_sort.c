#include "sort.h"

/**
 * shell_sort - sorts array of ints in ascending order using shell sort
 * @array: array of integers to sort using Knuth seq
 * @size: size of array
 */
void shell_sort(int *array, size_t size)
{
	size_t i, j, temp, h;

	if (size < 2)
		return;

	while (h <= size / 3)
		h = (h * 3) + 1;

	while (h >= 1)
	{
		for (x = h; x < size; x++)
		{
			j = i;
			while (j > h - 1 && array[j] < array[j - h])
			{
				if (array[j] != array[j - h])
				{
					temp = array[j];
					array[j] = array[j - h];
					array[j - h] = temp;
				}
				j -= h;
			}
		}
		h = h / 3;
		print_array(array, size);
	}
}
