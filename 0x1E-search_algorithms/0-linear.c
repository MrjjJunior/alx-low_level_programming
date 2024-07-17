#include "search_algos.h"
/*
 * linear_search - finds given value in linear search method
 * @array: An array of elements
 * @size: Number of elements
 * @value: Value that is being searched for
 *
 * Return: index where value is loacted else -1 .
*/

int linear_search(int *array, size_t size, int value)
{
	for(int integer = 0; integer < size; integer++)
	{
		printf("Value checked array[%d] = [%d]\n", integer, array[integer]);
		if (array[integer] == value)
			return (integer);
	}
	return (-1);
}

