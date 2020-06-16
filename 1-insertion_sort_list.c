#include "sort.h"
/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @list: Double pointer to double linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *div1 = NULL, *aux = NULL;

	if (!*list || !list)
		return;

	div1 = *list;
	div1 = div1->next;
	while (div1)
	{
		aux = div1;
		div1 = div1->next;
		while (aux->prev && aux->n < aux->prev->n)
		{
			aux->prev->next = aux->next;
			if (aux->next)
				aux->next->prev = aux->prev;
			aux->next = aux->prev;
			aux->prev = aux->next->prev;
			aux->next->prev = aux;
			if (aux->prev)
				aux->prev->next = aux;
			else
				*list = aux;
			print_list(*list);
		}
	}

}

