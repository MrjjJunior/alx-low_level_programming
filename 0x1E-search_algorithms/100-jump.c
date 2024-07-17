#include <math.h>
#include "search_algos.h"

/**
 * jump_search - search a sorted array for a value using jump search method
 * @array: the array to be searched
 * @size: the size of the array (number of elements)
 * @value: the int to be searched for
 *
 * Return: 1st index value is found at or -1 if not present or null array
 */
int jump_search(int *array, size_t size, int value)
{
	int jump_size = sqrt(size);
	int previous_pos = 0;
	int current_pos = 0;

	if (array == NULL || size == 0 || array[previous_pos] > value)
		return (-1);

	while (current_pos < (int)size)
	{
		if (array[current_pos] < value)
		{
			printf("Value checked array[%d] = [%d]\n", current_pos, array[current_pos]);

			previous_pos = current_pos;
			current_pos += jump_size;
		}
		else
		{
			break;
		}
	}

	printf("Value found between indexes [%d] and [%d]\n", previous_pos, current_pos);

	if (current_pos > (int)size - 1)
		current_pos = size - 1;

	while (previous_pos <= current_pos)
	{
		printf("Value checked array[%d] = [%d]\n", previous_pos, array[previous_pos]);
		if (array[previous_pos] == value)
			return (previous_pos);
		previous_pos++;
	}

	return (-1);
}

