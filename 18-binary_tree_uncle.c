#include <stdlib.h>

#include "binary_trees.h"

/**
 * binary_tree_uncle - function that finds the uncle of a node
 *
 * @node: pointer to the node to find the uncle
 *
 * Return: return a pointer to the uncle node
 *	   return NULL if node is NULL or has no uncle
*/

binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return (NULL);

	return (tree_sibling(node->parent));
}

/**
 * tree_sibling - function that finds the sibling of a node
 *
 * @node: pointer to the node to find the sibling
 *
 * Return: return a pointer to the sibling node
 *	   return NULL if @node or the parent is NULL
 *	   return NULL if node has no sibling
*/

binary_tree_t *tree_sibling(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return (NULL);

	if (node == node->parent->right)
		return (node->parent->left);

	return (node->parent->right);
}
