#include <stdio.h>
#include <stdlib.h>
#include "dog.h"

/**
 * print_dog - print info on a dog
 * @d: struct with dog's info
 */
void print_dog(struct dog *d)
{
	if (d == NULL)
		exit(0);

	if (d->name != NULL)
		printf("Name: %s\n", d->name);
	else
		printf("Name: (nil)\n");

	printf("Age: %f\n", d->age);

	if (d->owner != NULL)
		printf("Owner: %s\n", d->owner);
	else
		printf("Owner: (nil)\n");
}
