#include "sort.h"
/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @list: Double pointer to double linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *div1 = NULL, *aux = NULL, *tmp = NULL;

	if (!*list || !list)
		return;

	div1 = *list;
	div1 = div1->next;
	while (div1)
	{
		aux = div1;
		div1 = div1->next;
		while (aux->prev && aux->prev->n > aux->n)
		{
			tmp = aux->prev;
			aux->prev = tmp->prev;
			if (tmp->prev)
				tmp->prev->next = aux;
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
