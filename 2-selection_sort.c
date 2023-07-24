#include "sort.h"

/**
 * int_swapping - function used to swap two ints
 * .
 * @a: first integer to be swapped
 * @b: second int to be swapped.
 */

void int_swapping(int *a, int *b)
{
	int hold;

	hold = *a;/*a is given a temporary vilue*/
	*a = *b;
	*b = hold;
}

/**
 * selection_sort - function used to arrange ints in ascending
 * order using selection sort.
 *
 * @array: array of ints
 * @size: size of array.
 */

void selection_sort(int *array, size_t size)
{
	size_t p;
	size_t x;
	int *small;

	if (!array || size < 2)
	{
		return;
	}

	for (p = 0 ; p < size - 1 ; p++)
	{
		small = array + p;
		for (x = p + 1 ; x < size ; x++)
			small = (array[x] < *small) ? (array + x) : small;

		if ((array + p) != small) /*if it isnt the smallest element*/
		{
			int_swapping(array + p, small);
			print_array(array, size);
		}
	}
}
