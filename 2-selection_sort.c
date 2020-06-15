#include "sort.h"

/**
 * 
 * 
 * 
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int num_index;

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
