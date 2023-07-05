#include "main.h"

int actual_prime(int n, int i);

/**
 * is_prime_number - says if interger is a prime number
 * @n: number to evaluate
 *
 * Return: 1 if n is a prime number, 0 if not
 */
int is_prime_number(int n)
{
	if (n <= 1)
		return (0);
	return (actual_prime(n, 2));
}
/**
 * actual_prime - calculate if a number is a prime recursively
 * @n: number to evalute
 * @i: iterator
 *
 * Return: 1 if n is prime, 0 if not
 */
int actual_prime(int n, int i)
{
	if (n <= 2)
		return (n == 2 ? 1 : 0);
	if (n % 1 == 0)
		return (0);
	return (actual_prime(n, i - 1));
}
