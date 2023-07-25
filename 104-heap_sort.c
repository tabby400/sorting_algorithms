#include "sort.h"

void int_swapping(int *a, int *b);
void max_heap(int *array, size_t size, size_t start_index, size_t index);
void heap_sort(int *array, size_t size);

/**
 * int_swapping - function that is used in the swapping of
 * integers
 *
 * @a: first integer to be swappped.
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
 * max_heap - function that is used to traverse a binary tree
 * and rearrange elements in a binary heap
 *
 * @array: array of integers in binary tree.
 * @size: size of the tree
 * @start_ind: index of the base of binary tree.
 * @index: root node belonging to binary tree
 */

void max_heap(int *array, size_t size, size_t start_ind, size_t index)
{
	size_t right_child;
	size_t left_child;
	size_t big_child;

	left_child = 2 * index + 1;
	right_child = 2 * index + 2;
	big_child = index;

	if (left_child < start_ind && array[left_child] > array[big_child])
		big_child = left_child;
	if (right_child < start_ind && array[right_child] > array[big_child])
		big_child = right_child;

	if (big_child != index)
	{
		int_swapping(array + index, array + big_child);
		print_array(array, size);
		max_heap(array, size, start_ind, big_child);
	}
}

/**
 * heap_sort - function that uses the heap sort algorithm
 * to arrange ints in ascending order
 *
 * @array: array of ints.
 * @size: size of array.
 */

void heap_sort(int *array, size_t size)
{
	int p;

	if (!array || size < 2)
	{
		return;
	}

	for (p = (size / 2) - 1 ; p >= 0 ; p--)
		max_heap(array, size, size, p);

	for (p = size - 1 ; p > 0 ; p--)
	{
		int_swapping(array, array + p);
		print_array(array, size);
		max_heap(array, size, p, 0);
	}
}
