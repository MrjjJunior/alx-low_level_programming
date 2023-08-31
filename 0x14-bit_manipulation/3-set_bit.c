#include "main.h"

/**
 * set_bit - Sets the value of a bit to 1 at a given index.
 * @n: A pointer to the number whose bit needs to be set.
 *
 * @index: Th indexe of the bit to be set.
 *
 * Return: 1 if it worked, or -1 if error.
 */

int set_bit(unsigned long int *n, unsigned int index)
{
	if (index >= sizeof(unsigned long int) * 8)
		return (-1);

	*n = *n | (1UL << index);
	return (1);
}
