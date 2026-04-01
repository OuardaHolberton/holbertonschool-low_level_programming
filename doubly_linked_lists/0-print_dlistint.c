#include "lists.h"

/**
 * print_dlistint - prints all elements of a dlistint_t list
 * @h: pointer to the head of the list
 *
 * Return: number of nodes
 */
size_t print_dlistint(const dlistint_t *h)
{
	const dlistint_t *tmp;
	size_t n;

	n = 0;
	tmp = h;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		n++;
		tmp = tmp->next;
	}
	return (n);
}
