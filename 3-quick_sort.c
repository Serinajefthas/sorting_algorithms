#include "sort.h"

/**
 * quick_sort - sorts array of ints using quick sort algorithm
 * @array: array of integers
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	size_t i, j, temp, pivot;
