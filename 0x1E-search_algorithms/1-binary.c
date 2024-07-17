#include "search_algos.h"

/**
 * print_array - prints an array of integers
 * @array: pointer to the start of the array
 * @size: size of the array (number of elements)
 *
 * Return: nothing
 */
void print_array(int *array, int size)
{
	int integer;

	if (array == NULL || size == 0)
		return;

	printf("Searching in array: ");

	for (integer = 0; integer < size; integer++)
	{
		if (integer == 0)
			printf("%d", array[integer]);
		else
			printf(", %d", array[integer]);
	}

	printf("\n");
}

/**
 * binary_search - find value in sorted array using binary search method
 * @array: pointer to first element in array
 * @size: size of the array (number of elements)
 * @value: value to be searched for
 *
 * Return: index position of value or -1 if not found or array is null
 */
int binary_search(int *array, size_t size, int value)
{
	int low = 0;
	int high = size - 1;
	int mid;

	if (array == NULL || size == 0 || array[0] > value)
		return (-1);

	while (low <= high)
	{
		mid = (low + high) / 2;

		print_array(&array[low], (high - low) + 1);

		if (array[mid] == value)
			return (mid);

		if (array[mid] > value)
			high = mid - 1;

		else
			low = mid + 1;
	}

	return (-1);
}
