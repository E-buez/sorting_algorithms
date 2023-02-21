#include "sort.h"

/**
 * swap - swaps two elements in an array
 * @a: first element
 * @b: second element
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * partition - partitions an array around a pivot element
 * @array: array to be partitioned
 * @lo: lower index of the partition
 * @hi: upper index of the partition
 * @size: size of array
 *
 * Return: the index of the pivot element
 */
int partition(int *array, int lo, int hi, size_t size)
{
	int pivot = array[hi];
	int i = lo - 1;
	int j;

	for (j = lo; j <= hi - 1; j++)
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

	if (i + 1 != hi)
	{
		swap(&array[i + 1], &array[hi]);
		print_array(array, size);
	}

	return (i + 1);
}

/**
 * quick_sort_helper - recursive helper function for quick sort
 * @array: array to be sorted
 * @lo: lower index of the partition
 * @hi: upper index of the partition
 * @size: size of array
 */
void quick_sort_helper(int *array, int lo, int hi, size_t size)
{
	if (lo < hi)
	{
		int p = partition(array, lo, hi, size);

		quick_sort_helper(array, lo, p - 1, size);
		quick_sort_helper(array, p + 1, hi, size);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order using quick sort
 * @array: array to be sorted
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_helper(array, 0, size - 1, size);
}
