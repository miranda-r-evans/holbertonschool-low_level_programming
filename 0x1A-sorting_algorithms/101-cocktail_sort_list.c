#include "sort.h"

/**
 * swap - swaps twp nodes
 * @a: node
 * @b: node
 */
void swap(listint_t *a, listint_t *b)
{
	b->prev = a->prev;
	a->next = b->next;
	a->prev = b;
	b->next = a;

	if (a->next != NULL)
	{
		a->next->prev = a;
	}

	if (b->prev != NULL)
	{
		b->prev->next = b;
	}
}

/**
 * cocktail_sort_list - like bubble sort, but goes both ways
 * @list: linked list to be sorted
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *psIter;
	int bSwap = TRUE;

	if (list == NULL || *list == NULL)
	{
		return;
	}

	psIter = *list;

	while (bSwap == TRUE)
	{
		bSwap = FALSE;

		while (psIter->next != NULL)
		{
			if (psIter->n > psIter->next->n)
			{
				if (psIter == *list)
				{
					*list = psIter->next;
				}
				swap(psIter, psIter->next);
				bSwap = TRUE;
				print_list(*list);
			}
			else
			{
				psIter = psIter->next;
			}
		}

		while (psIter->prev != NULL)
		{
			if (psIter->n < psIter->prev->n)
			{
				if (psIter->prev == *list)
				{
					*list = psIter;
				}
				swap(psIter->prev, psIter);
				bSwap = TRUE;
				print_list(*list);
			}
			else
			{
				psIter = psIter->prev;
			}
		}
	}
}
