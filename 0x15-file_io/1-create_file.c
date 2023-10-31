#include "main.h"

/**
 * create_file - Create a file and write content to it.
 * @filename: The name of the file to be created.
 * @text_content: The content to be written to the file.
 *
 * Return: 1 on success, -1 on failure.
 */
int create_file(const char *filename, char *text_content)
{
	int file_desc, num_written, num_chars;

	if (!filename)
		return (-1);

	file_desc = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
	if (file_desc == -1)
		return (-1);

	if (!text_content)
		text_content = "";

	for (num_chars = 0; text_content[num_chars]; num_chars++)
		;

	num_written = write(file_desc, text_content, num_chars);

	if (num_written == -1)
	{
		close(file_desc);
		return (-1);
	}

	close(file_desc);
	return (1);
}
