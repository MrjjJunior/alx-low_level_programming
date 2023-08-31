#include "main.h"

/**
 * clear_bit - sets the value of a bit to 0 
 * @n: A pointer to the number whose bit neeeds to be cleared.
 * @index: The index of the bit to be cleared.
 *
 * Return: 1 if Success, else -1.
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index >= sizeof(unsigned long int) * 8)
		return (-1);

	*n = *n & (~(1UL << index));
	return (1);
}
