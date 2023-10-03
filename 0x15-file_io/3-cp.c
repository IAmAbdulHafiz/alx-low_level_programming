#include "main.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

/**
 * error_handling - Handles errors in file operations.
 * @file_from: Source file descriptor.
 * @file_to: Destination file descriptor.
 * @argv: Arguments vector.
 */

void error_handling(int file_from, int file_to, char *argv[])
{
	if (file_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	if (file_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		exit(99);
	}
}

/**
 * main - Copies content from one file to another.
 * @argc: Number of arguments.
 * @argv: Arguments vector.
 * Return: Always 0.
 */

int main(int argc, char *argv[])
{
	int source_file, dest_file, close_result;
	ssize_t num_chars, num_written;
	char buffer[1024];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	source_file = open(argv[1], O_RDONLY);
	dest_file = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC | O_APPEND, 0664);

	error_handling(source_file, dest_file, argv);

	num_chars = 1024;
	while (num_chars == 1024)
	{
		num_chars = read(source_file, buffer, 1024);
		if (num_chars == -1)
			error_handling(-1, 0, argv);

		num_written = write(dest_file, buffer, num_chars);
		if (num_written == -1)
			error_handling(0, -1, argv);
	}
	close_result = close(source_file);
	if (close_result == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", source_file);
		exit(100);
	}
	close_result = close(dest_file);
	if (close_result == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", dest_file);
		exit(100);
	}
	return (0);
}
