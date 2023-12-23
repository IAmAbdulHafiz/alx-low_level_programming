#include "hash_tables.h"

/**
 * key_index - Get the index at which a key/value pair should
 *             be stored in the array of a hash table.
 * @key: The key to get the index of.
 * @size: The size of the array of the hash table.
 *
 * Return: The index of the key.
 *
 * Description: Utilizes the djb2 hashing algorithm to determine the index.
 */

{
	return (hash_djb2(key) % size);
}
