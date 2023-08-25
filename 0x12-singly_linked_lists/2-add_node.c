#include "lists.h"

/**
 * _strlen - counts the lenght of a string
 * @str: string to be counted
 * Return: len of a string
 */

int _strlen(const char *str)
{
	int g = 0;

	while (str[g] != '\0')
	{
		g++;
	}
	return (g);
}

/**
 * add_node - adds a node at the beginning
 * @head: first parameter
 * @str: second parameter
 * Return: nodes
 */

list_t *add_node(list_t **head, const char *str)
{
	list_t *n;

	n = malloc(sizeof(list_t));

	if (n == NULL)
	{
		return (NULL);
	}
	n->str = strdup(str);
	n->len = _strlen(str);
	n->next = *head;

	*head = n;

	return (n);
}
