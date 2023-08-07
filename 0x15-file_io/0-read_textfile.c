#include "main.h"
#include <stdlib.h>

/**
 * read_textfile- it reads text file
 * @filename: text file name
 * @letters: number of letters to be read
 * Return: 1 when number of bytes are printed or 0 when NULL
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buf;
	ssize_t w;
	ssize_t t;
	ssize_t fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	buf = malloc(sizeof(char) * letters);
	t = read(fd, buf, letters);
	w = writ(STDOUT_FILENO, buf, t);

	free(buf);
	close(fd);
	return (w);
}