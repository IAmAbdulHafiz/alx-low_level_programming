#include "lists.h"

/**
 * dlistint_len - Counts elements in a linked dlistint_t list.
 * @h: Head of the list.
 * Return: Number of elements in the list.
 */
size_t dlistint_len(const dlistint_t *h)
{
	size_t nodes = 0;

	while (h)
	{
		nodes++;
		h = h->next;
	}
	return (nodes);
}
