#include "sort.h"
/**
* getMax - Finds the maximum value in an array
* @array: array to find max value of
* @size: Size of array
* Return: Largest value
*/
int getMax(int *array, size_t size)
{
	int max = array[0];
	size_t i;

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
		max = array[i];
	}
	return (max);
}
/**
 * countingSort - Performs counting sort
 * on an array based on significant places
 * @array: Array to be sorted
 * @size: Size of the array
 * @exp: The current significant place (power of 10)
 */
void countingSort(int *array, size_t size, int exp)
{
	const size_t RADIX = 10;
	int *count, *output;
	size_t i;

	count = malloc(RADIX * sizeof(int));
	if (count == NULL)
	{
		fprintf(stderr, "Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}
	for (i = 0; i < RADIX; i++)
		count[i] = 0;

	for (i = 0; i < size; i++)
		count[(array[i] / exp) % RADIX]++;
	for (i = 1; i < RADIX; i++)
		count[i] += count[i - 1];

	output = malloc(size * sizeof(int));
	if (output == NULL)
	{
		fprintf(stderr, "Memory allocation failed\n");
		free(count);
		exit(EXIT_FAILURE);
	}
	for (i = size - 1; i != SIZE_MAX; i--)
	{
		output[count[(array[i] / exp) % RADIX] - 1] = array[i];
		count[(array[i] / exp) % RADIX]--;
	}
	for (i = 0; i < size; i++)
		array[i] = output[i];

	for (i = 0; i < size; i++)
		printf("%d, ", array[i]);

	printf("\n");
	free(count);
	free(output);
}
/**
* radix_sort - Sorts an array using radix sort algo
* @array: Array to sort
* @size: size of array
*/
void radix_sort(int *array, size_t size)
{
	int max = getMax(array, size);
	int exp;

	for (exp = 1; max / exp > 0; exp *= 10)
		countingSort(array, size, exp);
}
