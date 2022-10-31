#include"lists.h"
/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: pointer to the singly linked list
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
 * An empty list is considered a palindrome
 **/
int is_palindrome(listint_t **head)
{
	listint_t *new_head = *head;

	return (check(&new_head, *head));
}
/**
 * check - is a auxiliar function, checking elements with recursion
 * @new_head: pointer to the list
 * @head: pointer to the head of the list
 * Return: 0 if it is false, 1 if it is true
 **/
int check(listint_t **new_head, listint_t *head)
{
	if (!head)
		return (1);
	if (check(new_head, head->next) && (head->n == (*new_head)->n))
		return ((*new_head = (*new_head)->next), 1);
	return (0);
}
