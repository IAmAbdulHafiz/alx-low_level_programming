#include "main.h"

/**
 * _strlen - Calculates the length of a string.
 * @s: Pointer to the input string.
 *
 * Return: The length of the string.
 */
int _strlen(char *s)
{
	int length = 0;

	while (*s != '\0')
	{
		s++;
		length++;
	}

	return (length);
}
