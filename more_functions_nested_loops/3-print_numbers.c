#include "main.h"

/**
 * print_numbers - prints the numbers, from 0 to 9, followed by a new line
 *
 * Return: void
 */
void print_numbers(void)
{
	int i;

	for (i = '0'; i <= '9'; i++)
	{
	_putchar(i); /* Première utilisation de _putchar */
	}
	_putchar('\n'); /* Deuxième utilisation de _putchar */
}

