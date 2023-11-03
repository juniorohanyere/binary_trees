#include <stdlib.h>

#include "binary_trees.h"

/**
 * bst_remove - a function that removes a node from a Binary Search Tree
 *
 * @root: pointer to the root node of the tree where a node will be removed
 * @value: the value to remove in the tree
 *
 * Description: once located, the node containing a value equals to @value must
 *		be removed and freed
 *		if the node to be deleted has two children, it must be replaced
 *		with its first in-order successor (not predecessor)
 *
 * Return: return a pointer to the new root node of the tree after removing the
 *	   desired value
*/

bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *tmp;

	if (root == NULL)
		return (NULL);

	/* recursively search for the node to remove */
	if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		/* node with the value found, handle different cases */
		if (root->left == NULL)
		{
			tmp = root->right;
			free(root);
			return (tmp);
		}
		else if (root->right == NULL)
		{
			tmp = root->left;
			free(root);
			return (tmp);
		}

		/* node has two children, replace with in-order successor */
		tmp = bst_get_min(root->right);
		root->n = tmp->n;
		root->right = bst_remove(root->right, tmp->n);
	}

	return (root);
}

/**
 * bst_get_min - gets the node with the minimum value in the tree
 *
 * @root: pointer to the root node
 *
 * Return: return a pointer to the minimum node in the tree
*/

bst_t *bst_get_min(bst_t *root)
{
	while (root->left)
		root = root->left;

	return (root);
}
