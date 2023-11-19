#include <stdio.h>
#include "sort.h"

/**
 * swap - Swaps two elements in an array
 * @a: Pointer to the first element
 * @b: Pointer to the second element
*/
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * heapify - Converts an array into a max heap
 * @array: Array to be converted into a heap
 * @size: Size of the array
 * @i: Index of the root of the subtree to be heapified
 * @total_size: Total size of the heap
*/
void heapify(int *array, size_t size, size_t i, size_t total_size)
{
	size_t largest = i;
	size_t left = 2 * i + 1;
	size_t right = 2 * i + 2;

	if (left < size && array[right] > array[largest])
		largest = left;

	if (right < size && array[right] > array[largest])
		largest = right;

	if (largest != i)
	{
		swap(&array[i], &array[largest]);
		print_array(array, total_size);
		heapify(array, size, largest, total_size);
	}
}
/**
 * heap_sort - Sorts an array of integers in ascending order using Heap sort
 * @array: Array to be sorted
 * @size: Size of the array
*/
void heap_sort(int *array, size_t size)
{
	int i;

	if (array == NULL || size < 2)
		return;

	for (i = size / 2 - 1; i >= 0; i--)
		heapify(array, size, i, size);

	for (i = size - 1; i > 0; i--)
	{
		swap(&array[0], &array[i]);
		print_array(array, size);
		heapify(array, i, 0, size);
	}
}
