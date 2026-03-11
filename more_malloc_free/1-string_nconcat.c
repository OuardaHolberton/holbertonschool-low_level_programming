#include "main.h"
#include <stdlib.h>

/**
 * string_nconcat - concatenate 2 strings into allocated space
 * s2 goes on until n bytes
 * @s1: string 1
 * @s2: string 2
 * @n: number of bytes of s2 we need to copy
 * Return: NULL if s1 or s2 == 0 or if malloc fails
 *         return copy
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	unsigned int length1;
	unsigned int length2;
	unsigned int i;
	unsigned int j;
	char *copy;

	length1 = 0;
	length2 = 0;
	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";
	while (s1[length1])
		length1++;
	while (s2[length2])
		length2++;
	if (n < length2)
		length2 = n;
	copy = malloc(sizeof(char) * (length1 + length2 + 1));
	if (copy == NULL)
		return (NULL);
	for (i = 0; i < length1; i++)
		copy[i] = s1[i];
	for (j = 0; j < length2; j++)
		copy[i + j] = s2[j];
	copy[i + j] = '\0';
	return (copy);
}


