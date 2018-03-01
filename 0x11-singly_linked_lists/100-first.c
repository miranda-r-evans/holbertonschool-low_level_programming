#include <stdio.h>

void print_string(void) __attribute__((constructor));

void print_string(void)
{
	printf("You're beat! and yet, you must allow,\nI bore my house upon my back!\n");
}
