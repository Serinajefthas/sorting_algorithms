#include "sort.h"

/**
 * insertion_sort_list - sorts doubly linked list in ascending order
 * @list: doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr, *temp;

	if (list == NULL)
		return;
	curr = *list;
	while (curr != NULL)
	{
		while (curr->next && (curr->n > (curr->next->n)))
		{
			temp = curr->next;
			curr->next = (temp)->next;
			(temp)->prev = curr->prev;
			if (curr->prev != NULL)
				curr->prev->next = temp;
			if (temp->next != NULL)
				temp->next->prev = curr;
			curr->prev = temp;
			temp->next = curr;
			if (temp->prev != NULL)
				curr = temp->prev;
			else if (temp->prev == NULL)
				*list = temp;
			print_list(*list);
		}
		curr = curr->next;
	}
}
