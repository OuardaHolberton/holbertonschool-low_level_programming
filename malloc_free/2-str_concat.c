#include "main.h"
#include <stdlib.h>

/**
 * str_concat - concatenates two strings
 * @s1: first string
 * @s2: second string
 *
 * Return: pointer to the new string, or NULL if it fails
 */
char *str_concat(char *s1, char *s2)
{
	char *array;
	unsigned int i;
	unsigned int j;
	unsigned int cp2;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";
	i = 0;
	while (s1[i] != '\0')
		i++;
	j = 0;
	while (s2[j] != '\0')
		j++;
	array = malloc((i + j + 1) * sizeof(char));
	if (array == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		array[i] = s1[i];
		i++;
	}
	cp2 = 0;
	while (s2[cp2] != '\0')
	{
		array[i + cp2] = s2[cp2];
		cp2++;
	}
	array[i + cp2] = '\0';
	return (array);
}
