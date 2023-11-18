#include "sort.h"
/**
 * get_max_number - Get the maximum number in an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: The maximum integer in the array.
 */
int get_max_number(int *array, int size)
{
	int max_num, a;

	for (max_num = array[0], a = 1; a < size; a++)
	{
		if (array[a] > max_num)
		{
			max_num = array[a];
		}
	}
	return (max_num);
}

/**
 * counting_sort - Sort an array of integers in ascending order
 *                 using the counting sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 */
void counting_sort(int *array, size_t size)
{
	int *count, *temp, max_num, a;

	if (array == NULL || size < 2)
		return;
	temp = malloc(sizeof(int) * size);
	if (!temp)
		return;
	max_num = get_max_number(array, size);
	count = malloc(sizeof(int) * (max_num + 1));
	if (!count)
	{
		free(temp);
		return;
	}

	for (a = 0; a < (max_num + 1); a++)
		count[a] = 0;
	for (a = 0; a < (int)size; a++)
		count[array[a]] += 1;
	for (a = 0; a < (max_num + 1); a++)
		count[a] += count[a - 1];
	print_array(count, max_num + 1);

	for (a = 0; a < (int)size; a++)
	{
		temp[count[array[a]] - 1] = array[a];
		count[array[a]] -= 1;
	}
	for (a = 0; a < (int)size; a++)
		array[a] = temp[a];

	free(temp);
	free(count);
}
