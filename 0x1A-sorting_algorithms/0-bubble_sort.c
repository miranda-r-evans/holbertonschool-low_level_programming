#include "sort.h"

/**
 * bubble_sort - iterates from beginning to end of array
 * swapping one element at a time
 * @array: array to be sorted
 * @size: size of array
*/
void bubble_sort(int *array, size_t size)
{
	int *piIter;
	int *piEnd;
	int iTmp;
	int bSwap = TRUE;

	if (size < 2 || array == NULL)
	{
		return;
	}

	piEnd = array + (size - 1);

	while (bSwap == TRUE)
	{
		bSwap = FALSE;
		for (piIter = array; piIter < piEnd; piIter++)
		{
			if (*piIter > *(piIter + 1))
			{
				iTmp = *piIter;
				*piIter = *(piIter + 1);
				*(piIter + 1) = iTmp;
				print_array(array, size);
				bSwap = TRUE;
			}
		}
	}
}
