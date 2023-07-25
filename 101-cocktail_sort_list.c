#include "sort.h"

void swap(int *first, int *second);
/**
 * cocktail_sort_list - sorts a doubly linked list of integers in
 * ascending order using the Cocktail shaker sort algorithm
 * @list: doubly linked list
 *
 * Return: Nothing
 */

void cocktail_sort_list(listint_t **list)
{
	listint_t *temp;
	int swap;

	if (!list || !*list || !(*list)->next)
		return;

	while (swap != 0)
	{
		swap = 0;
		temp = *list;
		while (temp->next != NULL)
		{
			if (temp->n > temp->next->n)
			{
				if (temp->prev != NULL)
					temp->prev->next = temp->next;
				temp->next->prev = temp->prev;
				if (temp->next->next != NULL)
					temp->next->next->prev = temp;
				temp->prev = temp->next;
				temp->next = temp->prev->next;
				temp->prev->next = temp;
				if (temp->prev == NULL)
					*list = temp;
				swap = 1;
				print_list(*list);
				temp = temp->prev;
			}
			temp = temp->next;
		}
		temp = temp->prev;

		while (temp->prev != NULL)
		{
			if (temp->prev->n > temp->n)
			{
				temp->next->prev = temp->prev;
				temp->prev->next = temp->next;
				if (temp->prev->prev != NULL)
					temp->prev->prev->next = temp;
				temp->next = temp->prev;
				temp->prev = temp->next->prev;
				temp->next->prev = temp;
				if (temp->prev == NULL)
					*list = temp;
				swap = 1;
				print_list(*list);
				temp = temp->next;
			}
			temp = temp->prev;
		}
		temp = temp->next;

	}
}

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

