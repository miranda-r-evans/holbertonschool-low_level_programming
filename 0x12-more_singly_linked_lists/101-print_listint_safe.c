#include "lists.h"

size_t print_listint_safe(const listint_t *head)
{
	size_t elmnts = 0;
	const listint_t *s_ptr;
	const listint_t *f_ptr;
	listint_t *brk_pnt;

	if (head != NULL)
		s_ptr = head->next;
	if (s_ptr != NULL)
		f_ptr = s_ptr->next;

	while (f_ptr != NULL && f_ptr->next != NULL)
	{
		if (s_ptr == f_ptr)
			break;
		s_ptr = s_ptr->next;
		f_ptr = f_ptr->next->next;
	}

	if (s_ptr == f_ptr)
	{
		s_ptr = head;
		while (s_ptr->next != f_ptr->next)
		{
			s_ptr = s_ptr->next;
			f_ptr = f_ptr->next;
		}
	}

	brk_pnt = f_ptr->next;
	printf ("breakpoint set\n");
/*	while (head != brk_pnt && head != NULL && head->next != NULL)
	{
		printf("%d\n", head->n);
		head = head->next;
		elmnts++;
	}
*/
	return (elmnts);
}
