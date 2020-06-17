#include "sort.h"
/**
 * radix_sort - sorts an array of integers in ascending
 * order using the Radix sort algorithm
 * @array: pointer to array for sorting
 * @size: size of array to sort
 */
void radix_sort(int *array, size_t size)
{
	int ten_array[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int *ptr_arr, divisor = 10, max_num = 0, max_div = 10, rem;
	size_t counter = 0;

	if (size == 1 || size == 0)
		return;
/*Malloc for temporal array*/
	ptr_arr = malloc(sizeof(int) * size);
	if (!ptr_arr)
		return;
/*Getting the max number in array and the max divisor possible*/
	for (counter = 0; counter < size; counter++)
		if (array[counter] > max_num)
			max_num = array[counter];
	while ((max_num / max_div) > 0)
		max_div *= 10;
/*Implementing Radix sort*/
	while (divisor <= max_div)
	{
		for (counter = 0; counter < size; counter++)
			rem = (array[counter] % divisor) / (divisor / 10), ten_array[rem] += 1;
		for (counter = 1; counter < 10; counter++)
			ten_array[counter] = ten_array[counter] + ten_array[counter - 1];
		for (counter = 0; counter < size; counter++)
		{
			rem = (array[size - 1 - counter] % divisor) / (divisor / 10);
			ten_array[rem] -= 1;
			ptr_arr[ten_array[rem]] = array[size - 1 - counter];
		}
		for (counter = 0; counter < size; counter++)
			array[counter] = ptr_arr[counter];
/* Setting values of ten_array to 0*/
		for (counter = 0; counter < 10; counter++)
			ten_array[counter] = 0;
		divisor *= 10;
		print_array(array, size);
	}
	free(ptr_arr);
}
