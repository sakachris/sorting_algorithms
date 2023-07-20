#include "sort.h"
#include <stdio.h>

/**
 * swap - swaps two integers
 * @first: first integer
 * @second: second integer
 *
 * Return: Nothing
 */

void swap(int *first, int *second)
{
	int temp = *first;

	*first = *second;
	*second = temp;
}

/**
 * partition - partitions a list for quick sort
 * @array: array to be sorted
 * @start: first index of array of integers
 * @end: last index of array of integers
 *
 * Return: index of the pivot integer
 */

size_t partition(int *array, int start, int end, size_t n)
{
	int pivot;
	int idx, i;

	(void)n;
	pivot = array[end];
	idx = start;

	for (i = start; i < end; i++)
	{
		if (array[i] <= pivot)
		{
			swap(&array[i], &array[idx]);
			idx++;
		}
	}
	swap(&array[idx], &array[end]);
	print_array(array, n);
	return (idx);
}

/**
 * quick_sort_rec - recursively sorts partitons of array
 * @array: array to sort
 * @start: first index of portion of array
 * @end: last index of portion of array
 *
 * Return: Nothing
 */

void quick_sort_rec(int *array, int start, int end, size_t size)
{
	int pvt_idx;

	if (start < end)
	{
		pvt_idx = partition(array, start, end, size);
		quick_sort_rec(array, start, pvt_idx - 1, size);
		/*print_array(array, size);*/
		quick_sort_rec(array, pvt_idx + 1, end, size);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order
 * using the Quick sort algorithm
 * @array: array to sort
 * @size: length of array
 *
 * Return: Nothing
 */

void quick_sort(int *array, size_t size)
{
	size_t start = 0, end = size - 1;

	quick_sort_rec(array, start, end, size);
}
