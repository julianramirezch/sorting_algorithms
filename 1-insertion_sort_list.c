#include "sort.h"
/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @list: Double pointer to double linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *div, *aux, *tmp = *list;

	if (!*list)
		return;

	if (tmp->next)
	{
		div = *list;
		div = div->next;
		while (div)
		{
			aux = div;
			div = div->next;
			while (aux->prev && aux->prev->n > aux->n)
			{
				tmp = aux->prev;
				aux->prev = tmp->prev;
				if (aux->prev)
					aux->prev->next = aux;
				tmp->next = aux->next;
				if (tmp->next)
					tmp->next->prev = tmp;
				tmp->prev = aux;
				aux->next = tmp;
				if (!aux->prev)
					*list = aux;
				print_list(*list);
			}

		}
	}
}
