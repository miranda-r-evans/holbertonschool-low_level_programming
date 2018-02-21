#include <stdio.h>
#include "3-calc.h"

/**
 * get_op_func - returns a pointer to the function dictated by the operand
 * represented by s
 * @s: points to the character of an operator
 *
 * Return: the function needed for the operation, or NULL if an incorrect char
 * is given
 */
int (*get_op_func(char *s))(int, int)
{
	op_t ops[] = {
		{"+", op_add},
		{"-", op_sub},
		{"*", op_mul},
		{"/", op_div},
		{"%", op_mod},
		{NULL, NULL}
	};
	int i = 0;

	while (i < 5)
	{
		if (*s == *(ops[i].op))
			return (ops[i].f);

		i++;
	}

	return (NULL);
}
