#include "sort.h"

/**
 * shell_sort - sorts an array of integers in ascending order using
 * the Shell sort algorithm, using the Knuth sequence
 * @array: array to sort
 * @size: length of array
 *
 * Return: Nothing
 */

void shell_sort(int *array, size_t size)
{
	size_t increment = 1, i;
	int j, k;

	if (!array || size < 2)
		return;

	while (increment <= (size - 1) / 9)
		increment = 3 * increment + 1;

	while (increment >= 1)
	{
		for (i = increment; i < size; i++)
		{
			k = array[i];
			for (j = i - increment; j >= 0 && k < array[j]; j = j - increment)
				array[j + increment] = array[j];

			array[j + increment] = k;
		}
		increment = increment / 3;
		print_array(array, size);

	}

}
