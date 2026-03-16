#include "function_pointers.h"
#include <stdlib.h>



/**
 * array_iterator - executes a function on each element of an array
 * @array: the array
 * @size: the size of the array
 * @action: pointer to the function to execute
 *
 * Return: void
 */
void array_iterator(int *array, size_t size, void (*action)(int))
{
	size_t i;

	if (array == NULL || action == NULL)
		return;
	i = 0;
	while (i < size)
	{
		action(array[i]);
		i++;
	}
}

