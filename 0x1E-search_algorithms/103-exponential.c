#include <stdio.h>
#include "search_algos.h"

size_t min(size_t a, size_t b)
{
	return (a <= b ? a : b);
}

/*
 *
 */


/*
 *
 */
int exponential_search(int *array, size_t size, int value)
{
	size_t low, high, bound = 1;

	if (!array || size == 0)
		return -1;

	while (bound < size && array[bound] < value)
	{
		printf("Value checked array[%lu] = [%d]\n", bound, array[bound]);
		bound = bound * 2;
	}

	low = bound / 2;
	high = min(bound, size - 1);
	printf("Value found between indexes [%lu] = [%d]\n", low, high);
	return (binary_search(array, size, value));
}

