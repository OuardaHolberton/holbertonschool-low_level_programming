#include "dog.h"
#include <stdio.h>

/**
 * init_dog - initialise les parametres de la structure
 * @d: le chien
 * @name: le nom
 * @age: l age
 * @owner: le proprietaire
 *
 * Return: void
 */

void init_dog(struct dog  *d, char *name, float age, char *owner)
{
    if (d != NULL)
{
    d->name = name;
    d->age = age;
    d->owner = owner;
}

}

