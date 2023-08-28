#include "lists.h"
#include <stdlib.h>

/**
 * free_list - Frees a list_t list.
 * @head: head pointer
 */

void free_list(list_t *head)
{
	list_t *gi;

	while (head)
	{
		gi = head->next;
		free(head->str);
		free(head);
		head = gi;
	}
}