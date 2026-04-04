#include <stdlib.h>
#include "hash_tables.h"

/**
 * hash_table_delete - deletes a hash table
 * @ht: the hash table to delete
 *
 * Return: void
 */
void hash_table_delete(hash_table_t *ht)
{
	hash_node_t *node;
	hash_node_t *tmp;
	unsigned long int i;

	if (ht == NULL)
		return;
	i = 0;
	while (i < ht->size)
	{
		node = ht->array[i];
		while (node != NULL)
		{
			tmp = node->next;
			free(node->key);
			free(node->value);
			free(node);
			node = tmp;
		}
		i++;
	}
	free(ht->array);
	free(ht);
}
