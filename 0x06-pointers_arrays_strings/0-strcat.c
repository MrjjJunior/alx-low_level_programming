#include "main.h"
/**
 * _strcat - concatenates two strings
 * @dest: input
 * @src: input
 *
 * Return: void
 */
char *_strcat(char *dest, char *src)
{
	int a;
	int s;

	a = 0;
	while (dest[i] != '\0')
	{
		a++;
	}
	s = 0;
	while (src[s] != '\0')
	{
		dest[a] = src[s];
		a++;
		s++;
	}

	dest[a] = '\0';
	return (dest);
}
