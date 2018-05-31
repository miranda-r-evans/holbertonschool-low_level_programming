#include "sort.h"

/**
 * _memset - sets memory of an array
 * @piArray: array to be changed
 * @iSize: size of array
 * @iNum: number array is set to
 */
void _memset(int *piArray, int iSize, int iNum)
{
	int i;

	for (i = 0; i < iSize; i++)
	{
		*piArray = iNum;
		piArray++;
	}
}

/**
 * find_biggest - finds biggest number in array
 * @piArray: array to be evaluated
 * @iSize: size of array
 *
 * Return: biggest int
 */
int find_biggest(int *piArray, size_t iSize)
{
	int *piIter = piArray;
	int iBig = *piIter;

	while (piIter < piArray + iSize)
	{

		if (*piIter < 0)
		{
			exit(EXIT_FAILURE);
		}
		if (*piIter > iBig)
		{
			iBig = *piIter;
		}
		piIter++;
	}

	return (iBig);
}

/**
 * sort_original - rewrites an array according to the count array
 * @piCount: count array
 * @piOrig: original array to be rewritten
 * @iCountSize: size of count array
 */
void sort_original(int *piCount, int *piOrig, size_t iCountSize)
{
	int *piCountIter = piCount;
	int iHighestVal = 0;
	int i = 0;

	while (piCountIter < piCount + iCountSize)
	{
		if (*piCountIter > i)
		{
			i++;
			*piOrig = iHighestVal;
			piOrig++;
		}
		if (*piCountIter > i)
		{
			continue;
		}

		iHighestVal++;
		piCountIter++;
	}
}

/**
 * fill_out_count_array - increments bytes after each 1 found
 * @piCount: count array
 * @iSize: size of count array
 */
void fill_out_count_array(int *piCount, int iSize)
{
	int *piBackward;
	int *piForward;
	int iHowMany;

	piBackward = piCount + iSize - 1;

	while (piBackward >= piCount)
	{
		if (*piBackward >= 1)
		{
			iHowMany = *piBackward;
			piForward = piBackward + 1;
			while (piForward < piCount + iSize)
			{
				*piForward += iHowMany;
				piForward++;
			}
		}
		piBackward--;
	}
}

/**
 * counting_sort - sorts an array by using array values as
 * indices for another array
 * @array: array to be sorted
 * @size: size of array
 */
void counting_sort(int *array, size_t size)
{
	int *piCount;
	int *piIter;
	int iBig;

	if (array == NULL || size < 2)
	{
		return;
	}

	iBig = find_biggest(array, size);

	piCount = malloc(sizeof(int) * (iBig + 1));
	if (piCount == NULL)
	{
		return;
	}
	_memset(piCount, iBig + 1, 0);

	piIter = array;

	while (piIter < array + size)
	{
		piCount[*piIter] += 1;
		piIter++;
	}

	fill_out_count_array(piCount, iBig + 1);

	print_array(piCount, iBig + 1);

	sort_original(piCount, array, iBig + 1);

	free(piCount);
}
