#include "sort.h"

/**
 * selection_sort - sorts an array
 * @array: array to be sorted
 * @size: size of array
 */
void selection_sort(int *array, size_t size)
{
	int *piToSort;
	int *piSmallest;
	int *piSearcher;
	int iTmp;

	if (array == NULL || size < 2)
	{
		return;
	}

	piToSort = array;

	while (piToSort < array + size)
	{
		piSmallest = array + (size - 1);
		piSearcher = piSmallest;

		while (piSearcher != piToSort)
		{
			if (*piSearcher < *piSmallest)
			{
				piSmallest = piSearcher;
			}

			piSearcher--;
		}

		if (*piSmallest < *piToSort)
		{
			iTmp = *piToSort;
			*piToSort = *piSmallest;
			*piSmallest = iTmp;

			print_array(array, size);
		}

		piToSort++;
	}
}
