#include "main.h"

/**
 * _puts_recursion - Affiche une chaîne suivie d'une nouvelle ligne.
 * @s: La chaîne à afficher.
 *
 * Return; Always 0.
 */

void _puts_recursion(char *s)
{
	if (*s == '\0')
	{
		_putchar('\n');
		return;
	}

	_putchar(*s);
	_puts_recursion(s + 1);
}
