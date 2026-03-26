#include "main.h"

int helper(int n, int i);

/**
 * helper - Checks for divisors of a number recursively.
 * @n: The number to check.
 * @i: The current divisor to test.
 *
 * Return: 1 if n is prime, 0 otherwise.
 */
int helper(int n, int i)
{
	if (n <= 1)
		return (0);
	if (i >= n)
		return (1);
	if (n % i == 0)
		return (0);
	return (helper(n, i + 1));
}

/**
 * is_prime_number - States if a number is a prime number.
 * @n: The number to evaluate.
 *
 * Return: 1 if n is a prime number, 0 if not.
 */
int is_prime_number(int n)
{
	return (helper(n, 2));
}
