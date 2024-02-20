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
 * sift_down - Repairs the heap whose root element is at index 'start'
 * @array: The array
 * @start: Index to start the sifting
 * @end: Index to end the sifting
 * @size: Number of elements in @array
 */
void sift_down(int *array, size_t start, size_t end, size_t size)
{
	size_t root = start, child;

	while (2 * root + 1 <= end)
	{
		child = 2 * root + 1;
		if (child + 1 <= end && array[child] < array[child + 1])
			child++;
		if (array[root] < array[child])
		{
			swap(array, root, child, size);
			root = child;
		}
		else
			return;
	}
}

/**
 * heapify - Creates a heap from an array
 * @array: The array
 * @size: Number of elements in @array
 */
void heapify(int *array, size_t size)
{
	int start;

	start = (size - 2) / 2;
	while (start >= 0)
	{
		sift_down(array, start, size - 1, size);
		start--;
	}
}

/**
 * heap_sort - Sorts an array of integers in ascending order
 * using the Heap sort algorithm
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void heap_sort(int *array, size_t size)
{
	size_t end;

	if (array == NULL || size < 2)
		return;
	heapify(array, size);
	end = size - 1;
	while (end > 0)
	{
		swap(array, end, 0, size);
		end--;
		sift_down(array, 0, end, size);
	}
}
