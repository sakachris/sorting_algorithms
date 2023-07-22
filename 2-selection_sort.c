#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending order
 * using the Selection sort algorithm
 * @array: array to sort
 * @size: length of array
 */

void selection_sort(int *array, size_t size)
{
	int temp;
	size_t i, j, m_pos;

	if (!array || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		m_pos = i;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[m_pos])
				m_pos = j;
		}

		if (m_pos != i)
		{
			temp = array[i];
			array[i] = array[m_pos];
			array[m_pos] = temp;
			print_array(array, size);
		}
	}
}
