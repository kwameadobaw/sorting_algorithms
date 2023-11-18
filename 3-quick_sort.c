#include <stdio.h>
#include "sort.h"
/**
 * quick_sort - Sorts an array of integers in ascending order
 *		using the Quick sort algorithm
 * @array: An array of integers.
 * @size: The size of the array.
*/
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quicksort_recursive(array, 0, size - 1, size);
}
/**
 * quicksort_recursive - Recursive function to perform quicksort.
 * @array: The array to be sorted
 * @low: The low index of the partition.
 * @high: The high index of the partition.
 * @size: The size of the array.
*/
void quicksort_recursive(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pivot_index = lomuto_partition(array, low, high, size);

		quicksort_recursive(array, low, pivot_index - 1, size);
		quicksort_recursive(array, pivot_index + 1, high, size);
	}
}
/**
 * lomuto_partition - Lomuto partition scheme for quicksort
 * @array: The array to be partitioned
 * @low: The low index of the partition.
 * @high: The high index of the partition
 * @size: The size of the array.
 *
 * Return: Index of the pivot after partitioning
*/
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;
	int j;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			swap(&array[i], &array[j]);
			print_array(array, size);
		}
	}
	swap(&array[i + 1], &array[high]);
	print_array(array, size);

	return (i + 1);
}
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
