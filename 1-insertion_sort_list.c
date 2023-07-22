#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers in
 * ascending order using the Insertion sort algorithm
 * @list: doubly linked list
 *
 * Return: Nothing
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *temp, *temp2;

	if (!list || !(*list) || !(*list)->next)
		return;
	temp = *list;
	temp2 = (*list)->next;

	while (temp2)
	{
		while (temp && (temp2->n < temp->n))
		{
			temp->next = temp2->next;
			if (temp2->next != NULL)
				temp2->next->prev = temp;
			temp2->next = temp;
			temp2->prev = temp->prev;
			if (temp->prev != NULL)
				temp->prev->next = temp2;
			temp->prev = temp2;
			if (temp2->prev == NULL)
				*list = temp2;
			print_list(*list);
			temp = temp2->prev;
		}
		temp = temp2;
		temp2 = temp2->next;
	}
}
