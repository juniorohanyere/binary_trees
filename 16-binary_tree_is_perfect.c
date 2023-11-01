#include <stdlib.h>

#include "binary_trees.h"

/**
 * binary_tree_is_perfect - a function that checks if a binary tree is perfect
 *
 * @tree: pointer to the root node of the tree to check
 *
 * Return: return 0 if @tree is NULL
*/

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int l, left, r, right;

	if (tree == NULL)
		return (0);

	/* get the depth of the left and right subtrees */
	left = get_node_depth(tree->left);
	right = get_node_depth(tree->right);

	/* check if the left and right subtrees have the same depth */
	if (left != right)
		return (0);

	/* recursively check if both left and right subtrees are perfect */
	l = binary_tree_is_perfect(tree->left) + 1;
	r = binary_tree_is_perfect(tree->right) + 1;

	return (l && r);
}

/**
 * get_node_depth - get the depth of a given node
 *
 * @tree: pointer to the root node of the depth to get
 *
 * Return: return the depth of @tree
*/

int get_node_depth(const binary_tree_t *tree)
{
	int left, right;

	if (tree == NULL)
		return (0);

	left = get_node_depth(tree->left);
	right = get_node_depth(tree->right);

	return (1 + (left > right ? left : right));
}
