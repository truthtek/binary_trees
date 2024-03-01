#include "binary_trees.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * binary_tree_levelorder - Goes through a binary tree using level-order traversal
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node. The value in the node must be passed as a parameter to this function.
 * If tree or func is NULL, do nothing
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
int height = binary_tree_height(tree);
int i;
if (tree == NULL || func == NULL)
return;
for (i = 1; i <= height + 1; i++)
binary_tree_traverse_level(tree, func, i);
}
