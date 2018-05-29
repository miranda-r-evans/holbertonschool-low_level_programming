#include "sort.h"

/**
 * bridge - bridges the two nodes on either side of a node
 * @pSBetween: node in between nodes to be bridged
 */
void bridge(listint_t *pSBetween)
{
	if (pSBetween->prev != NULL)
	{
		pSBetween->prev->next = pSBetween->next;
	}
	if (pSBetween->next != NULL)
	{
		pSBetween->next->prev = pSBetween->prev;
	}
}

/**
 * insert - inserts a node in between two nodes
 * @pSPrev: node to sit before new
 * @pSNext: node to sit after new
 * @pSNew: node to be inserted
 */
void insert(listint_t *pSPrev, listint_t *pSNext, listint_t *pSNew)
{
	pSNew->next = pSNext;
	pSNew->prev = pSPrev;

	if (pSPrev != NULL)
	{
		pSPrev->next = pSNew;
	}

	if (pSNext != NULL)
	{
		pSNext->prev = pSNew;
	}
}

/**
 * insertion_sort_list - sorts a list by iterating through list
 * once, placing each new node among the already sorted nodes
 * @list: list to be sorted
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *pSIter;
	listint_t *pSSwap;

	if (list == NULL || *list == NULL)
	{
		return;
	}

	pSIter = *list;
	pSSwap = pSIter->next;

	while (pSSwap != NULL)
	{
		if (pSSwap->n >= pSIter->n)
		{
			pSIter = pSSwap;
			pSSwap = pSSwap->next;
			continue;
		}

		while (pSSwap->n < pSSwap->prev->n)
		{
			bridge(pSSwap);
			insert(pSSwap->prev->prev, pSSwap->prev, pSSwap);
			if (pSSwap->prev == NULL)
			{
				*list = pSSwap;
				print_list(*list);
				break;
			}
			print_list(*list);
		}
		pSSwap = pSIter->next;
	}
}
