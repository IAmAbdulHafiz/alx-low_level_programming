#include "lists.h"

/**
 * add_dnodeint - Adds a new node with the given integer at the beginning
 * of a doubly linked list.
 * @head: A pointer to the head of the dlistint_t list.
 * @n: The integer value for the new node.
 *
 * Return: If the function fails (due to memory allocation) - NULL.
 * Otherwise - the address of the newly added node.
 */

dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *new;

	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
		return (NULL);

	new->n = n;
	new->prev = NULL;
	new->next = *head;
	if (*head != NULL)
		(*head)->prev = new;
	*head = new;

	return (new);
}
