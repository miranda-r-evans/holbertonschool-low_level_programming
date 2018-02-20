#include <stdio.h>
#include <stdlib.h>
#include "dog.h"

/**
 * free_dog - free a malloc'd dog struct
 * @d: dog struct to be freed
 */
void free_dog(dog_t *d)
{
	if (d != NULL)
	{
	free(d->name);
	free(d->owner);
	free(d);
	}
}
