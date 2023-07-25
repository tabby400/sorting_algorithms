#include "sort.h"

void int_swapping(int *a, int *b);
int hoare_partition(int *array, size_t size, int left, int right);
void hoare_sorting(int *array, size_t size, int left, int right);
void quick_sort_hoare(int *array, size_t size);

/**
 * int_swapping - function used in the swapping of two
 * ints in an array
 *
 * @a: first integer to be swapped.
 * @b: second integer to swappped.
 */

void int_swapping(int *a, int *b)
{
	int hold;

	hold = *a;
	*a = *b;
	*b = hold;
}

/**
 * hoare_partition_quick - function that uses the hoare partition
 * scheme to arrange ints in an array
 *
 * @array: array of integers.
 * @size: size of array.
 * @low: The starting index of the subset to order.
 * @high: The ending index of the subset to order.
 *
 * Return: index partitioned lastly
 */

int hoare_partition_quick(int *array, size_t size, int low, int high)
{
	int pivot;
	int ptr_left;
	int ptr_right;

	pivot = array[high];
	for (ptr_left = low - 1, ptr_right = high + 1; ptr_left < ptr_right;)
	{
		do {
			ptr_left++;
		} while (array[ptr_left] < pivot);
		do {
			ptr_right--;
		} while (array[ptr_right] > pivot);

		if (ptr_left < ptr_right)
		{
			int_swapping(array + ptr_left, array + ptr_right);
			print_array(array, size);
		}
	}

	return (ptr_left);
}

/**
 * hoare_sorting - this function works by implementing recursion
 * using the quick sort algorithm
 *
 * @array: array of ints
 * @size: size of the array.
 * @start: the beginning index of array being ordered
 * @end: the last index of the array being ordered
 */

void hoare_sorting(int *array, size_t size, int start, int end)
{
	int part_ind;

	if (end - start > 0)
	{
		part_ind = hoare_partition_quick(array, size, start, end);
		hoare_sorting(array, size, start, part_ind - 1);
		hoare_sorting(array, size, part_ind, end);
	}
}

/**
 * quick_sort_hoare - Sort an array of integers in ascending
 *                    order using the quicksort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 */

void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
	{
		return;
	}

	hoare_sorting(array, size, 0, size - 1);
}
