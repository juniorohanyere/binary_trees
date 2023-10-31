#include <stdlib.h>

#include "binary_trees.h"

/**
 * binary_tree_insert_right - function that inserts a node as the right-child
 *			      of another node
 *
 * @parent: pointer to the node to insert the right-child in
 * @value: value to store in the new node
 *
 * Description: if parent already has a right-child, the new node must take its
 *		place, and the old right-child must be set as the right-child
 *		of the new node
 *
 * Return: return a pointer to the created node
 *	   return NULL on failure of if parent is NULL
*/

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *node;

	if (parent == NULL)
		return (NULL);

	node = malloc(sizeof(binary_tree_t));
	if (node == NULL)
		return (NULL);

	node->n = value;
	node->parent = parent;
	node->left = NULL;
	/* check if the parent node already has a right node */
	if (parent->right == NULL)
		node->right = NULL;
	else
	{
		node->right = parent->right;
		node->right->parent = node;
	}

	/* set the right-child of the parent to the new node created */
	parent->right = node;

	return (node);
}
