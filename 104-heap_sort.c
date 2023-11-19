#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * sift_down - Perform the sift-down operation on the heap
 *
 * @array: Array to be sorted
 * @start: Start index of the heap
 * @end: End index of the heap
 * @size: Size of the array
 */
void sift_down(int *array, size_t start, size_t end, size_t size)
{
	size_t root = start;
	size_t child = root * 2 + 1;
	size_t swap = root;
	int temp;
	
	while (root * 2 + 1 <= end)
	{
		if (array[swap] < array[child])
			swap = child;
		
		if (child + 1 <= end && array[swap] < array[child + 1])
			swap = child + 1;
		
		if (swap != root)
		{
			temp = array[root];
			array[root] = array[swap];
			array[swap] = temp;
			print_array(array, size);
			root = swap;
		}
		else
		{
			break; 
		}
	}
}

/**
 * heapify - Build a heap (rearrange array) from the elements
 *
 * @array: Array to be sorted
 * @size: Size of the array
 */
void heapify(int *array, size_t size)
{
	int start;
	for (start = (size / 2) - 1; start >= 0; start--)
		sift_down(array, start, size - 1, size);
}

/**
 * heap_sort - Sort an array of integers in ascending order using Heap sort
 *
 * @array: Array to be sorted
 * @size: Size of the array
 */
void heap_sort(int *array, size_t size)
{
	size_t end;
	int temp;
	
	if (!array || size < 2)
		return;
	
	heapify(array, size);
	
	for (end = size - 1; end > 0; end--)
	{
		temp = array[end];
		array[end] = array[0];
		array[0] = temp;
		print_array(array, size);
		sift_down(array, 0, end - 1, size);
	}
}
