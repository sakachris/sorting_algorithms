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

size_t partition(int *array, size_t start, size_t end)
{
	int pivot;
	size_t idx, i;

	pivot = array[end];
	idx = start;
	printf("pivot = %d  idx = %ld\n", pivot, idx);

	for (i = start; i < end; i++)
	{
		if (array[i] <= pivot)
		{
			if (i != idx)
			{
				swap(&array[i], &array[idx]);
				idx++;
			}
		}
	}
	swap(&array[idx], &array[end]);
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

void quick_sort_rec(int *array, size_t start, size_t end)
{
	size_t pvt_idx;

	if (start < end)
	{
		pvt_idx = partition(array, start, end);
		printf("Got pivot index: %ld\n", pvt_idx);
		quick_sort_rec(array, start, pvt_idx - 1);
		printf("left portion\n");
		quick_sort_rec(array, pvt_idx + 1, end);
	}
	printf("quick_sort_rec\n");
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

	printf("before recusrsion\n");
	quick_sort_rec(array, start, end);
	printf("quick_sort\n");
}
