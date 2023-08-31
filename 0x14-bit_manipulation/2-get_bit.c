#include "main.h"

/**
 * get_bit - Gets the value of a bit at a given index.
 * @n: The number containg the bit.
 * @index: The index of the bit to retrieve.
 *
 * Return: The value of the bit at index, or -1 if error.
 */

int get_bit(unsigned long int n, unsigned int index)
{
	if (index >= sizeof(unsigned long int) * 8)
		return (-1);

	return (int)((n >> index) &  1);
}
