#include "sort.h"

/**
 * sort_down - elements high on the heap get replaced with ones lower
 * @piArray: the heap
 * @iSize: size of piArray
 * @iUnSorted: size of unsorted part of array
 * @iIndex: index of element to be sorted down
 */
void sort_down(int *piArray, size_t iSize, size_t iUnSorted, int iIndex)
{
	size_t iBig = (iIndex + 1) * 2;
	size_t iSmall = iBig - 1;
	int iTmp;

	while (iSmall < iUnSorted)
	{
		if (iBig < iUnSorted && piArray[iBig] > piArray[iIndex] &&
		    piArray[iBig] > piArray[iSmall])
		{
			iTmp = piArray[iBig];
			piArray[iBig] = piArray[iIndex];
			piArray[iIndex] = iTmp;
			iIndex = iBig;
			print_array(piArray, iSize);
		}
		else if (piArray[iSmall] > piArray[iIndex])
		{
			iTmp = piArray[iSmall];
			piArray[iSmall] = piArray[iIndex];
			piArray[iIndex] = iTmp;
			iIndex = iSmall;
			print_array(piArray, iSize);
		}
		else
		{
			break;
		}

		iBig = (iIndex + 1) * 2;
		iSmall = iBig - 1;
	}
}

/**
 * max_heap - function to build a max heap
 * @piArray: array to sort
 * @iSize: size of array
 */
void max_heap(int *piArray, size_t iSize)
{
	int iChild = iSize - 1;
	int iParent;

	if ((iChild & 1) == 1)
	{
		iParent = iChild / 2;
		sort_down(piArray, iSize, iSize, iParent);
		iChild--;
	}

	iParent = iChild / 2 - 1;

	while (TRUE)
	{
		sort_down(piArray, iSize, iSize, iParent);
		if (iParent <= 0)
		{
			break;
		}
		iChild -= 2;
		iParent = iChild / 2 - 1;
	}
}
/**
 * heap_sort - sorts elements by moving highest element to the top,
 * then switching with a lower element
 * @array: array to sort
 * @size: size of array
 */
void heap_sort(int *array, size_t size)
{
	int iTmp;
	size_t iUnSorted = size;

	if (array == NULL || size < 2)
	{
		return;
	}

	max_heap(array, size);

	while (iUnSorted > 1)
	{
		iTmp = array[0];
		array[0] = array[iUnSorted - 1];
		array[iUnSorted - 1] = iTmp;
		iUnSorted--;
		print_array(array, size);
		sort_down(array, size, iUnSorted, 0);
	}
}
