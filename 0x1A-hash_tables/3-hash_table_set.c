#include "hash_tables.h"

/**
 * hash_table_set - Inserts or updates an entry in the hash table.
 * @ht: A pointer to the hash table.
 * @key: The key to insert or update - must not be an empty string.
 * @value: The value associated with the key.
 *
 * Return: 0 upon failure, 1 on success.
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *_new;
	char *valueCopy;
	unsigned long int index, i;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	valueCopy = strdup(value);
	if (valueCopy == NULL)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	for (i = index; ht->array[i]; i++)
	{
		if (strcmp(ht->array[i]->key, key) == 0)
		{
			free(ht->array[i]->value);
			ht->array[i]->value = valueCopy;
			return (1);
		}
	}

	_new = malloc(sizeof(hash_node_t));
	if (_new == NULL)
	{
		free(valueCopy);
		return (0);
	}
	_new->key = strdup(key);
	if (_new->key == NULL)
	{
		free(_new);
		return (0);
	}
	_new->value = valueCopy;
	_new->next = ht->array[index];
	ht->array[index] = _new;

	return (1);
}
