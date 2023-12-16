#include "main.h"
#include <stddef.h>

/**
 * _strstr - Locates the first occurrence of a substring in a string.
 * @haystack: Pointer to the string to search.
 * @needle: Pointer to the substring to find.
 *
 * Return: Pointer to the first occurrence of the 'needle' in 'haystack',
 * or NULL if no match is found.
 */
char *_strstr(char *haystack, char *needle)
{
	char *result = haystack, *fneedle = needle;

	while (*haystack)
	{
		while (*needle)
		{
			if (*haystack++ != *needle++)
			{
				break;
			}
		}

		if (!*needle)
		{
			return (result);
		}

		needle = fneedle;
		result++;
		haystack = result;
	}

	return (NULL);
}

