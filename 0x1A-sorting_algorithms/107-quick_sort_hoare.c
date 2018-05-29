#include "sort.h"

/**
 * hoare_parition - devides an array in half, then calls itself on each half
 * @piBegin: beginning of array
 * @piEnd: last member of array
 * @array: array to divide
 * @size: size of array
 */
void hoare_parition(int *piBegin, int *piEnd, int *array, size_t size)
{
	int iPivot = *piEnd;
	int iTmp;
	int *piForwardIter = piBegin;
	int *piBackwardIter = piEnd;

	if (piBegin == piEnd)
	{
		return;
	}

	while (TRUE)
	{
		while (*piForwardIter < iPivot)
		{
			piForwardIter++;
		}

		while (*piBackwardIter > iPivot)
		{
			piBackwardIter--;
		}

		if (piForwardIter >= piBackwardIter)
		{
			break;
		}

		if (*piForwardIter != *piBackwardIter)
		{
			iTmp = *piForwardIter;
			*piForwardIter = *piBackwardIter;
			*piBackwardIter = iTmp;
			print_array(array, size);
		}

		piForwardIter++;
		piBackwardIter--;
	}

	hoare_parition(piBegin, piForwardIter - 1, array, size);

	hoare_parition(piForwardIter, piEnd, array, size);
}

/**
 * quick_sort_hoare - recursively sorts array into sub-arrays greater than
 * and less than a pivot
 * @array: array to sort
 * @size: size of array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
	{
		return;
	}

	hoare_parition(array, array + (size - 1), array, size);
}
