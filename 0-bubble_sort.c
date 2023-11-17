#include "sort.h"
/**
 * swap - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * bubble_sort - Sort an array of integers in ascending order.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	char isSorted;

	if (array == NULL || size < 2)
		return;
	for (i = 0; i < size; i++)
	{
		isSorted = 1;
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				isSorted = 0;
				print_array(array, size);
			}
		}
		/* if no two elements were swapped by inner loop, then break */
		if (isSorted == 1)
			break;
	}
}
