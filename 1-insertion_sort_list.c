#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending
 *                       order using the Insertion sort algorithm.
 * @list: Double pointer to the head of the list.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *swap, *current, *prev;

	if (list == NULL || *list == NULL || *(list)->next == NULL)
		return;

	current = (*list)->next;

	while (current != NULL)
	{
		swap = current;

		while ((swap->prev != NULL) && (swap->n < swap->prev->n))
		{
			prev = swap->prev;

			if (prev->prev != NULL)
				prev->prev->next = swap;
			if (swap->next != NULL)
				swap->next->prev = prev;

			prev->next = swap->next;
			swap->prev = prev->prev;
			swap->next = prev;
			prev->prev = swap;

			if (swap->prev == NULL)
				*list = swap;

			print_list(*list);
		}
		current = current->next;
	}
}
