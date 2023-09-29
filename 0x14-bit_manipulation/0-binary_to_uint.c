#include "main.h"

/**
 * binary_to_uint - Convert binary to unsigned int.
 * @b: Ptr to binary string (0/1 chars).
 * Return: Converted number or 0 if invalid chars or NULL.
 */

unsigned int binary_to_uint(const char *b)
{
	unsigned int result = 0;

	if (b == NULL)
		return (0);

	while (*b)
	{
		if (*b != '0' && *b != '1')
			return (0);

		result = (result << 1) + (*b - '0');
		b++;
	}

	return (result);
}
