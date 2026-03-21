#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * print_char - Affiche un caractere
 * @arg: Liste d'arguments
 */
void print_char(va_list arg)
{
	printf("%c", va_arg(arg, int));
}

/**
 * print_int - Affiche un entier
 * @arg: Liste d'arguments
 */
void print_int(va_list arg)
{
	printf("%d", va_arg(arg, int));
}

/**
 * print_float - Affiche un nombre a virgule
 * @arg: Liste d'arguments
 */
void print_float(va_list arg)
{
	printf("%f", va_arg(arg, double));
}

/**
 * print_string - Affiche une chaine de caracteres
 * @arg: Liste d'arguments
 */
void print_string(va_list arg)
{
	char *str = va_arg(arg, char *);

	if (str == NULL)
	{
		printf("(nil)");
		return;
	}
	printf("%s", str);
}

/**
 * print_all - Fonction principale qui affiche tout
 * @format: Liste des formats (c, i, f, s)
 */
void print_all(const char * const format, ...)
{
	va_list args;
	int i = 0, j = 0;
	char *separateur = "";
	printer_t funcs[] = {
		{"c", print_char},
		{"i", print_int},
		{"f", print_float},
		{"s", print_string},
		{NULL, NULL}
	};

	va_start(args, format);

	while (format && format[i])
	{
		j = 0;
		while (funcs[j].symbol)
		{
			
			if (format[i] == *(funcs[j].symbol))
			{
				printf("%s", separateur);
				funcs[j].f(args);
				separateur = ", ";
			}
			j++;
		}
		i++;
	}

	printf("\n");
	va_end(args);
}
