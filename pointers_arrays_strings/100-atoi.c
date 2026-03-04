#include "main.h"

/**
 * _atoi - convert a string to an integer
 * @s: string
 *
 * Return: integer value
 */

int _atoi(char *s)
{
        int here = 0; /* where am i in the string*/
        int sign = 1; /* what sign will be the num*/
        unsigned int num = 0; /* final result*/
        int digit = 0; /* detects if we met a digit yet*/

        while (s[here] != '\0') /*loop till \0*/
        {
                if (digit == 0)/*only signs before first digit*/
                {
                        if (s[here] == '-')
                        {
                                sign = sign * (-1); /*change the sign if '-'*/
                        }
                        if (s[here] == '+')
                        {
                                sign = sign * (1); /*doesn't change the sign if '+'*/
                        }
                }

                if (s[here] >= '0' && s[here] <= '9') /*if digit detected*/
                {
                        digit = 1;
                        num = num * 10 + (s[here] - '0'); /*turns a char into int*/
                }
                else if (digit == 1)
                {
                        break; /* stops if digits end*/
                }
                here++;
        }

        return (num * sign); /* change the final sign*/

}
