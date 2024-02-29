#include "binary_trees.h"

/**
 * binary_tree_nodes - Counts the nodes with at least 1 child in a 
 * @tree: Pointer to the root node of the tree to count the nodes
 *
 * Return: The number of nodes with at least 1 child in the tree, or 
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
size_t left_nodes = 0, right_nodes = 0;
if (tree == NULL)
return (0);
if (tree->left != NULL || tree->right != NULL)
return (1 + binary_tree_nodes(tree->left) + binary_tree_nodes(tree->right));
return (0);
}
