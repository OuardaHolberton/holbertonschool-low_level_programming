#include "lists.h"

/**
 * insert_dnodeint_at_index - inserts a new node at a given position
 * @h: pointer to the pointer of the head of the list
 * @idx: index where the new node should be added
 * @n: integer to store in the new node
 *
 * Return: address of the new node, or NULL if it failed
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new;
	dlistint_t *tmp;
	unsigned int i;

	i = 0;
	if (idx == 0)
		return (add_dnodeint(h, n));
	tmp = *h;
	while (tmp != NULL)
	{
		if (i == idx)
		{
			new = malloc(sizeof(dlistint_t));
			if (new == NULL)
				return (NULL);
			new->n = n;
			new->next = tmp;
			new->prev = tmp->prev;
			tmp->prev->next = new;
			tmp->prev = new;
			return (new);
		}
		i++;
		tmp = tmp->next;
	}
	if (i == idx)
		return (add_dnodeint_end(h, n));
	return (NULL);
}
