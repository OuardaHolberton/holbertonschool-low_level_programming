#include <stdlib.h>
#include "dog.h"

/**
 * _strlen - retourne la longueur d une string
 * @s: la string
 *
 * Return: longueur de la string
 */
int _strlen(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

/**
 * _strcpy - copie une string
 * @dest: destination
 * @src: source
 *
 * Return: dest
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

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

	if (name == NULL || owner == NULL)
		return (NULL);
	dog = malloc(sizeof(dog_t));
	if (dog == NULL)
		return (NULL);
	dog->name = malloc(_strlen(name) + 1);
	if (dog->name == NULL)
	{
		free(dog);
		return (NULL);
	}
	_strcpy(dog->name, name);
	dog->owner = malloc(_strlen(owner) + 1);
	if (dog->owner == NULL)
	{
		free(dog->name);
		free(dog);
		return (NULL);
	}
	_strcpy(dog->owner, owner);
	dog->age = age;
	return (dog);
}
