#include "hash_tables.h"

/**
 * hash_table_delete - Deletes a hash table.
 * @ht: A pointer to a hash table.
 */
void hash_table_delete(hash_table_t *ht)
{
	hash_table_t *_head = ht;
	hash_node_t *_node, *current;
	unsigned long int i;

	for (i = 0; i < ht->size; i++)
	{
		if (ht->array[i] != NULL)
		{
			_node = ht->array[i];
			while (_node != NULL)
			{
				current = _node->next;
				free(_node->key);
				free(_node->value);
				free(_node);
				_node = current;
			}
		}
	}
	free(_head->array);
	free(_head);
}
