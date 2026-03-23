#include "main.h"

/**
 * _print_rev_recursion - Affiche une chaîne à l'envers.
 * @s: La chaîne de caractères à afficher.
 *
 * Return: void.
 */
void _print_rev_recursion(char *s)
{
	
	if (*s == '\0')
	{
		return;
	}
	_print_rev_recursion(s + 1);
	_putchar(*s);
}
