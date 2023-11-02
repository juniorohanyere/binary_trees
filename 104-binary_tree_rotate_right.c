#include <stdlib.h>

#include "binary_trees.h"

/**
 * binary_tree_rotate_right - function that performs a right-rotation on a
 *			      binary tree
 *
 * @tree: pointer to the root node of the tree to rotate
 *
 * Return: return a pointer to the new root node of the tree once rotated
*/

binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *node, *tmp = NULL;

	if (tree == NULL || tree->left == NULL)
		return (NULL);

	if (tree->left->right != NULL)
		tmp = tree->left->right;

	node = tree->left;
	tree->left->right = tree;
	tree->parent = tree->left;
	tree->left->parent = NULL;
	tree->left = tmp;

	if (tmp != NULL)
		tmp->parent = tree;

	return (node);
}
