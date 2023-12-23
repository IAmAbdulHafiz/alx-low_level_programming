#include "hash_tables.h"

shash_table_t *shash_table_create(unsigned long int size);
int shash_table_set(shash_table_t *ht, const char *key, const char *value);
char *shash_table_get(const shash_table_t *ht, const char *key);
void shash_table_print(const shash_table_t *ht);
void shash_table_print_rev(const shash_table_t *ht);
void shash_table_delete(shash_table_t *ht);

/**
 * shash_table_create - Creates a sorted hash table.
 * @size: The size of _new sorted hash table.
 *
 * Return: If an error occurs - NULL.
 *         Otherwise - a pointer to the _new sorted hash table.
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *ht;
	unsigned long int i;

	hash_t = malloc(sizeof(hash_table_t));
	if (hash_t == NULL)
		return (NULL);

	hash_t->size = size;
	hash_t->array = malloc(sizeof(hash_node_t *) * size);
	if (hash_t->array == NULL)
		return (NULL);
	for (i = 0; i < size; i++)
		hash_t->array[i] = NULL;
	ht->shead = NULL;
	ht->stail = NULL;

	return (hash_t);
}

/**
 * shash_table_set - Adds an element to a sorted hash table.
 * @ht: A pointer to the sorted hash table.
 * @key: The key to add - cannot be an empty string.
 * @value: The value associated with key.
 *
 * Return: Upon failure - 0.
 *         Otherwise - 1.
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	shash_node_t *_new, *current;
	char *valueCopy;
	unsigned long int index;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	valueCopy = strdup(value);
	if (valueCopy == NULL)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	current = ht->shead;
	while (current)
	{
		if (strcmp(current->key, key) == 0)
		{
			free(current->value);
			current->value = valueCopy;
			return (1);
		}
		current = current->snext;
	}

	_new = malloc(sizeof(shash_node_t));
	if (_new == NULL)
	{
		free(valueCopy);
		return (0);
	}
	_new->key = strdup(key);
	if (_new->key == NULL)
	{
		free(valueCopy);
		free(_new);
		return (0);
	}
	_new->value = valueCopy;
	_new->next = ht->array[index];
	ht->array[index] = _new;

	if (ht->shead == NULL)
	{
		_new->sprev = NULL;
		_new->snext = NULL;
		ht->shead = _new;
		ht->stail = _new;
	}
	else if (strcmp(ht->shead->key, key) > 0)
	{
		_new->sprev = NULL;
		_new->snext = ht->shead;
		ht->shead->sprev = _new;
		ht->shead = _new;
	}
	else
	{
		current = ht->shead;
		while (current->snext != NULL && strcmp(current->snext->key, key) < 0)
			current = current->snext;
		_new->sprev = current;
		_new->snext = current->snext;
		if (current->snext == NULL)
			ht->stail = _new;
		else
			current->snext->sprev = _new;
		current->snext = _new;
	}

	return (1);
}

/**
 * shash_table_get - Retrieve the value associated with
 *                   a key in a sorted hash table.
 * @ht: A pointer to the sorted hash table.
 * @key: The key to get the value of.
 *
 * Return: If the key cannot be matched - NULL.
 *         Otherwise - the value associated with key in ht.
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	shash_node_t *_node;
	unsigned long int index;

	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);

	index = key_index((const unsigned char *)key, ht->size);
	if (index >= ht->size)
		return (NULL);

	_node = ht->shead;
	while (_node != NULL && strcmp(_node->key, key) != 0)
		_node = _node->snext;

	return ((_node == NULL) ? NULL : _node->value);
}

/**
 * shash_table_print - Prints a sorted hash table in order.
 * @ht: A pointer to the sorted hash table.
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *_node;

	if (ht == NULL)
		return;

	_node = ht->shead;
	printf("{");
	while (_node != NULL)
	{
		printf("'%s': '%s'", _node->key, _node->value);
		_node = _node->snext;
		if (_node != NULL)
			printf(", ");
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - Prints a sorted hash table in reverse order.
 * @ht: A pointer to the sorted hash table to print.
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *_node;

	if (ht == NULL)
		return;

	_node = ht->stail;
	printf("{");
	while (_node != NULL)
	{
		printf("'%s': '%s'", _node->key, _node->value);
		_node = _node->sprev;
		if (_node != NULL)
			printf(", ");
	}
	printf("}\n");
}

/**
 * shash_table_delete - Deletes a sorted hash table.
 * @ht: A pointer to the sorted hash table.
 */
void shash_table_delete(shash_table_t *ht)
{
	shash_table_t *head = ht;
	shash_node_t *_node, *current;

	if (ht == NULL)
		return;

	_node = ht->shead;
	while (_node)
	{
		current = _node->snext;
		free(_node->key);
		free(_node->value);
		free(_node);
		_node = current;
	}

	free(head->array);
	free(head);
}
