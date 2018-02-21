#include <stdio.h>
#include <stdlib.h>
#include "3-calc.h"

/**
 * op_add - add two numbers
 * @a: number to be added
 * @b: number to be added
 *
 * Return: sum of a and b
 */
int op_add(int a, int b)
{
	return (a + b);
}

/**
 * op_sub - subtract one number from another
 * @a: number that subtracts b
 * @b: number that is subtracted by a
 *
 * Return: a minus b
 */
int op_sub(int a, int b)
{
	return (a - b);
}

/**
 * op_mul - multiplies two numbers
 * @a: number to be multiplied
 * @b: number to be multiplied
 *
 * Return: sum of a and b
 */
int op_mul(int a, int b)
{
	return (a * b);
}

/**
 * op_div - divides one number by another
 * @a: dividend
 * @b: divisor
 *
 * Return: quotient of a and b
 */
int op_div(int a, int b)
{
	if (b == 0)
	{
		printf("Error\n");
		exit(100);
	}
	return (a / b);
}

/**
 * op_mod - find the remainder of the division of two numbers
 * @a: dividend
 * @b: divisor
 *
 * Return: remainer of a divided by b
 */
int op_mod(int a, int b)
{
	if (b == 0)
	{
		printf("Error\n");
		exit(100);
	}
	return (a % b);
}
