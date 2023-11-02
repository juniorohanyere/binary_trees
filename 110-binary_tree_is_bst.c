#include <stdlib.h>
#include <limits.h>

#include "binary_trees.h"

/**
 * binary_tree_is_bst - function that checks if a binary tree is a valid Binary
 *			Search Tree
 *
 * @tree: pointer to the root node of the tree to check
 *
 * Description: properties of a binary search tree:
 *		the left subtree of a node contains only nodes with values less
 *		the node's value
 *		the right subtree of a node contains only nodes with values
 *		greater than the node's value
 *		the left and right subtree each must also be a binary search
 *		tree
 *		there must be no duplicate values
 *
 * Return: return 1 if tree is a valid BST
 *	   return 0 otherwise, or if @tree is NULL
*/

int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (is_bst(tree, INT_MIN, INT_MAX));
}
/**
 * is_bst - checks if a given binary tree is a valid bst
 *
 * @tree: pointer to the root node of the tree to check
 * @min: the minimum value
 * @max: the maximum value
 *
 * Return: return 1 if valid
 *	   return 0 otherwise
*/

int is_bst(const binary_tree_t *tree, int min, int max)
{
	int left, right;

	if (tree == NULL)
		return (1);

	if (tree->n < min || tree->n > max)
		return (0);

	left = is_bst(tree->left, min, tree->n - 1);
	right = is_bst(tree->right, tree->n + 1, max);

	return (left && right);
}
