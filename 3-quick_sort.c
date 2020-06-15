#include "sort.h"

/**
 * 
 * 
 * 
 */

int partition(int *array, int low, int high, size_t size)
{ 
	int pivot = array[high];    // pivot 
	int i = (low - 1);  // Index of smaller element 

	for (int j = low; j <= high - 1; j++) 
	{ 
	// If current element is smaller than or 
	// equal to pivot 
		if (array[j] <= pivot) 
		{ 
			i++;    // increment index of smaller element 
			swap(&array[i], &array[j]);
			if (i != j)
				print_array(array, size);
		}
	} 
	swap(&array[i + 1], &array[high]);
	if (i + 1 != high)
		print_array(array, size);
	return (i + 1);
}

/**
 * 
 * 
 * 
 */
void quick_sort2(int *array, int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = partition(array, low, high, size);
		quick_sort2(array, low, pivot - 1, size);
		quick_sort2(array, pivot + 1, high, size);
	}
}
/**
 * 
 * 
 * 
 */

void quick_sort(int *array, size_t size)
{
	int high = size - 1;

	quick_sort2(array, 0, high, size);
}
