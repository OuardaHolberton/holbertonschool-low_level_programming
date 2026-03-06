#include "main.h"

/**
 * _atoi - convert a string to an integer
 * @s: string
 *
 * Return: integer value
 */
int _atoi(char *s)
{
	int here;
	int sign;
	unsigned int num;
	int digit;

	here = 0;
	sign = 1;
	num = 0;
	digit = 0;
	while (s[here] != '\0')
	{
		if (digit == 0)
		{
			if (s[here] == '-')
				sign = sign * (-1);
			if (s[here] == '+')
				sign = sign * (1);
		}
		if (s[here] >= '0' && s[here] <= '9')
		{
			digit = 1;
			num = num * 10 + (s[here] - '0');
		}
		else if (digit == 1)
			break;
		here++;
	}
	return (num * sign);
}
