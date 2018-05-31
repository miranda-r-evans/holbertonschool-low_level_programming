#include "sort.h"

/**
 * pointer_set - sets pointers to NULL
 * @pMyArray: an array of pointers
 */
void pointer_set(listint_b **pMyArray)
{
	int i;

	for (i = 0; i < 10; i++, pMyArray++)
	{
		*pMyArray = NULL;
	}
}

/**
 * add_to_bucket - adds an int (as a node) to a bucket (member of node array)
 * @ppsBucketList: array of linked lists
 * @iMod: current modulo value for determining what bucket to add to
 * @iNodeVal: int value to be added
 */
void add_to_bucket(listint_b **ppsBucketList, int iMod, int iNodeVal)
{
	listint_b *psNewNode = malloc(sizeof(listint_b));
	listint_b *psIter;
	int iDigit;

	if (psNewNode == NULL)
	{
		exit(EXIT_FAILURE);
	}

	iDigit = iNodeVal % iMod / (iMod / 10);
	psIter = ppsBucketList[iDigit];
	psNewNode->n = iNodeVal;
	psNewNode->next = NULL;

	if (psIter == NULL)
	{
		ppsBucketList[iDigit] = psNewNode;
	}
	else
	{
		while (psIter->next != NULL)
		{
			psIter = psIter->next;
		}
		psIter->next = psNewNode;
	}
}

/**
 * buckets_to_array - writes values in buckets to an array
 * @ppsBucketList: array of buckets
 * @piArray: array of ints
 */
void buckets_to_array(listint_b **ppsBucketList, int *piArray)
{
	listint_b **ppsBucketIter = ppsBucketList;
	listint_b *psNodeIter;
	listint_b *psTmp;

	while (ppsBucketIter < ppsBucketList + 10)
	{
		psNodeIter = *ppsBucketIter;
		while (psNodeIter != NULL)
		{
			*piArray = psNodeIter->n;
			piArray++;
			psTmp = psNodeIter;
			psNodeIter = psNodeIter->next;
			free(psTmp);
		}
		ppsBucketIter++;
	}
}

/**
 * radix_sort - sorts an array by sorting the least significant digit onwards
 * @array: array to be sorted
 * @size: size of array
 */
void radix_sort(int *array, size_t size)
{
	listint_b **ppsBucketArray;
	int *iIter;
	int iMod = 10;
	int bIsSorted = FALSE;

	if (array == NULL || size < 2)
	{
		return;
	}

	ppsBucketArray = malloc(sizeof(listint_b *) * 10);
	if (ppsBucketArray == NULL)
	{
		return;
	}

	while (bIsSorted == FALSE)
	{
		bIsSorted = TRUE;
		pointer_set(ppsBucketArray);
		iIter = array;
		while (iIter < array + size)
		{
			if (*iIter >= iMod)
			{
				bIsSorted = FALSE;
			}
			add_to_bucket(ppsBucketArray, iMod, *iIter);
			iIter++;
		}
		buckets_to_array(ppsBucketArray, array);

		print_array(array, size);

		iMod *= 10;
	}
	free(ppsBucketArray);
}
