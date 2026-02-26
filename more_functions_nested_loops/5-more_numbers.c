#include "main.h"

/**
 * more_numbers - imprime 10 fois les nombres de 0 à 14.
 *
 * Return: void
 */
void more_numbers(void)
{
	int i, j;

	for (i = 0; i < 10; i++)
	{
	for (j = 0; j <= 14; j++)
		{
	if (j > 9)
			{
	_putchar((j / 10) + '0'); /* Premier _putchar : pour la dizaine */
			}
	_putchar((j % 10) + '0'); /* Deuxième _putchar : pour l'unité */
		}
	_putchar('\n'); /* Troisième _putchar : pour la nouvelle ligne */
	}
}

