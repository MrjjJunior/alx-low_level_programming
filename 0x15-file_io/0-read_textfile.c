#include "main.h"

/**
 * read_textfile - reads a text file and prints a number of letters
 * @filename: The name of the file
 * @letters: The number of letters to print
 *
 * Return: The actual number of letters printed. If it fails, return 0.
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	int file_descriptor;
	ssize_t num_bytes_read, num_bytes_written;
	char *buffer;

	if (filename == NULL)
		return (0);

	file_descriptor = open(filename, O_RDONLY);

	if (file_descriptor == -1)
		return(0);

	buffer = malloc(sizeof(char) * letters);
	if (buffer == NULL)
	{
		close(file_descriptor);
		return (0);
	}

	num_bytes_read = read(file_descriptor, buffer, letters);
	num_bytes_written = write(STDOUT_FILENO, buffer, num_bytes_read);

	close(file_descriptor);
	free(buffer);

	if (num_bytes_read != num_bytes_written)
		return (0);

	return (num_bytes_written);
}
