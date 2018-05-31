#include "sort.h"

/**
 * partition - breaks array down to arrays of greater than and less
 * than last element
 * @piBegin: beginning of array
 * @piEnd: end of array
 * @array: total array
 * @size: size of array
 */
void partition(int *piBegin, int *piEnd, int *array, size_t size)
{
	int *piIter = piBegin;
	int *piInsert = piBegin;
	int iTmp;
	int isHomogenous = TRUE;

	if (piEnd == piBegin)
	{
		return;
	}

	while (piIter < piEnd)
	{
		if (*piIter < *piEnd)
		{
			if (piIter != piInsert)
			{
				iTmp = *piIter;
				*piIter = *piInsert;
				*piInsert = iTmp;
				print_array(array, size);
			}
			piInsert++;
			isHomogenous = FALSE;
		}
		if (*piIter > *piEnd)
		{
			isHomogenous = FALSE;
		}
		piIter++;
	}

	if (isHomogenous == TRUE)
	{
		return;
	}

	if (*piInsert != *piEnd)
	{
		iTmp = *piEnd;
		*piEnd = *piInsert;
		*piInsert = iTmp;
		print_array(array, size);
	}

	partition(piBegin, piInsert - 1, array, size);

	partition(piInsert, piEnd, array, size);
}

/**
 * quick_sort - calls recursive function that splits array into sub-arrays
 * @array: array to be sorted
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
	{
		return;
	}

	partition(array, array + (size - 1), array, size);
}
