#include <stdio.h>
/**
 * main -  program that prints single digit numbers of base ten starting from zero
 * Return: Always 0.
 */

int main(void)
{
	int digit;

	for (digit = 0; digit < 10; digit++)
	{
		putchar('0' + digit);
	}

	putchar('\n');

	return (0);
}
