#include <stdlib.h>

#include "binary_trees.h"

/**
 * binary_tree_insert_left - function that inserts a node as the left-child of
 *			     another node
 *
 * @parent: the parent node
 * @value: the value to put into the node to be created
 *
 * Return: return a pointer to the newly created node
*/

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *node;

	if (parent == NULL)
		return (NULL);

	node = malloc(sizeof(binary_tree_t));
	if (node == NULL)
		return (NULL);

	node->n = value;
	node->parent = parent;
	node->right = NULL;
	/* check if the parent node already has a left node */
	if (parent->left == NULL)
		node->left = NULL;
	else
	{
		node->left = parent->left;
		node->left->parent = node;
	}

	parent->left = node;

	return (node);
}
