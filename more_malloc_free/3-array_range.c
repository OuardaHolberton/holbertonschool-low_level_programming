#include "main.h"
#include <stdlib.h>

/**
 * array_range - creates an array of integers
 * @min: minimum value
 * @max: maximum value
 *
 * Return: pointer to the new array, or NULL on failure
 */

int *array_range(int min, int max)
{
	int *array;
	int i;

	if (min > max)
		return (NULL);
	array = malloc(sizeof(int) * (max - min + 1));
	if (array == NULL)
		return (NULL);
	i = 0;
	while (min <= max)
	{
		array[i] = min;
		i++;
		min++;
	}
	return (array);
}
