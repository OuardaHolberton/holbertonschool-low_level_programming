#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * main - adds positive numbers
 * @argc: number of arguments
 * @argv: array of the arguments
 *
 * Return: 0 on success, 1 on error
 */
int main(int argc, char *argv[])
{
	int cpt;
	int col;
	int tot;

	tot = 0;
	if (argc == 1)
	{
		printf("0\n");
		return (0);
	}
	cpt = 1;
	while (cpt < argc)
	{
		col = 0;
		while (argv[cpt][col] != '\0')
		{
			if (argv[cpt][col] < '0' || argv[cpt][col] > '9')
			{
				printf("Error\n");
				return (1);
			}
			col++;
		}
		tot += atoi(argv[cpt]);
		cpt++;
	}
	printf("%d\n", tot);
	return (0);
}
