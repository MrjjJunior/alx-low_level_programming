#include "main.h"
/**
 * _strncat - concatenate two strings
 * @dest: input
 * @src: input
 * @n: input
 *
 * Return: dest
 */
char *_strncat(char *dest, char *src, int n)
{
	int a;
	int s;

	a = 0;
	while (dest[a] != '\0')
	{
		a++;
	}
	s = 0;
	while (s < n && src[s] != '\0')
	{
		dest[a] = src[s];
		a++;
		s++;
	}
	dest[a] = '\0';
	return (dest);
}
