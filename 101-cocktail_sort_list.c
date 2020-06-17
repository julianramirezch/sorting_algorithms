#include "sort.h"

/**
 * cocktail_sort_list - Cocktail sort algorithm
 * @list: Doubly linked list
 */

void cocktail_sort_list(listint_t **list)
{
	listint_t *node = NULL, *first = NULL, *last = NULL;

	if (!list || !*list)
		return;

	first = *list;
	while (first->next != last)
	{
		/*Move pointer from first until last node*/
		node = first;
		while (node->next != last)
		{
			if (node->n > node->next->n)
			{
				if (node == *list)
					*list = first = node->next;
				swap_node(node, node->next);
				print_list(*list);
			}
			else
				node = node->next;
		}
		/*Move pointer from last until first node*/
		last = node;
		node = node->prev;
		while (node != first)
		{
			if (node->prev != NULL && node->n < node->prev->n)
			{
				if (node->prev == *list)
					*list = first = node;
				swap_node(node->prev, node);
				print_list(*list);
			}
			else
				node = node->prev;
		}
		first = node;
	}
}
/**
 * swap_node - Swap two nodes
 * @node_prev: First node
 * @node: Second node
 */

void swap_node(listint_t *node_prev, listint_t *node)
{
	if (node_prev->prev != NULL)
		node_prev->prev->next = node;
	if (node->next != NULL)
		node->next->prev = node_prev;
	node_prev->next = node->next;
	node->prev = node_prev->prev;
	node_prev->prev = node;
	node->next = node_prev;
}
