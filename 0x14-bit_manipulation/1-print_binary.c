#include <stdio.h>
#include "main.h"

int _putchar(char c);
/**
 * print_binary - Prints the binary representation of a number
 * @n: number to print in binary
 */
void print_binary(unsigned long int n)
{
	int size, shift, bit;

	size = sizeof(unsigned long int) * 8;

	for (shift = size - 1; shift >= 0; shift--)
	{
		bit = (n >> shift) & 1;
		_putchar(bit + '0');
	}
}
