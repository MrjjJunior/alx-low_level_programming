#include <stdio.h>
#include "main.h"

/**
 * binary_to_uint - Converts binary to interger
 * @b: Pointer to a string
 *
 * Return: converted number
 */

unsigned int binary_to_uint(const char *b)
{
	unsigned int number;
	number = 0;

	if (b == NULL)
		return (0);

	while (*b != '\0')
	{
		if (*b != '0' && *b != '1')
			return (0);

		number = number * 2 + (*b - '0');
		b++;
	}
	return (number);
}
