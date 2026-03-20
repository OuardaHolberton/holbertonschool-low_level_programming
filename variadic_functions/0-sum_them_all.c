#include <stdarg.h>
#include "variadic_functions.h"

/**
 * sum_them_all - returns the sum parameters
 * @n: number of parameters
 *
 * Return: sum
 */
int sum_them_all(const unsigned int n, ...)
{
	va_list args;
	int sum;
	unsigned int i;

	if (n == 0)
		return (0);
	va_start(args, n);
	sum = 0;
	i = 0;
	while (i < n)
	{
		sum = sum + va_arg(args, int);
		i++;
	}
	va_end(args);
	return (sum);
}
