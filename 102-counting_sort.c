#include "sort.h"

/**
 * findmax_int - function that is used in getting the maximum
 * value in an array full of integers
 *
 * @array: array of integers.
 * @size: size of the array.
 *
 * Return:int with the maximum value
 */

int findmax_int(int *array, int size)
{
	int maximum;
	int p;

	for (maximum = array[0], p = 1 ; p < size ; p++)
	{
		if (array[p] > maximum)
			maximum = array[p];
	}

	return (maximum);
}

/**
 * counting_sort - function that is used to sort ints in
 * the ascending order by using counting sort algo
 *
 * @array: array of ints
 * @size: size of array.
 */

void counting_sort(int *array, size_t size)
{
	int *items_sort;
	int max_value;
	int *count;
	int p;

	if (!array || size < 2)
	{
		return;
	}

	items_sort = malloc(sizeof(int) * size);
	if (!items_sort)
	{
		return;
	}
	max_value = findmax_int(array, size);
	count = malloc(sizeof(int) * (max_value + 1));
	if (!count)
	{
		free(items_sort);
		return;
	}

	for (p = 0 ; p < (max_value + 1) ; p++)
		count[p] = 0;
	for (p = 0 ; p < (int)size ; p++)
		count[array[p]] = count[array[p]] + 1;
	for (p = 0 ; p < (max_value + 1) ; p++)
		count[p] = count[p] + count[p - 1];
	print_array(count, max_value + 1);

	for (p = 0 ; p < (int)size ; p++)
	{
		items_sort[count[array[p]] - 1] = array[p];
		count[array[p]] = count[array[p]] - 1;
	}
	for (p = 0 ; p < (int)size ; p++)
		array[p] = items_sort[p];
	free(items_sort);
	free(count);
}
