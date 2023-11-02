#include <stdlib.h>

#include "binary_trees.h"

/**
 * binary_tree_is_complete - function that checks if a binary tree is complete
 *
 * @tree: pointer to the root node of the tree to check
 *
 * Return: return 0 if @tree is NULL
*/

int binary_tree_is_complete(const binary_tree_t *tree)
{
	int size, level;

	if (tree == NULL)
		return (0);

	size = tree_size(tree);
	level = 0;

	return (is_complete(tree, level, size));
}

/**
 * is_complete - checks if a given binary tree is complete
 *
 * @tree: pointer to the root node of the tree to check
 * @level: the level/index of the node
 * @size: the size of the binary tree
 *
 * Return: return 1 if tree is complete
 *	   return 0 otherwise
*/

int is_complete(const binary_tree_t *tree, int level, int size)
{
	int left, right;

	if (tree == NULL)
		return (1);

	if (level >= size)
		return (0);

	left = is_complete(tree->left, 2 * level + 1, size);
	right = is_complete(tree->right, 2 * level + 2, size);

	return (left && right);
}

/**
 * tree_size - function that measures the size of a binary tree
 *
 * @tree: is a pointer to the root node of the tree to measure the size
 *
 * Return: return 0 if @tree is NULL
*/

size_t tree_size(const binary_tree_t *tree)
{
	size_t i;

	if (tree == NULL)
		return (0);

	i = 1 + tree_size(tree->left) + tree_size(tree->right);

	return (i);
}
