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
	tmp = *head;
	if (*head == NULL)
	{
		node->next = NULL;
		*head = node;
	}
	else
	{
		if (number < tmp->n)
		{
			node->next = tmp;
			*head = node;
			return (*head);
		}
		else
		{
			while(tmp->next != NULL)
			{
				if(tmp->n < number && tmp->next->n < number)
				{
					tmp = tmp->next;
				}
				else
				{
					node->next = tmp->next;
					tmp->next = node;
					break;
				}
			}
			if (tmp->next == NULL)
				return (add_nodeint_end(head, number));
		}
	}
	return (node);
}