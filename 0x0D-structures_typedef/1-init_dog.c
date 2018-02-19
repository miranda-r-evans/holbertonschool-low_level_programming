#include <stdio.h>
#include <stdlib.h>
#include "dog.h"

/**
 * init_dog - function to initialize a dog struct
 * @d: struct to be initialized
 * @name: name of dog
 * @age: age of dog
 * @owner: dog's owner
 */
void init_dog(struct dog *d, char *name, float age, char *owner)
{
	if (d == NULL)
		exit(0);

	d->name = name;
	d->age = age;
	d->owner = owner;
}
