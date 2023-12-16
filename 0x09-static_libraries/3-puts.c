#include "main.h"

/**
 * _puts - Prints a string followed by a new line.
 * @str: Input string to print.
 *
 * Return: No return value (void).
 */
void _puts(char *str)
{
	while (*str != '\0')
	{
		_putchar(*str);
		str++;
	}
	_putchar('\n');
}
