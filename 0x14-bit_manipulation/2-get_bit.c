#include "main.h"

/**
 * get_bit - returns the value
 * @n: number to check bits in.
 * @index: index at which to check bit.
 *
 * Return: Value of the bit.
 */

int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long int mask;

	if (index >= sizeof(unsigned long int) * 8)
	{
		return (-1);
	}

	mask = 1UL << index;
	return (n & mask) ? 1 : 0;
}
