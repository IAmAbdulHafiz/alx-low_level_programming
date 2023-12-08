#include "lists.h"

/**
 * insert_dnodeint_at_index - Inserts a new node with the given integer in a
 * dlistint_t list at a specified position.
 * @h: A pointer to the head of the dlistint_t list.
 * @idx: The position to insert the new node.
 * @n: The integer value for the new node.
 *
 * Return: If the function fails (due to memory allocation or invalid index) -
 * NULL. Otherwise - the address of the newly inserted node.
 */

dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *_tmp = *h, *new;

	if (idx == 0)
		return (add_dnodeint(h, n));

	for (; idx != 1; idx--)
	{
		_tmp = _tmp->next;
		if (_tmp == NULL)
			return (NULL);
	}

	if (_tmp->next == NULL)
		return (add_dnodeint_end(h, n));

	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
		return (NULL);

	new->n = n;
	new->prev = _tmp;
	new->next = _tmp->next;
	_tmp->next->prev = new;
	_tmp->next = new;

	return (new);
}
