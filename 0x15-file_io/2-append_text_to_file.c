#include "main.h"

/**
 * append_text_to_file - appends text at the end of a file.
 * @filename: File name.
 * @content: content to add.
 *
 * Return: 1 on success, -1 on failure.
 */

int append_text_to_file(const char *filename, char *content)
{
	int file_descriptor;
	int num_letters;
	int bytes_written;

	if (!filename)
		return (-1);

	file_descriptor = open(filename, O_WRONLY | O_APPEND);

	if (file_descriptor == -1)
		return (-1);

	if (content)
	{
		for (num_letters = 0; content[num_letters]; num_letters++)
			;

		bytes_written = write(file_descriptor, content, num_letters);

		if (bytes_written == -1)
		{
			close(file_descriptor);
			return (-1);
		}
	}
	close(file_descriptor);

	return (1);
}
