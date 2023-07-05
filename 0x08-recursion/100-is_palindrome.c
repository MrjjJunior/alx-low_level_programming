#include "main.h"
#include <string.h>

/**
 * is_palindrome_helper - check if a string is a palindrome.
 * @start: starts the check
 * @end: ends the check
 * @s: string to reverse
 *
 * Return: 1 if the string is a palindrome, otherwise 0
 */
int is_palindrome_helper(char *s, int start, int end)
{
	if (start >= end)
		return (1);
	if (s[start] != s[end])
		return (0);

	return (is_palindrome_helper(s, start + 1, end - 1));
}

/**
 * is_palindrome - checks if a string is a palindrome.
 * @s: string to calculate the length
 *
 * Return: 1 if the string is a palindrome, otherwise 0.
 */
int is_palindrome(char *s)
{
	int len = strlen(s);

	if (len <= 1)
		return (1);

	return (is_palindrome_helper(s, 0, len - 1));
}
