#include <stdlib.h>

#include "binary_trees.h"

/**
 * binary_trees_ancestor - function that finds the lowest common ancestor of
 *			   two nodes
 *
 * @first: pointer to the first node
 * @second: pointer to the second node
 *
 * Return: return a pointer to the lowest common ancestor node of the two given
 *	   nodes
 *	   return NULL if no common ancestor was found
*/

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
	const binary_tree_t *second)
{
	binary_tree_t *ancestor = NULL, *f, *s;

	if (first == NULL || second == NULL)
		return (NULL);

	if (first == second)
		return ((binary_tree_t *)first);

	f = (binary_tree_t *)first;
	while (f != NULL)
	{
		s = (binary_tree_t *)second;
		while (s != NULL)
		{
			if (f == s)
			{
				ancestor = f;
				break;
			}
			s = s->parent;
		}

		if (ancestor)
			break;

		f = f->parent;
	}

	return (ancestor);
}
