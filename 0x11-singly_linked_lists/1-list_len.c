#include "lists.h"

size_t list_len(const list_t *h)
{
	size_t elmnts = 0;

        const list_t *l_ptr = h;

	while (1)
	{
		if (l_ptr != NULL)
			elmnts++;
		else
			break;

		l_ptr = l_ptr->next;
	}

	return (elmnts);
}
