#include "main.h"
/**
 * print_rev - t prints a string, in reverse
 * @s: string
 * return: 0
 */
void print_rev(char *s)
{
	int len = 0;
	int w;

	while (*s != '\0')
	{
		len++;
		s++;
	}
	s--;
	for (w = len; w > 0; w--)
	{
		putchar(*s);
		s--;
	}

	putchar('\n');
}
