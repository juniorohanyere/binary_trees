#include <stdlib.h>

#include "binary_trees.h"

/**
 * array_to_bst - function that builds a Binary Search Tree from an array
 *
 * @array: pointer to the first element of the array to be converted
 * @size: the number of element in the array
 *
 * Description: if a value of the array is already present in the tree, this
 *		value must be ignored
 *
 * Return: return a pointer to the root node of the created BST
 *	   return NULL on failure
*/

bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *root = NULL;
	size_t i, j;

	if (array == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < i; j++)
		{
			if (array[j] == array[i])
				break;
		}
		if (j == i)
		{
			if (!bst_insert(&root, array[i]))
				return (NULL);
		}
	}

	return (root);
}
