#include "lists.h"

/**
 * get_dnodeint_at_index - Retrieves the node at a specified index in a
 * dlistint_t list.
 * @head: The head of the dlistint_t list.
 * @index: The index of the node to retrieve.
 *
 * Return: If the node does not exist at the given index - NULL.
 * Otherwise - the address of the node at the specified index.
 */

dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	for (; index != 0; index--)
	{
		if (head == NULL)
			return (NULL);
		head = head->next;
	}

	return (head);
}
