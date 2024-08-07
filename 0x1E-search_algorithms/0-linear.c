#include "search_algos.h"

/**
 * linear_search - find value in an array using linear search method
 * @array: pointer to first element in array to be searched
 * @size: size of the array (number of elements)
 * @value: value to searched for
 *
 * Return: 1st index where value is located or -1 if not found or array is null
 */
int linear_search(int *array, size_t size, int value)
{
	size_t integer;

	if (array == NULL || size == 0)
		return (-1);

	for (integer = 0; integer < size; integer++)
	{
		printf("Value checked array[%ld] = [%d]\n", integer, array[integer]);
		if (array[integer] == value)
			return (integer);
	}
	return (-1);
}
