#include <stdlib.h>

#include "binary_trees.h"

/**
 * binary_tree_nodes - function that counts the nodes with at least 1 child in
 *		       a binary tree
 *
 * @tree: pointer to the root node of the tree to count the number of nodes
 *
 * Description: a NULL pointer is not a node
 *
 * Return: return 0 if @tree is NULL
*/

size_t binary_tree_nodes(const binary_tree_t *tree)
{
	int i;

	if (tree == NULL)
		return (0);

	i = 0;

	/* if the current node has at least one child, increment the count */
	if (tree->left != NULL || tree->right != NULL)
		i++;

	i += binary_tree_nodes(tree->left);
	i += binary_tree_nodes(tree->right);

	return (i);
}

