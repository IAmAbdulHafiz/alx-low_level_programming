#include "main.h"

/**
 * set_bit - Set bit value at given index to 1.
 * @n: Ptr to number whose bit will be set.
 * @index: Index of the bit to be set.
 * Return: 1 if success, -1 if error.
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	if (index >= sizeof(*n) * 8)
		return (-1);
	*n |= (1 << index);
	return (1);
}
