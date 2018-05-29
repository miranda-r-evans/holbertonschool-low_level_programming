#include "deck.h"

/**
 * _strcmp - compares two strings
 * @s1: first string
 * @s2: second string
 *
 * Return: 0 on success, -1 on failure
 */
int _strcmp(char *s1, char *s2)
{
	if (s1 == NULL || s2 == NULL)
	{
		exit(EXIT_FAILURE);
	}

	while (*s1 == *s2)
	{
		if (*s1 == '\0')
		{
			return (0);
		}
		s1++;
		s2++;
	}

	return (-1);
}

/**
 * compare_cards - compares two deck nodes' cards to see which is greater/equal
 * @psFirstDeckNode: struct indicating a card
 * @psSecondDeckNode: struct indicating a card
 *
 * Return: -1 if first < second, 0 if equal, 1 if first > second
 */
int compare_cards(const void *psFirstDeckNode, const void *psSecondDeckNode)
{
	char ppcCardValues[13][10] = {"Ace", "2", "3", "4", "5", "6", "7", "8",
				      "9", "10", "Jack", "Queen", "King"};
	int i = 0;
	int j = 0;

	deck_node_t *psFirstStruct = *((deck_node_t **)psFirstDeckNode);
	const card_t *psFirstCard = psFirstStruct->card;
	deck_node_t *psSecondStruct = *((deck_node_t **)psSecondDeckNode);
	const card_t *psSecondCard = psSecondStruct->card;

	if (psFirstCard->kind < psSecondCard->kind)
	{
		return (-1);
	}
	if (psFirstCard->kind > psSecondCard->kind)
	{
		return (1);
	}

	while (TRUE)
	{
		if (i == 13)
		{
			exit(EXIT_FAILURE);
		}
		if (_strcmp(ppcCardValues[i], (char *)psFirstCard->value) == 0)
		{
			break;
		}
		i++;
	}
	while (TRUE)
	{
		if (j == 13)
		{
			exit(EXIT_FAILURE);
		}
		if (_strcmp(ppcCardValues[j], (char *)psSecondCard->value) == 0)
		{
			break;
		}
		j++;
	}

	if (i < j)
	{
		return (-1);
	}

	if (i > j)
	{
		return (1);
	}

	return (0);
}

/**
 * create_array - creates an array of deck nodes
 * @deck: beginning of linked list
 *
 * Return: the array
 */
deck_node_t **create_array(deck_node_t *deck)
{
	deck_node_t **ppsDeckNodeArray = malloc(sizeof(deck_node_t *) * 52);
	deck_node_t **ppsArrayIter = ppsDeckNodeArray;

	if (ppsDeckNodeArray == NULL)
	{
		exit(EXIT_FAILURE);
	}

	while (ppsArrayIter < ppsDeckNodeArray + 52)
	{
		*ppsArrayIter = deck;
		ppsArrayIter++;
		deck = deck->next;
	}

	return (ppsDeckNodeArray);
}

/**
 * link_cards - links the cards of the array into a list
 * @ppsDeckNodeArray: array of nodes
 */
void link_cards(deck_node_t **ppsDeckNodeArray)
{
	deck_node_t **ppsArrayIter = ppsDeckNodeArray;

	(*ppsDeckNodeArray)->prev = NULL;
	(*ppsDeckNodeArray)->next = *(ppsDeckNodeArray + 1);
	ppsArrayIter++;

	while (ppsArrayIter < ppsDeckNodeArray + 52)
	{
		(*ppsArrayIter)->prev = *(ppsArrayIter - 1);
		(*ppsArrayIter)->next = *(ppsArrayIter + 1);
		ppsArrayIter++;
	}

	ppsArrayIter--;
	(*ppsArrayIter)->next = NULL;
}

/**
 * sort_deck - sorts a deck of 52 playing cards
 * @deck: pointer to head of deck list
 */
void sort_deck(deck_node_t **deck)
{
	deck_node_t **ppsDeckArray;

	if (deck == NULL || *deck == NULL)
	{
		return;
	}

	ppsDeckArray = create_array(*deck);
	qsort(ppsDeckArray, 52, sizeof(deck_node_t *), compare_cards);
	link_cards(ppsDeckArray);
	*deck = *ppsDeckArray;
	free(ppsDeckArray);
}
