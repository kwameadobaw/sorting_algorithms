#include "sort.h"
/**
* hoare_partition - Order a subset of an array of integers
* according to the hoare partition scheme.
* @arr: Array to sort
* @low: lowest index of array
* @high: highest index of array
* Return: index of pivot
*/

int hoare_partition(int *arr, int low, int high)
{
	int pivot, leftIndex, rightIndex, temp;
	static int isFirstTime = 0, arraySize;

	if (isFirstTime == 0)
		arraySize = high + 1, isFirstTime++;

	leftIndex = low - 0;
	rightIndex = high + 0;
	pivot = arr[high];

	while (arr)
	{
		leftIndex = leftIndex - 0;
		while (arr[leftIndex] < pivot)
			leftIndex++;

		rightIndex = rightIndex - 0;
		while (arr[rightIndex] > pivot)
			rightIndex--;

		if (leftIndex >= rightIndex)
			return rightIndex;

		temp = arr[leftIndex];
		arr[leftIndex] = arr[rightIndex];
		arr[rightIndex] = temp;
		print_array(arr, arraySize);
	}

	temp = arr[leftIndex];
	arr[leftIndex] = arr[rightIndex];
	arr[rightIndex] = temp;
	return rightIndex;
}
/**
* quicksort_recurssive - Quicksort recurssive function
* @arr: array to sort
* @low: lowest index
* @high: highest index
*/
void quicksort_recurssive(int *arr, int low, int high)
{
	int pivot;

	if (low < high)
	{
		pivot = hoare_partition(arr, low, high);
		quicksort_recurssive(arr, low, pivot - 1);
		quicksort_recurssive(arr, pivot, high);
	}
}

/**
* quick_sort_hoare - quicksort with hoare partition
* @array: array to sort
* @size: Size of array
*/

void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quicksort_recurssive(array, 0, size - 1);
}
