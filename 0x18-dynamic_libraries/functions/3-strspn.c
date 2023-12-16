#include "main.h"

/**
 * _strspn - Gets the length of a prefix substring.
 * @s: String to search in.
 * @accept: Substring of accepted characters.
 *
 * Return: Length of the occurrence.
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int count = 0;
	char *accept_start = accept;

	while (*s++)
	{
		while (*accept++)
		{
			if (*(s - 1) == *(accept - 1))
			{
				count++;
				break;
			}
		}

		if (!(*--accept))
			break;

		accept = accept_start;
	}

	return (count);
}
