#include "main.h"
#include <stdlib.h>
#include <stdio.h>
/**
 * _strdup - duplicate to new memory space location
 * @str: charcater
 * Return: 0
 */
char *_strdup(char *str)
{
	char *sto;
	int i, r = 0;

	if (str == NULL)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
		i++;

	sto = malloc(sizeof(char) * (i + 1));

	if (sto == NULL)
		return (NULL);

	for (r = 0; str[r]; r++)
		sto[r] = str[r];

	return (sto);
}
