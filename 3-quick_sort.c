#iniclude "sort.h"

/**
 * partition - Partitions the array using the Lomuto partition scheme.
 * @array: The array to sort.
 * @low: The starting index of the partition.
 * @high: The ending index of the partition (pivot).
 * @size: The total size of the array.
 *
 * Return: The final index of the pivot.
 */
int partition(int *array, size_t low, size_t high, size_t size)
{
	int pivot = array[high];
	size_t i = low - 1;

	for (size_t j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				int temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
		}
	}
	if (i + 1 != high)
	{
		int temp = array[i + 1];
		array[i + 1] = array[high];
		array[high] = temp;
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
	if (low < high)
	{
		int pivot_index = partition(array, low, high, size);
		
		if (pivot_index > 0) /* Prevent underflow for size_t */
		{
			quick_sort_recursive(array, low, pivot_index - 1, size);
		}
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
	{
		return;
	}
	quick_sort_recursive(array, 0, size - 1, size);
}
