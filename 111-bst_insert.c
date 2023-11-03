#include <stdlib.h>

#include "binary_trees.h"

/**
 * bst_insert - function that inserts a value in a Binary Search Tree
 *
 * @tree: double pointer to the root node of the BST to insert the value
 * @value: the value to store in the node to be inserted
 *
 * Description: if the address stored in @tree is NULL, the created node must
 *		become the root node
 *		if the value is already present in the tree, it must be ignored
 *
 * Return: return a pointer to the created node
 *	   return NULL on failure
*/

bst_t *bst_insert(bst_t **tree, int value)
{
	if (tree == NULL || *tree == NULL)
		return (*tree = binary_tree_node(NULL, value));

	if ((*tree)->n > value)
	{
		if ((*tree)->left == NULL)
			return (tree_insert_left(*tree, value));

		return (bst_insert(&((*tree)->left), value));
	}

	if ((*tree)->n < value)
	{
		if ((*tree)->right == NULL)
			return (tree_insert_right(*tree, value));

		return (bst_insert(&((*tree)->right), value));
	}

	return (NULL);
}

/**
 * tree_insert_left - function that inserts a node as the left-child of
 *		      another node
 *
 * @parent: the parent node
 * @value: the value to put into the node to be created
 *
 * Return: return a pointer to the newly created node
*/

binary_tree_t *tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *node;

	if (parent == NULL)
		return (NULL);

	node = malloc(sizeof(binary_tree_t));
	if (node == NULL)
		return (NULL);

	node->n = value;
	node->parent = parent;
	node->right = NULL;
	/* check if the parent node already has a left node */
	if (parent->left == NULL)
		node->left = NULL;
	else
	{
		node->left = parent->left;
		node->left->parent = node;
	}

	parent->left = node;

	return (node);
}

/**
 * tree_insert_right - function that inserts a node as the right-child
 *		       of another node
 *
 * @parent: pointer to the node to insert the right-child in
 * @value: value to store in the new node
 *
 * Description: if parent already has a right-child, the new node must take its
 *		place, and the old right-child must be set as the right-child
 *		of the new node
 *
 * Return: return a pointer to the created node
 *	   return NULL on failure of if parent is NULL
*/

binary_tree_t *tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *node;

	if (parent == NULL)
		return (NULL);

	node = malloc(sizeof(binary_tree_t));
	if (node == NULL)
		return (NULL);

	node->n = value;
	node->parent = parent;
	node->left = NULL;
	/* check if the parent node already has a right node */
	if (parent->right == NULL)
		node->right = NULL;
	else
	{
		node->right = parent->right;
		node->right->parent = node;
	}

	/* set the right-child of the parent to the new node created */
	parent->right = node;

	return (node);
}
