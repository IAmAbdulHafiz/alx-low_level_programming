#include "main.h"

/**
 * flip_bits - Count bits needed to flip from n to m.
 * @n: The first number.
 * @m: The second number.
 * Return: Count of bits needed to flip.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned int count = 0;
	unsigned long int my_result = n ^ m;

	while (my_result)
	{
		count += my_result & 1;
		my_result >>= 1;
	}

	return (count);
}
