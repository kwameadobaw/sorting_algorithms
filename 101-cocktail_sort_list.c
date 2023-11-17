#include "sort.h"

/**
 * cocktail_sort_list - Sorts doubly linked list of integers
 * in ascending order using Cocktail shaker sort
 * @list: A pointer to a pointer to the head of the list
*/
void cocktail_sort_list(listint_t **list)
{
	listint_t *start = NULL, *end = NULL, *current = NULL;
	int swapped;

	if (list == NULL || *list == NULL)
		return;

	do {
		swapped = 0;

		for (current = *list; current->next != end; current = current->next)
		{
			if (current->n > current->next->n)
			{
				swap_nodes(list, &current, &(current->next));
				swapped = 1;
			}
		}
		if (!swapped)
			break;

		end = current;

		swapped = 0;

		for (current = current->prev;
				current->prev != start; current = current->prev)
		{
			if (current->n < current->prev->n)
			{
				swap_nodes(list, &(current->prev), &current);
				swapped = 1;
			}
		}

		start = current;

	} while (swapped);
}

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @list: A pointer to a pointer to the head of the list
 * @node1: A pointer to the first node
 * @node2: A pointer to the second node
*/
void swap_nodes(listint_t **list, listint_t **node1, listint_t **node2)
{
	listint_t *temp1, *temp2;

	temp1 = (*node1)->prev;
	temp2 = (*node2)->next;

	if (temp1 != NULL)
		temp1->next = *node2;
	else
		*list = *node2;

	if (temp2 != NULL)
		temp2->prev = *node1;

	(*node1)->next = temp2;
	(*node1)->prev = *node2;
	(*node2)->next = *node1;
	(*node2)->prev = temp1;

	print_list(*list);
}
