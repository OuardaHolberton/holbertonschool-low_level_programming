#include <stdlib.h>
#include "3-calc.h"

/**
 * main - programme calculatrice
 * @argc: nombre d arguments
 * @argv: tableau d arguments
 *
 * Return: 0
 */
int main(int argc, char *argv[])
{
	int a;
	int b;
	char *op;
	int (*func)(int, int);

	if (argc != 4)
	{
		printf("Error\n");
		exit(98);
	}
	a = atoi(argv[1]);
	b = atoi(argv[3]);
	op = argv[2];
	func = get_op_func(op);
	if (func == NULL)
	{
		printf("Error\n");
		exit(99);
	}
	if (b == 0 && (op[0] == '/' || op[0] == '%'))
	{
		printf("Error\n");
		exit(100);
	}
	printf("%d\n", func(a, b));
	return (0);
}
