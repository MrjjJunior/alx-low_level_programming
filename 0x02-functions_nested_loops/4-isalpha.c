#include <stdio.h>
/**
 * _isalpha - checks for alphabetic character
 * Return: Always 0.
 * @param c The character to be checked.
 * @return 1 if c is an alphabetic letter, else 0
 */

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
	{

		return (1);
	}

	else
	{
		return (0);
	}
}
