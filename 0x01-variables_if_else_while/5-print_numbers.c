#include <stdio.h>
/**
 * main - a program that prints all single digit numbers of base ten starting from zero
 * Return: Always 0.
 */

int main(void)
{
	int number;

	for (number = 0; number <= 9; number++)
	{
		putchar(number + '0');
	}

	putchar('\n');

	return (0);
}
