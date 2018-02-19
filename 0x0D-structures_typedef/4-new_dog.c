#include <stdio.h>
#include <stdlib.h>
#include "dog.h"

/**
 * _strlen - find length of a string
 * @str: string to be evaluated
 *
 * Return: length of string
 */
int _strlen(char *str)
{
	int i;

	for (i = 0; *str != '\0'; i++)
		str++;

	return (i);
}

/**
 * new_dog - create a new_dog of type dog_t
 * @name: name of new dog
 * @age: age of new dog
 * @owner: owner of new dog
 *
 * Return: a pointer to the new dog
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *my_dog = NULL;
	int n_len = _strlen(name);
	int o_len = _strlen(owner);
	char *n_ptr;
	char *o_ptr;
	int i;

	my_dog = malloc(sizeof(dog_t));
	if (my_dog == NULL)
		return (NULL);

	my_dog->name = malloc(n_len + 1);
	if (my_dog->name == NULL)
		return (NULL);

	my_dog->owner = malloc(o_len + 1);
	if (my_dog->owner == NULL)
		return (NULL);

	n_ptr = my_dog->name;
	for (i = 0; i < n_len + 1; i++)
	{
		*n_ptr = *name;
		n_ptr++;
		name++;
	}

	my_dog->age = age;

	o_ptr = my_dog->owner;
	for (i = 0; i < o_len + 1; i++)
	{
		*o_ptr = *owner;
		o_ptr++;
		owner++;
	}

	return (my_dog);
}
