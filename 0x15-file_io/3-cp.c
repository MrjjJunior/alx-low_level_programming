#include "main.h"
#include <stdlib.h>
#include <stdio.h>

char *make_buffer(void);
void close_file(int fd);

/**
 * create_buffer - returns a buffer of size 1024 bytes.
 *
 * Return: A pointer to the new allocated buffer.
 */

char *create_buffer(void)
{
	char *buffer = malloc(1024);

	if (buffer == NULL)
	{
		perror("Error: Unable to allocate buffer");
		exit(EXIT_FAILURE);
	}

	return buffer;
}
/**
 * close_file - closes selected file descriptor
 *
 * @fd: the file descriptor to be closed.
 */
lose_file(int fd)
{
	if (close(fd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(EXIT_FAILURE);
	}
}
int main(int argc, char *argv[])
{
	int from_fd, to_fd, r, w;
	char *buffer;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(EXIT_FAILURE);
	}

	buffer = create_buffer(argv[2]);
	from_fd = open(argv[1], O_RDONLY);
	to_fd = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, FILE_PERMS);
	while ((r = read(from_fd, buffer, BUFFER_size)) > 0)
	{
		if (from_fd == -1 || r == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
			free(buffer);
			exit(EXIT_FAILURE);
		}
	}

	free(buffer);
	close_file(from_fd);
	close_file(to_fd);

	return (EXIT_SUCCESS);
}
