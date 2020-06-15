#include "sort.h"

/**
 * swap - swap two items
 * @a: Int
 * @b: Int
 */

void swap(int *a, int *b)
{
	int aux;

	aux = *a;
	*a = *b;
	*b = aux;
}

/**
 * selection_sort - Selection sort algorithm
 * @array: array
 * @size: size of array
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int num_index;

	if (size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		num_index = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[num_index] > array[j])
				num_index = j;
		}
		swap(&array[num_index], &array[i]);
		print_array(array, size);
	}
}
