#include "lists.h"
#include <string.h>

/**
 * add_node_end - adds node at the end of a linked list
 * @head: head pointer
 * @str: input string
 * Return: address of the new element.
 */

list_t *add_node_end(list_t **head, const char *str)
{
	char *dup;
	int len;
	list_t *n, *last;

	n = malloc(sizeof(list_t));
	if (n == NULL)
	{
		return (NULL);
	}
	dup = strdup(str);
	if (str == NULL)
	{
		free(n);
		return (NULL);
	}
	for (len = 0; str[len];)
	{
		len++;
	}
	n->str = dup;
	n->len = len;
	n->next = NULL;

	if (*head == NULL)
	{
		*head = n;
	}
	else
	{
		last = *head;
		while (last->next != NULL)
		{
			last = last->next;
		}
		last->next = n;
	}

	return (*head);
}
