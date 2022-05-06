#include "binary_trees.h"

/**
 *heap_t *heap_insert - inserts a value into a Max Binary Heap
 *@root: pointer to the root of the heap
 *@value: value to be inserted
 *Return: pointer to the new node
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node;
	heap_t *parent;
	heap_t *current;

	new_node = malloc(sizeof(heap_t));
	if (new_node == NULL)

		return (NULL);
	new_node->n = value;
	new_node->parent = NULL;
	new_node->left = NULL;
	new_node->right = NULL;
	if (*root == NULL)
	{
		*root = new_node;
		return (new_node);
	}
	current = *root;
	parent = NULL;
	while (current != NULL)
	{
		parent = current;
		if (value > current->n)

			current = current->right;
		else

			current = current->left;
	}
	if (value > parent->n)
	{
		parent->right = new_node;
		new_node->parent = parent;
	}
	else
	{
		parent->left = new_node;
		new_node->parent = parent;
	}
	return (new_node);
}
