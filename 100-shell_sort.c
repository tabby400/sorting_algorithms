#include "sort.h"

/**
 * int_swapping - function used to swap two integers
 *
 * @a: first integer to be swapped.
 * @b: second integer to be swapped.
 */

void int_swapping(int *a, int *b)
{
	int hold;

	hold = *a;
	*a = *b;
	*b = hold;
}

/**
 * shell_sort - function which uses the shell sort algo
 * to arrange ints in ascending order
 *
 * @array: array of ints
 * @size: size of the array
 */

void shell_sort(int *array, size_t size)
{
	size_t interval;
	size_t p;
	size_t x;

	if (!array || size < 2)
	{
		return;
	}

	for (interval = 1 ; interval < (size / 3);)
		interval = interval * 3 + 1;

	for (; interval >= 1 ; interval /= 3)
	{
		for (p = interval ; p < size ; p++)
		{
			x = p;
			while (x >= interval && array[x - interval] > array[x])
			{
				int_swapping(array + x, array + (x - interval));
				x = x - interval;
			}
		}
		print_array(array, size);
	}
}
