#include "main.h"
#include <stdlib.h>

/**
 * _strdup - duplicates a string
 * @str: string to duplicate
 *
 * Return: pointer to the new string, or NULL if it fails
 */
char *_strdup(char *str)
{
	char *array;
	unsigned int i;
	unsigned int cp;

	if (str == NULL)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
		i++;
	array = malloc((i + 1) * sizeof(char));
	if (array == NULL)
		return (NULL);
	cp = 0;
	while (str[cp] != '\0')
	{
		array[cp] = str[cp];
		cp++;
	}
	array[cp] = '\0';
	return (array);
}
