#ifndef VARIADIC_FUNCTIONS_H
#define VARIADIC_FUNCTIONS_H
#include <stdarg.h>
#include <stdio.h>

/**
 * struct printer - Structure pour associer un format a une fonction
 * @symbol: Le format (c, i, f, s)
 * @f: Le pointeur vers la fonction d'affichage
 */

typedef struct printer
{
	char *symbol;
	void (*f)(va_list arg);
} printer_t;


int _putchar(char c);
int sum_them_all(const unsigned int n, ...);
void print_numbers(const char *separator, const unsigned int n, ...);
void print_strings(const char *separator, const unsigned int n, ...);
void print_all(const char * const format, ...);

#endif
