#include <stdlib.h>

#include "binary_trees.h"

/**
 * binary_tree_balance - a function that measures the balance factor of a
 *			 binary tree
 *
 * @tree: pointer to the root node of the tree to measure the balance factor
 *
 * Return: return 0 if @tree is NULL
*/

int binary_tree_balance(const binary_tree_t *tree)
{
	int balance;
	size_t left, right;

	if (tree == NULL)
		return (0);

	left = tree_height(tree->left) - 1;
	right = tree_height(tree->right) - 1;

	balance = left - right;

	return (balance);
}

/**
 * tree_height - gets the height of a given binary tree
 *
 * @tree: pointer to the root node of the tree to get the height
 *
 * Return: return the height of the given binary tree
*/

size_t tree_height(const binary_tree_t *tree)
{
	size_t h, left, right;

	if (tree == NULL)
		return (0);

	left = tree_height(tree->left);
	right = tree_height(tree->right);

	if (left > right)
		h = left + 1;
	else
		h = right + 1;

	return (h);
}
