#include "sort.h"

/**
 * bubble_sort - sorts an array of integers using bubble sort
 * @array: array of integers
 * @size: length of the array
 *
 * Return: Nothing
 */

void bubble_sort(int *array, size_t size)
{
	size_t i;
	int temp, swap;

	if (!array || size < 2)
		exit(0);

	while (swap)
	{
		swap = 0;
		for (i = 0; i < (size - 1); i++)
		{
			if (array[i] > array[i + 1])
			{
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				swap = 1;
				print_array(array, size);
			}
		}
	}
}
