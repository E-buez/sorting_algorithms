#include "sort.h"

/**
 * bubble_sort - function to perform 'bubble sort' on an array
 * @array: argument of type 'int *'
 *	array
 * @size: argument of type 'size_t'
 *	size of array
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp;

	if (!(size < 2))
	{
		/* iterate through the list 'size - 1' times */
		for (i = 0; i < (size - 1); i++)
		{
			/* iterate through the unsorted part */
			for (j = 0; j < (size - i - 1); j++)
			{
				if (array[j] > array[j + 1])
				{
					temp = array[j];
					array[j] = array[j + 1];
					array[j + 1] = temp;
					print_array(array, size);
				}
			}
		}
	}
}
