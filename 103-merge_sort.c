#include "sort.h"
#include <stdio.h>

/**
 * merge - merges a list of sorted arrays
 * @array: array to be sorted
 * @start: first index of array of integers
 * @end: last index of array of integers
 * @mid: middle index of array of integers
 * @size: length of array
 *
 * Return: index of the pivot integer
 */

void merge(int *array, int start, int mid, int end, size_t size)
{
	int *copy;
	int i, j, k;

	copy = malloc(size * sizeof(int));
	if (!copy)
		return;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + start, mid - start);
	printf("[right]: ");
	print_array(array + mid, end - mid);
	for (i = start, j = mid, k = start; k < end; k++)
	{
		if (i < mid && (j >= end || array[i] <= array[j]))
		{
			copy[k] = array[i];
			i++;
		}
		else
		{
			copy[k] = array[j];
			j++;
		}
	}

	for (k = start; k < end; k++)
		array[k] = copy[k];

	printf("[Done]: ");
	print_array(array + start, end - start);
	free(copy);
}

/**
 * merge_sort_rec - recursively divides partitons of array
 * @array: array to sort
 * @start: first index of portion of array
 * @end: last index of portion of array
 * @size: length of array
 *
 * Return: Nothing
 */

void merge_sort_rec(int *array, int start, int end, size_t size)
{
	int mid;

	if (end - start < 2)
		return;
	mid = (start + end) / 2;
	merge_sort_rec(array, start, mid, size);
	merge_sort_rec(array, mid, end, size);
	merge(array, start, mid, end, size);
}

/**
 * merge_sort - sorts an array of integers in ascending order
 * using the Merge sort algorithm
 * @array: array to sort
 * @size: length of array
 *
 * Return: Nothing
 */

void merge_sort(int *array, size_t size)
{
	size_t start = 0, end = size;

	if (!array || size < 2)
		return;

	merge_sort_rec(array, start, end, size);
}
