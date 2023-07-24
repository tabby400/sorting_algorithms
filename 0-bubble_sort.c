#include "sort.h"

/**
 * int_swapping - function used in the swapping of ints
 * in an array.
 *
 * @a: 1st int to be swapped.
 * @b: 2nd int to  be swapped.
 */

void int_swapping(int *a, int *b)
{
	int hold;

	hold = *a; /*to not loose a value*/
	*a = *b;
	*b = hold; /*takes a value*/
}


/**
 * bubble_sort - function that is used to sort an array og ints
 * in ascending order
 *
 * @array: this is an array containing the ints to be
 * sorted
 * @size: this is size of array and is to be printed after each
 * size is made
 */

void bubble_sort(int *array, size_t size)
{
	size_t p;
	size_t curr_size = size;
	bool sorted = false;

	if (!array || size < 2)
	{
		return;
	}

	while (sorted == false)/*ascendin order not gotten*/
	{
		sorted = true;
		for (p = 0 ; p < curr_size - 1 ; p++)
		{
			if (array[p] > array[p + 1])
			{
				int_swapping(array + p, array + p + 1);
				print_array(array, size);
				sorted = false;
			}
		}
		curr_size--;
	}
}
