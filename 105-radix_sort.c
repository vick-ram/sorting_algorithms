#include "sort.h"

/**
 * get_max - Gets the maximum number in an array
 * @array: The array
 * @size: Number of elements in @array
 *
 * Return: The maximum number in @array
 */
int get_max(int *array, size_t size)
{
	int max = array[0];
	size_t i;

	for (i = 1; i < size; i++)
		if (array[i] > max)
			max = array[i];
	return (max);
}

/**
 * counting_sort_radix - Sorts an array of integers in ascending order
 * using the Counting sort algorithm
 * @array: The array to be sorted
 * @size: Number of elements in @array
 * @exp: Digit to count
 *
 * Return: An array of the counts
 */
int *counting_sort_radix(int *array, size_t size, int exp)
{
	int *output, *count, i, max = 10;
	size_t j;

	count = malloc(sizeof(int) * (max + 1));
	output = malloc(sizeof(int) * size);
	if (count == NULL || output == NULL)
		return (NULL);
	for (i = 0; i <= max; i++)
		count[i] = 0;
	for (j = 0; j < size; j++)
		count[(array[j] / exp) % 10]++;
	for (i = 1; i <= max; i++)
		count[i] += count[i - 1];
	for (j = size - 1; (int)j >= 0; j--)
	{
		output[count[(array[j] / exp) % 10] - 1] = array[j];
		count[(array[j] / exp) % 10]--;
	}
	for (j = 0; j < size; j++)
		array[j] = output[j];
	free(count);
	free(output);
	return (array);
}

/**
 * radix_sort - Sorts an array of integers in ascending order
 * using the Radix sort algorithm
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void radix_sort(int *array, size_t size)
{
	int max, exp;

	if (array == NULL || size < 2)
		return;
	max = get_max(array, size);
	for (exp = 1; max / exp > 0; exp *= 10)
	{
		array = counting_sort_radix(array, size, exp);
		print_array(array, size);
	}
}
