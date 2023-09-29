#include "main.h"

/**
 * get_bit - Get value of bit at given index.
 * @n: Number to extract bit from.
 * @index: Index of bit to retrieve.
 *
 * Return: Value of bit at index or -1 on error.
 */

int get_bit(unsigned long int n, unsigned int index)
{
	if (index >= sizeof(n) * 8)
		return (-1);
	return ((n >> index) & 1);
}
