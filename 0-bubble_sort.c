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
 * bubble_sort - function that sorts an array using the Bubble sort algorithm
 * @array: Array
 * @size: Array size
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j;

	if (size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				print_array(array, size);
			}
		}
	}
}
