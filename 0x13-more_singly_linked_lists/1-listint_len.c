#include "lists.h"
#include <stddef.h>

/**
 * listint_len - returns the number of elements in a linked
 * @h: linked list
 * @next: points to the next node
 *
 * Return: number of nodes
 *
 */

size_t listint_len(const listint_t *h)
{
	size_t count = 0;

	while (h)
	{
		count++;

		h = h->next;
	}

	return (count);
}
