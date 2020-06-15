#include "sort.h"

void insertion_sort_list(listint_t **list)
{
	listint_t *div, *aux, *tmp;

	if (!*list)
		return;

	div = *list;
	div = div->next;
	while(div)
	{
		aux = div;
		div = div->next;
		while(aux->prev && aux->prev->n > aux->n)
		{
			tmp = aux->prev;
			aux->prev = tmp->prev;
			if(aux->prev)
				aux->prev->next = aux;
			tmp->next = aux->next;
			if(tmp->next)
				tmp->next->prev = tmp;
			tmp->prev = aux;
			aux->next = tmp;
			if (!aux->prev)
				*list = aux;
			print_list(*list);
		}

	}
}
