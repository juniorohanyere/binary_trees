#include <stdlib.h>

#include "binary_trees.h"

/**
 * binary_tree_preorder - a function that goes through a binary tree using
 *			  pre-order traversal
 *
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node
 *
 * Description: the value in the node must be passed as a parameter to the
 *		@func
 *		if @tree or @func is NULL, do nothing
 *
 * Return: return nothing
*/

void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	func(tree->n);

	/* preorder traversal => root->left->right */
	/* no need to recurse on the root tree/node :) */
	/* that shit almost confused me, infinite loop! */
	binary_tree_preorder(tree->left, func);
	binary_tree_preorder(tree->right, func);
}
