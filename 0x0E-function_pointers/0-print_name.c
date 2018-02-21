#include "function_pointers.h"

/**
 * print_name - calls a function pointed to by argument to print a name
 * @name: name to be printed
 * @f: function that prints the name
 */
void print_name(char *name, void (*f)(char *))
{
	f(name);
}
