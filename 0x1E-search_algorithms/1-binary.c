#include <stdio.h>
#include "search_algos.h"


/*
 * ---Sudo code---
 * function binary_search(A, n, T) is
    L := 0
    R := n − 1
    while L ≤ R do
        m := floor((L + R) / 2)
        if A[m] < T then
            L := m + 1
        else if A[m] > T then
            R := m − 1
        else:
            return m
    return unsuccessful
    */

/*
int binary_search(int *array, size_t size, int value)
{
	left = 0;
	right = size - 1;

	while left <= right do:
	{
		middle = floor((left + right) / 2);
		if *array[middle] < value then:
		{
			left = middle + 1;
		}
		else if *array[middle] > value:
		{
			right = middle - 1;
		}
		else
		{
			return (middle);
		}
	}
	return (-1);
}
*/

/*int binary_search(int *array, size_t size, int value)
{
	size_t left = 0, right = size - 1, middle = 0;

	if (array == NULL)   
		return (-1);

	while (left <= right)
	{
		middle = (left + right) / 2 ;

		printf("Searching in array: ");
		for (left = 0; left < size; left++)
		{
			if (left != size - 1)
				printf("%d, ", array[left]);
			else
				printf("%d\n", array[left]);
		}

		if (array[middle] < value)
			left = middle + 1;
		else if (array[middle] > value)
			right = middle - 1;
		else
			return (middle);
	}

	return (-1);
}				
*/

/**
 * binary_search - searches for a value in an integer array using a binary
 * search algorithm, not guaranteed to return lowest index if `value` appears
 * twice in `array`
 * @array: pointer to first element of array to seach
 * @size: number of elements in array
 * @value: value to search for
 *
 * Return: index containing `value`, or -1 if `value` not found or
 * `array` is NULL
 */

int binary_search(int *array, size_t size, int value)
{
	int left, middle, right;
	int i;

	if (array == NULL)
	{
		return (-1);
	}

	left = 0;
	right = size - 1;

	while (left <= right)
	{
		middle = (left + right) / 2;

		printf("Searching in array: ");
		for (i = left; i <= right; i++)
			printf("%i%s", array[i], i == right ? "\n" : ", ");

		if (array[middle] < value)
			left = middle + 1;
		else if (array[middle] > value)
			right = middle - 1;
		else
			return (middle);
	}

	return (-1);
}
