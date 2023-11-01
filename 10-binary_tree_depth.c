#include <stdlib.h>

#include "binary_trees.h"

/**
 * binary_tree_depth - a function that measures the depth of a node in a binary
 *		       tree
 *
 * @tree: is a pointer to the node to measure the depth
 *
 * Return: return 0 if tree is NULL
*/

size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth;

	if (tree == NULL)
		return (0);

	depth = get_depth(tree) - 1;

	return (depth);
}

/**
 * get_depth - gets the depth of a give binary tree
 *
 * @tree: pointer to the node to get the depth from
 *
 * Return: return the depth of @tree
*/

size_t get_depth(const binary_tree_t *tree)
{
	size_t d, parent;

	if (tree == NULL)
		return (0);

	parent = get_depth(tree->parent);

	d = parent + 1;

	return (d);
}
