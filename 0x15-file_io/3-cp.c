#include "main.h"

/**
 * error_file - Handles file opening errors.
 * @file_desc: File descriptor.
 * @file_name: File name.
 */

void error_file(int file_desc, const char *file_name)
{
	dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_name);
	close(file_desc);
	exit(98);
}

/**
 * main - Copies the content of one file to another.
 * @argc: Number of arguments.
 * @argv: Array of arguments.
 * Return: 0 on success, otherwise an error code.
 */
int main(int argc, char *argv[])
{
	int file_from, file_to;
	ssize_t nchars, nwr;
	char buf[1024];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		return (97);
	}

	file_from = open(argv[1], O_RDONLY);
	if (file_from == -1)
	error_file(file_from, argv[1]);

	file_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC | O_APPEND, 0664);
	if (file_to == -1)
		error_file(file_to, argv[2]);

	while ((nchars = read(file_from, buf, sizeof(buf))) > 0)
	{
		nwr = write(file_to, buf, nchars);
		if (nwr == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			close(file_from);
			close(file_to);
			exit(99);
		}
	}

	if (nchars == -1)
		error_file(file_from, argv[1]);

	if (close(file_from) == -1 || close(file_to) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close file descriptor\n");
		exit(100);
	}

	return (0);
}
