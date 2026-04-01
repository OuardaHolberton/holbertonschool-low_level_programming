#include "lists.h"

/**
 * free_dlistint - libère une liste dlistint_t
 * @head: pointeur vers la tête de liste
 */

void free_dlistint(dlistint_t *head)
{
	dlistint_t *tmp;

	while (head != NULL)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}
