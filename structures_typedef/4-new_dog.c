#include <stdlib.h>
#include <string.h>
#include "dog.h"

/**
 * new_dog - cree un nouveau chien
 * @name: le nom du chien
 * @age: l age du chien
 * @owner: le proprietaire du chien
 *
 * Return: pointeur vers le nouveau chien ou NULL si echec
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *dog;

	dog = malloc(sizeof(dog_t));
	if (dog == NULL)
		return (NULL);
	dog->name = malloc(strlen(name) + 1);
	if (dog->name == NULL)
		return (NULL);
	strcpy(dog->name, name);
	dog->owner = malloc(strlen(owner) + 1);
	if (dog->owner == NULL)
		return (NULL);
	strcpy(dog->owner, owner);
	dog->age = age;
	return (dog);
}
