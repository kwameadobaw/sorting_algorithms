#include "sort.h"

/**
 * cocktail_sort_list - Sorts doubly linked list of integers
 * in ascending order using Cocktail shaker sort
 * @list: A pointer to a pointer to the head of the list
*/
void cocktail_sort_list(listint_t **list)
{
	int swapped = 1;
	listint_t *current;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	while (swapped)
	{
		swapped = 0;

		/* Traverse from left to right */
		for (current = *list; current->next != NULL; current = current->next)
		{
			if (current->n > current->next->n)
			{
				swap_nodes(list, &current, &(current->next));
				print_list(*list);
				swapped = 1;
			}
		}

		if (!swapped)
			break;

		swapped = 0;

		/* Traverse from right to left */
		for (; current->prev != NULL; current = current->prev)
		{
			if (current->n < current->prev->n)
			{
				swap_nodes(list, &(current->prev), &current);
				print_list(*list);
				swapped = 1;
			}
		}
	}
}
/**
 * swap_nodes - Swaps two nodes in a doubly linked list.
 * @list: A pointer to the head of the doubly linked list.
 * @node1: A pointer to the first node to be swapped.
 * @node2: A pointer to the second node to be swapped.
*/
void swap_nodes(listint_t **list, listint_t **node1, listint_t **node2)
{
	listint_t *temp;

	temp = (*node1)->prev;

	if (temp != NULL)
		temp->next = *node2;

	(*node2)->prev = temp;
	(*node1)->prev = *node2;
	(*node1)->next = (*node2)->next;

	if ((*node2)->next != NULL)
		(*node2)->next->prev = *node1;

	(*node2)->next = *node1;

	if (temp == NULL)
		*list = *node2;
}
