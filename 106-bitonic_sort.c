#include "sort.h"

/**
 * swap - Swaps two integers in an array
 * @array: The array
 * @i: Index of the first integer
 * @j: Index of the second integer
 * @size: Number of elements in @array
 */
void swap(int *array, size_t i, size_t j, size_t size)
{
	int temp;

	temp = array[i];
	array[i] = array[j];
	array[j] = temp;
	print_array(array, size);
}

/**
 * bitonic_compare - Compares and swaps two elements in a bitonic sequence
 * @array: The array
 * @i: Index of the first element
 * @j: Index of the second element
 * @size: Number of elements in @array
 * @dir: The direction (1 for increasing, 0 for decreasing)
 */
void bitonic_compare(int *array, size_t i, size_t j, size_t size, int dir)
{
	if (dir == (array[i] > array[j]))
		swap(array, i, j, size);
}

/**
 * bitonic_merge - Merges two bitonic sequences
 * @array: The array
 * @low: The starting index of the sequence
 * @cnt: The number of elements in the sequence
 * @size: Number of elements in @array
 * @dir: The direction (1 for increasing, 0 for decreasing)
 */
void bitonic_merge(int *array, size_t low, size_t cnt, size_t size, int dir)
{
	size_t k, i;

	if (cnt > 1)
	{
		k = cnt / 2;
		for (i = low; i < low + k; i++)
		bitonic_compare(array, i, i + k, size, dir);
		bitonic_merge(array, low, k, size, dir);
		bitonic_merge(array, low + k, k, size, dir);
	}
}

/**
 * bitonic_sort_recursive - Recursively sorts a bitonic sequence
 * @array: The array
 * @low: The starting index of the sequence
 * @cnt: The number of elements in the sequence
 * @size: Number of elements in @array
 * @dir: The direction (1 for increasing, 0 for decreasing)
 */
void bitonic_sort_recursive(int *array, size_t low, size_t cnt, size_t size, int dir)
{
	size_t k;

	if (cnt > 1)
	{
		k = cnt / 2;
		bitonic_sort_recursive(array, low, k, size, 1);
		bitonic_sort_recursive(array, low + k, k, size, 0);
		bitonic_merge(array, low, cnt, size, dir);
	}
}

/**
 * bitonic_sort - Sorts an array of integers in ascending order
 * using the Bitonic sort algorithm
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic_sort_recursive(array, 0, size, size, 1);
}
