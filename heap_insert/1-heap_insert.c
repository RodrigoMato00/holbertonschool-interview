#include "binary_trees.h"

/**
 * swap_values - Swaps the values between two heap nodes
 * @a: First node
 * @b: Second node
 */
void swap_values(heap_t *a, heap_t *b)
{
	int temp = a->n;

	a->n = b->n;
	b->n = temp;
}

/**
 * bubble_up - Moves the inserted node up to maintain max-heap property
 * @node: Pointer to the newly inserted node
 *
 * Return: The pointer to the node that ends up holding the inserted value
 */
heap_t *bubble_up(heap_t *node)
{
	while (node->parent && node->n > node->parent->n)
	{
		swap_values(node, node->parent);
		node = node->parent;
	}
	return (node);
}

/**
 * get_insert_parent - Finds the parent where the new node should be inserted
 *                     using level-order traversal
 * @root: Pointer to the root of the heap
 *
 * Return: Pointer to the parent node where there's a free spot (left or right)
 */
heap_t *get_insert_parent(heap_t *root)
{
	heap_t *queue[1024];
	int front = 0, rear = 0;

	queue[rear++] = root;
	while (front < rear)
	{
		heap_t *current = queue[front++];

		if (!current->left || !current->right)
			return (current);

		queue[rear++] = current->left;
		queue[rear++] = current->right;
	}
	return (NULL);
}

/**
 * heap_insert - Inserts a value into a Max Binary Heap
 * @root: Double pointer to the root of the Heap
 * @value: Value to insert
 *
 * Return: Pointer to the node that ends up holding the inserted value,
 *         or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node, *parent;

	if (!root)
		return (NULL);

	if (!*root)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}

	parent = get_insert_parent(*root);
	if (!parent)
		return (NULL);

	new_node = binary_tree_node(parent, value);
	if (!new_node)
		return (NULL);

	if (!parent->left)
		parent->left = new_node;
	else
		parent->right = new_node;

	new_node = bubble_up(new_node);

	return (new_node);
}
