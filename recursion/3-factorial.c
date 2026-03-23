#include "main.h"

/**
 * factorial - Calcule la factorielle d'un nombre n.
 * @n: Le nombre à calculer.
 *
 * Return: Le résultat (int), ou -1 si n est négatif.
 */
int factorial(int n)
{
	int res;

	if (n < 0)
	{
		return (-1);
	}
	if (n == 0)
	{
		return (1);
	}
	res = n * factorial(n - 1);

	return (res);
}
