#include "sort.h"

void int_swapping(int *a, int *b);
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

/**
 * int_swapping - function used to swap two ints
 * in an array
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
 * lomuto_scheme - partioning algorithm that arranges the elements
 * in an array around a particular chosen pivot element
 *            .
 * @size: size of the array.
 * @array: array with ints
 * @left: the starting subset to order.
 * @right: the ending subset to order
 *
 * Return: index of pivot element after partitioning
 */

int lomuto_scheme(int *array, size_t size, int left, int right)
{
	int *pivot;
	int up;
	int down;

	pivot = array + right;

	for (up = down = left ; down < right ; down++)
	{
		if (array[down] < *pivot)
		{
			if (up < down)
			{
				int_swapping(array + down, array + up);
				print_array(array, size);
			}
			up++;
		}
	}

	if (array[up] > *pivot)
	{
		int_swapping(array + up, pivot);
		print_array(array, size);
	}

	return (up);
}

/**
 * sorting_lomuto - function used when implementing the
 * quicksort algorithm
 *
 * @size: size of the array.
 * @array: an array with ints to sort
 * @left: starting subset to order
 * @right: ending subset to order
 */

void sorting_lomuto(int *array, size_t size, int left, int right)
{
	int set;

	if (right - left > 0)
	{
		set = lomuto_scheme(array, size, left, right);
		sorting_lomuto(array, size, left, set - 1);
	sorting_lomuto(array, size, set + 1, right);
	}
}

/**
 * quick_sort - function that used the quick algorithm to
 * sort ints in ascending order
 *
 * @array: array of integers.
 * @size:  size of the array.
 */

void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
	{
		return;
	}

	sorting_lomuto(array, size, 0, size - 1);
}
