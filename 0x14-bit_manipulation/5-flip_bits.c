#include "main.h"

/**
 * flip_bits - Counts the number of bits to change to get from one number to another.
 * @n: First number.
 * @m: Second number.
 *
 * Return: Number of bits to change.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
    int bit_index;
    unsigned long int xor_result = n ^ m;
    unsigned int count_bits = 0;

    for (bit_index = 0; bit_index < 64; bit_index++)
    {
	    if ((xor_result >> bit_index) & 1)
		    count_bits++;
    }

    return count_bits;
}
