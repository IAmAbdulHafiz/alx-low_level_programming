#include "main.h"

/**
 * _strncat - Concatenates 'n' characters from 'src' to 'dest'.
 * @dest: Pointer to the destination string.
 * @src: Pointer to the source string to be appended.
 * @n: Number of characters to concatenate.
 *
 * Return: Pointer to the destination string 'dest'.
 */
char *_strncat(char *dest, char *src, int n)
{
	int m, i;

	m = 0;

	for (i = 0; i < 1000; i++)
	{
		if (dest[i] == '\0')
		{
			break;
		}
		m++;
	}

	for (i = 0; src[i] != '\0' && i < n; i++)
	{
		dest[m + i] = src[i];
	}

	dest[m + i] = '\0';
	return (dest);
}
