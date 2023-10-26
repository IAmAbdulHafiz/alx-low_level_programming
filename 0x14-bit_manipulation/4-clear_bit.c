#include "main.h"

/**
 * clear_bit - Clear bit value at given index (set to 0).
 * @n: Ptr to number whose bit will be cleared.
 * @index: Index of the bit to be cleared.
 * Return: 1 if success, -1 if error.
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index >= sizeof(*n) * 8)
		return (-1);
	*n &= ~(1 << index);
	return (1);
}
