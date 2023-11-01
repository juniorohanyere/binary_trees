#include <stdlib.h>

#include "binary_trees.h"

/**
 * binary_tree_is_full - function that checks if a binary tree is full
 *
 * @tree: pointer to the root node of the tree to check
 *
 * Return: return 0 if @tree is NULL
*/

int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (is_full(tree));
}

/**
 * is_full - checks if a given binary tree is full by checking its child nodes
 *
 * @tree: pointer to the root node of the tree to check
 *
 * Return: return 1 if full
 *	   return 0 otherwise
*/

int is_full(const binary_tree_t *tree)
{
	int i = 1;

	if (tree->left == NULL && tree->right != NULL)
		return (0);

	if (tree->left != NULL && tree->right == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (1);

	if (i == 0)
		return (0);

	i = is_full(tree->left);
	i = is_full(tree->right);

	return (i);
}
