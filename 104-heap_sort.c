#include "sort.h"

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
 * heapify - create heaps
 * @array: array to be sorted
 * @start: first index of array of integers
 * @end: last index of array of integers
 * @size: length of array
 *
 * Return: index of the pivot integer
 */

void heapify(int *array, int start, int end, size_t size)
{
	int big = end;
	int left = 2 * end + 1;
	int right = 2 * end + 2;

	if (left < start && array[left] > array[big])
		big = left;

	if (right < start && array[right] > array[big])
		big = right;

	if (big != end)
	{
		swap(&array[end], &array[big]);
		print_array(array, size);
		heapify(array, start, big, size);
	}
}

/**
 * heap_sort - sorts an array of integers in ascending order
 * using the Heap sort algorithm
 * @array: array to sort
 * @size: length of array
 *
 * Return: Nothing
 */

void heap_sort(int *array, size_t size)
{
	int i;

	if (!array || size < 2)
		return;

	for (i = size / 2 - 1; i >= 0; i--)
		heapify(array, size, i, size);

	for (i = size - 1; i >= 0; i--)
	{
		swap(&array[0], &array[i]);

		if (i != 0)
			print_array(array, size);

		heapify(array, i, 0, size);
	}
}
