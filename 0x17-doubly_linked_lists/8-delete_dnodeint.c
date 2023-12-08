#include "lists.h"

/**
 * delete_dnodeint_at_index - Deletes a node from a dlistint_t list at a
 * specified index.
 * @head: A pointer to the head of the dlistint_t list.
 * @index: The index of the node to delete.
 *
 * Return: Upon success - 1.
 * Otherwise - -1.
 */

int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *_tmp = *head;

	if (*head == NULL)
		return (-1);

	for (; index != 0; index--)
	{
		if (_tmp == NULL)
			return (-1);
		_tmp = _tmp->next;
	}

	if (_tmp == *head)
	{
		*head = _tmp->next;
		if (*head != NULL)
			(*head)->prev = NULL;
	}

	else
	{
		_tmp->prev->next = _tmp->next;
		if (_tmp->next != NULL)
			_tmp->next->prev = _tmp->prev;
	}

	free(_tmp);
	return (1);
}
