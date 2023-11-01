#include <stdlib.h>
#include <stdio.h>

#include "binary_trees.h"

/**
 * binary_tree_height - function that measures the height of a binary tree
 *
 * @tree: pointer to the root node of the tree to measure the height.
 *
 * Return: return 0 if tree is NULL
*/

size_t binary_tree_height(const binary_tree_t *tree)
{
	int height;

	if (tree == NULL)
		return (0);

	height = get_height(tree) - 1;

	return (height);
}

/**
 * get_height - gets the height of a binary tree
 *
 * @tree: pointer to the root node of the tree to get the height
 *
 * Return: return the hight of the tree
*/

size_t get_height(const binary_tree_t *tree)
{
	size_t h, left, right;

	if (tree == NULL)
		return (0);

	left = get_height(tree->left);
	right = get_height(tree->right);

	/* return the maximum of left and right subtree heights,*/
	/* plus 1 for the current node */
	h = (left > right) ? (left + 1) : (right + 1);

	return (h);
}
