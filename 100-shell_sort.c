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
	size_t increment = 1, i, j;
	int temp;

	if (!array || size < 2)
		return;

	while (increment < size)
		increment = 3 * increment + 1;
	increment = (increment - 1) / 3;

	while (increment > 0)
	{
		for (i = increment; i < size; i++)
		{
			temp = array[i];
			for (j = i; j >= increment && array[j - increment] > temp; j -= increment)
				array[j] = array[j - increment];

			array[j] = temp;
		}
		increment = (increment - 1) / 3;
		print_array(array, size);

	}

}
