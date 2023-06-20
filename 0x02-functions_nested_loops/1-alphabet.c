#include <stdio.h>
/**
 * print_alphabet - prints alphabets in lowercases
 */
void print_alphabet(void)
{
	char letter = 'a';

	for (; letter <= 'z'; letter++)
	{
		_putchar(letter);
	}

	_putchar('\n');
}
