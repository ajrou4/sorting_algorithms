#include "sort.h"

/**
 * partition - partitions the array
 * @array: array to be sorted
 * @low: lowest index of the partition
 * @high: highest index of the partition
 * @size: size of the array
 * Return: index of the pivot
 */

int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = (low - 1);
	int j, tmp;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;
			if (i != j)
				print_array(array, size);
		}
	}
	tmp = array[i + 1];
	array[i + 1] = array[high];
	array[high] = tmp;
	if (i + 1 != j)
		print_array(array, size);
	return (i + 1);
}

/**
 * partition - partitions the array
 * @array: array to be sorted
 * @low: lowest index of the partition
 * @high: highest index of the partition
 * @size: size of the array
 * Return: index of the pivot
 */

void quick_sort_helper(int *array, int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = partition(array, low, high, size);
		quick_sort_helper(array, low, pivot - 1, size);
		quick_sort_helper(array, pivot + 1, high, size);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order
 * using the Quick sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 * Return: void
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_helper(array, 0, size - 1, size);
}
