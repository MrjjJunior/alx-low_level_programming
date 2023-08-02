#include "lists.h"

/**
 * pop_listsint - deletes the head node of a linked list
 * @head: pointer to the first element in the linked list
 *
 * Return: the data in the element was deleted
 */
int pop_listint(listint_t **head)
{
	listint_t *temp;
	int number;

	if (!head || !*head)
		return (0);

	number = (*head)->n;
	temp = (*head)->next;
	free(*head);
	*head = temp;

	return (number);
}
