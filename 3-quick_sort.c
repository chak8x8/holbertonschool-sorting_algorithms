#include "sort.h"

/**
 * partition - Partitions the array using the Lomuto partition scheme.
 * @array: The array to sort.
 * @low: The starting index of the partition.
 * @high: The ending index of the partition (pivot).
 * @size: The total size of the array.
 *
 * Return: The final index of the pivot after partitioning.
 */
int partition(int *array, size_t low, size_t high, size_t size)
{
	int pivot = array[high], temp;
	size_t i = low - 1, j;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				/* Swap array[i] and array[j] */
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;

				/* Print only if something changed */
				print_array(array, size);
			}
		}
	}

	/* Place pivot in its correct position */
	if (i + 1 != high)
	{
		/* Swap array[i + 1] and array[high] (the pivot) */
		temp = array[i + 1];
		array[i + 1] = array[high];
		array[high] = temp;

		/*
		 * Print if and only if the swap changed the array
		 * (i.e., the pivot wasn't already in the correct position
		 * with the same value).
		 */
		if (array[i + 1] != temp)
			print_array(array, size);
	}

	return (i + 1);
}

/**
 * quick_sort_recursive - Recursively sorts the array using Quick sort.
 * @array: The array to sort.
 * @low: The starting index of the partition.
 * @high: The ending index of the partition.
 * @size: The total size of the array.
 */
void quick_sort_recursive(int *array, size_t low, size_t high, size_t size)
{
	int pivot_index;

	if (low < high)
	{
		pivot_index = partition(array, low, high, size);

		/*
		 * For size_t, be sure pivot_index is > 0 before subtracting 1
		 * to avoid underflow.
		 */
		if (pivot_index > 0)
			quick_sort_recursive(array, low, pivot_index - 1, size);

		quick_sort_recursive(array, pivot_index + 1, high, size);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order using Quick sort.
 * @array: The array to sort.
 * @size: The size of the array.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_recursive(array, 0, size - 1, size);
}
