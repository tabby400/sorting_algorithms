#include "sort.h"

/**
 * node_swapping - a function that is used to swap two nodes
 * in a doubly linked list
 *
 * @head: A pointer to the head of the doubly-linked list.
 * @n1: points to the first node
 * @n2: points to the second node
 */

void node_swapping(listint_t **head, listint_t **n1, listint_t *n2)
{
	(*n1)->next = n2->next;
	if (n2->next != NULL)
	{
		n2->next->prev = *n1;
	}
	n2->prev = (*n1)->prev;
	n2->next = *n1;
	if ((*n1)->prev != NULL)
	{
		(*n1)->prev->next = n2;
	}
	else
		*head = n2;

	(*n1)->prev = n2;
	*n1 = n2->prev;
}

/**
 * insertion_sort_list -function used in the sorting of ints
 * in a doubly linked list
 *
 * @list:a pointer to the list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *now;
	listint_t *pos;
	listint_t *nxt;

	if (!list || !*list || (*list)->next == NULL)
	{
		return;
	}

	for (now = (*list)->next ; now != NULL ; now = nxt)
	{
		nxt = now->next;
		pos = now->prev;
		while (pos != NULL && now->n < pos->n)
		{
			node_swapping(list, &pos, now);
			print_list((const listint_t *)*list);
		}
	}
}
