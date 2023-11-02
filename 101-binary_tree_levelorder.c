#include <stdlib.h>

#include "binary_trees.h"

/**
 * binary_tree_levelorder - function that goes through a binary tree using
 *			    level-order traversal
 *
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node
 *
 * Description: the value in the node must be passed as a parameter to this
 *		function
 *		do nothing if @func is NULL
 *
 * Return: return nothing
*/

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	int i, level;
	binary_tree_t *tmp;

	if (tree == NULL || func == NULL)
		return;

	level = tree_height(tree);
	tmp = (binary_tree_t *)tree;

	for (i = 0; i <= level + 1; i++)
		tree_levelorder(tmp, func, i);
}

/**
 * tree_levelorder - gets the level-order of a given binary tree
 *
 * @tree: pointer to the root node of the binary tree
 * @func: pointer to a function to call
 * @level: integer value representing the level of nodes in the binary tree
 *
 * Return: return nothing
*/

void tree_levelorder(const binary_tree_t *tree, void (*func)(int), int level)
{
	if (tree == NULL || func == NULL)
		return;

	if (level == 1)
		func(tree->n);

	if (level > 1)
	{
		tree_levelorder(tree->left, func, level - 1);
		tree_levelorder(tree->right, func, level - 1);
	}
}

/**
 * tree_height - function that measures the height of a binary tree
 *
 * @tree: pointer to the root node of the tree to measure the height.
 *
 * Return: return 0 if tree is NULL
*/

size_t tree_height(const binary_tree_t *tree)
{
	int height;

	if (tree == NULL)
		return (0);

	height = get_tree_height(tree) - 1;

	return (height);
}

/**
 * get_tree_height - gets the height of a binary tree
 *
 * @tree: pointer to the root node of the tree to get the height
 *
 * Return: return the hight of the tree
*/

size_t get_tree_height(const binary_tree_t *tree)
{
	size_t h, left, right;

	if (tree == NULL)
		return (0);

	left = get_tree_height(tree->left);
	right = get_tree_height(tree->right);

	/* return the maximum of left and right subtree heights,*/
	/* plus 1 for the current node */
	h = (left > right) ? (left + 1) : (right + 1);

	return (h);
}
