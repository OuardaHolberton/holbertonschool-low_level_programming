#include <stdlib.h>
#include "dog.h"
/**
 *free_dog - libere les chiens
 *@d: le chien
 * Return: void
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
