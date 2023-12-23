#include "hash_tables.h"

/**
 * hash_table_print - Prints a hash table.
 * @ht: A pointer to the hash table to print.
 *
 * Description: Key/value pairs are printed in the order they appear
 * in the array of the hash table.
 */
void hash_table_print(const hash_table_t *ht)
{
	hash_node_t *_node;
	unsigned long int i;
	unsigned char commaFlag = 0;

	if (ht == NULL)
		return;

	printf("{");
	for (i = 0; i < ht->size; i++)
	{
		if (ht->array[i] != NULL)
		{
			if (commaFlag == 1)
				printf(", ");

			_node = ht->array[i];
			while (_node != NULL)
			{
				printf("'%s': '%s'", _node->key, _node->value);
				_node = _node->next;
				if (_node != NULL)
					printf(", ");
			}
			commaFlag = 1;
		}
	}
	printf("}\n");
}
