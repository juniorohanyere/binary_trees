#include <stdlib.h>

#include "binary_trees.h"

/**
 * binary_tree_leaves - a function that counts the leaves in a binary tree
 *
 * @tree: pointer to the root node of the tree to count the number of leaves
 *
 * Description: a NULL pointer is not a leaf
 *
 * Return: return 0 if @tree is NULL
*/

size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t leaves;

	if (tree == NULL)
		return (0);

	leaves = get_leaves(tree);

	return (leaves);
}

/**
 * get_leaves - gets the number of leave nodes in a binary tree
 *
 * @tree: pointer to the root node of the tree to get the number of leaves from
 *
 * Return: return the number of leave nodes found
*/

size_t get_leaves(const binary_tree_t *tree)
{
	size_t left, right;

	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (1); /* leaf node(s) */

	left = get_leaves(tree->left);
	right = get_leaves(tree->right);

	return (left + right);
}
