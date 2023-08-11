#include "main.h"
#include <stdlib.h>
#include <stdio.h>

char *make_buffer(void);
void close_file(int fd);

/**
 * make_buffer - returns a buffer of size 1024 bytes.
 *
 * Return: A pointer to the new allocated buffer.
 */

char *make_buffer(void)
{
	char *buffer = malloc(1024);

	if (buffer == NULL)
	{
		perror("Error: Unable to allocate buffer");
		exit(EXIT_FAILURE);
	}

	return (buffer);
}
/**
 * close_file - closes selected file descriptor
 *
 * @fd: the file descriptor to be closed.
 */

void close_file(int fd)
{
	if (close(fd) == -1)
	{
		perror("Error: Unable to close file descriptor");
		exit(EXIT_FAILURE);
	}
}

int main(int argc, char *argv[])
{
	int from_fd, to_fd, bytes_read, bytes_written;
	char *buffer;

	if (argc != 3)
	{
		fprintf(stderr, "Usage: %s file_from file_to\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	to_fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (to_fd == -1)
	{
		perror("Error: Unable to creat or open destination file");
		free(buffer);
		close_file(from_fd);
		exit(EXIT_FAILURE);
	}

	while ((bytes_read = read(from_fd, buffer, 1024)) > 0)
	{
		bytes_written = write(to_fd, buffer, bytes_read);
		if (bytes_written == -1)
		{
			perror("Error: Unable to write to destinatiom file");
			free(buffer);
			close_file(from_fd);
			close_file(to_fd);
			exit(EXIT_FAILURE);
		}
	}
	if (bytes_read == -1)
	{
		perror("Error: Unable to read from source file");
		free(buffer);
		close_file(from_fd);
		close_file(to_fd);
		exit(EXIT_FAILURE);
	}
	free(buffer);
	close_file(from_fd);
	close_file(to_fd);

	return (EXIT_SUCCESS);
}
