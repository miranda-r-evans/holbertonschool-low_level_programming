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

	my_dog = malloc(n_len + o_len + 2 + sizeof(float));
	if (my_dog == NULL)
		return (NULL);

	my_dog->name = name;
	my_dog->age = age;
	my_dog->owner = owner;

	return (my_dog);
}
