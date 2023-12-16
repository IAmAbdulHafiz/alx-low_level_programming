#include "main.h"

/**
 * _strncpy - Copies 'n' characters from 'src' to 'dest'.
 * @dest: Pointer to the destination string.
 * @src: Pointer to the source string.
 * @n: Number of characters to copy.
 *
 * Return: Pointer to the destination string 'dest'.
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i;

	for (i = 0; src[i] != '\0' && i < n; i++)
	{
		dest[i] = src[i];
	}

	for (; i < n; i++)
	{
		dest[i] = '\0';
	}

	return (dest);
}
