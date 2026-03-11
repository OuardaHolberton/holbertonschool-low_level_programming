#include <stdlib.h>
#include "main.h"

/**
 * malloc_checked - alloue de la mémoire avec malloc
 * @b: nombre d'octets à allouer
 *
 * Return: pointeur vers la mémoire allouée
 */

void *malloc_checked(unsigned int b)
{
	void *ptr;

	ptr = malloc(b);
	if (ptr == NULL)
	exit(98);
	return (ptr);


}
