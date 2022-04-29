#include "lists.h"

/**
  *insert_node - insert a number into a sorted singly linked list
  *@head: pointer to the head
  *@number: number to sort and add
  *return: pointer to new node
 **/
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *node = NULL; 
	listint_t *tmp = NULL;

	if (head == NULL)
		return (NULL);

	node = malloc(sizeof(listint_t));
	if (node == NULL)
		return (NULL);

	node->n = number;
	node->next = NULL;
	if (*head == NULL)
	{
		*head = node;
		return (node);
	}

	tmp = *head;
	if (tmp->n == number)
	{
		*head = node;
		node->next = tmp;
		return (node);
	}

	while (tmp->next != NULL && tmp->next->n <= number)
	{
		tmp = tmp->next;
	}

	node->next = tmp->next;
	tmp->next = node;
	return (node);
}
