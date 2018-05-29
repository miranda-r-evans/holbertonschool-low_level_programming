#include "sort.h"

/**
 * shell_sort - compares elements relative to a set gap, then decreases gap
 * @array: array to be sorted
 * @size: size of array
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1;
	int iTmp;
	int *piIter;
	int *piDec;

	if (array == NULL || size < 2)
	{
		return;
	}

	while (gap < size)
	{
		gap = gap * 3 + 1;
	}
	gap = (gap - 1) / 3;

	while (gap >= 1)
	{
		piIter = array;
		while (piIter + gap < array + size)
		{
			if (*piIter > *(piIter + gap))
			{
				iTmp = *piIter;
				*piIter = *(piIter + gap);
				*(piIter + gap) = iTmp;

				piDec = piIter - gap;
				while (piDec >= array && *piDec > *(piDec + gap))
				{
					iTmp = *piDec;
					*piDec = *(piDec + gap);
					*(piDec + gap) = iTmp;

					piDec -= gap;
				}
			}
			piIter++;
		}
		print_array(array, size);
		gap = (gap - 1) / 3;
	}
}
