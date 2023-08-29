#include "lists.h"

/**
 * delete_nodeint_at_index - deletes a node a certain index in the listint
 *
 * @head: pointer to the first element in the list
 *
 * @index: index of the node to be deleted
 *
 * Return: 1 for Success, or -1 Fail
 */


int delete_nodeint_at_index(listint_t **head, unsigned int index)

{
	unsigned int g;
	listint_t *tmp;
	listint_t *node;


	tmp = *head;

	if (head == NULL || *head == NULL)
		return (-1);

	for (g = 0; g < index - 1 && tmp != NULL && index != 0; g++)

		tmp = tmp->next;

	if (tmp == NULL)
		return (-1);

	if (index == 0)
	{
		node = tmp->next;
		free(tmp);
		*head = node;
	}

	else
	{
		if (tmp->next == NULL)
			node = tmp->next;

		else
			node = tmp->next->next;
		free(tmp->next);
		tmp->next = node;
	}
	return (1);
}
