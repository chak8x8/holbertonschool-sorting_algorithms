#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in ascending order
 *                  using the Selection sort algorithm.
 * @array: The array to sort.
 * @size: The size of the array.
 */
void selection_sort(int *array, size_t size)
{
	size_t i = 0, j = 0, min_idk;
	int temp = 0;

	if (array == NULL || size < 2)
	{
		return;
	}

	for (i = 0; i < size - 1; i++)
	{
		min_idk = i;

		for (j = i + 1; j < size; j++)
		{
			if (array[min_idk] > array[j])
			{
				min_idk = j;
			}
		}

		temp = array[i];
		array[i] = array[min_idk];
		array[min_idk] = temp;

		print_array(array, size);
	}
}
