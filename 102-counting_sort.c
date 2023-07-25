#include "sort.h"

/**
 * counting_sort -  sorts an array of integers in ascending order
 * using the Counting sort algorithm
 * @array: array to be sorted
 * @size: length of array
 *
 * Return: Nothing
 */

void counting_sort(int *array, size_t size)
{
	int *count, *copy, max, j;
	size_t i;

	if (!array || size < 2)
		return;
	copy = malloc((size) * sizeof(int));
	for (i = 0; i < size; i++)
		copy[i] = array[i];

	max = array[0];
	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	max++;

	count = malloc(max * sizeof(int));
	if (!count)
		return;

	for (j = 0; j < max; j++)
		count[j] = 0;

	for (i = 0; i < size; i++)
		count[array[i]]++;

	for (j = 1; j < max; j++)
		count[j] += count[j - 1];
	print_array(count, max);

	for (j = size - 1; j >= 0; j--)
	{
		copy[count[array[j]] - 1] = array[j];
		count[array[j]]--;
	}
	for (i = 0; i < size; i++)
		array[i] = copy[i];
	free(count);
	free(copy);
}
