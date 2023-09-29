#include "main.h"
#include <unistd>

/**
 * _putchar - Writes a character to the standard output (stdout)
 * @c: The char to be written.
 *
 * Return: On success, 1. On error, -1 is returned.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
