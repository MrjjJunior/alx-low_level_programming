#include <stdio.h>
#include "search_algos.h"

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

