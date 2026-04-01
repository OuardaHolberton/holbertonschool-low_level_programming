#include "lists.h"

/**
 * dlistint_len - count all elements of the list
 * @h: pointer to the head of the list
 *
 * Return: length
 */
size_t dlistint_len(const dlistint_t *h)
{
	const dlistint_t *tmp;
	size_t n;

	n = 0;
	tmp = h;
	while (tmp != NULL)
	{
		n++;
		tmp = tmp->next;
	}
	return (n);
}
