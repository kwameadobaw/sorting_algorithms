#include "sort.h"
/**
 * swap - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second inteegr to swap.
*/
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
* recursive_quick_sort - Recursive function to perform Quick sort
* @array: The array to be sorted
* @low: Starting index of the partition to be sorted
* @high: Ending index of the partition to be sorted
* @size: Number of elements in the array
*/
void recursive_quick_sort(int *array, int low, int high, size_t size)
{
	int partition;

	if (low < high)
	{
		partition = lomuto_partition(array, low, high, size);
		recursive_quick_sort(array, low, partition - 1, size);
		recursive_quick_sort(array, partition + 1, high, size);
	}
}

/**
* lomuto_partition - Lomuto partition scheme for Quick sort
* @array: The array to be partitioned
* @low: Starting index of the partition
* @high: Ending index of the partition
* @size: Number of elements in the array
* Return: Index of the pivot after partitioning
*/
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot, i, j;

	pivot = array[high];
	i = low - 1;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;

			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}

	if (i + 1 != high)
	{
		swap(&array[i + 1], &array[high]);
		print_array(array, size);
	}

	return (i + 1);
}

/**
* quick_sort - Sorts an array of integers in ascending order with
* Quick sort algorithm
* @array: The array to be sorted
* @size: Number of elements in the array
*/
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	recursive_quick_sort(array, 0, size - 1, size);

	print_array(array, size);
}
