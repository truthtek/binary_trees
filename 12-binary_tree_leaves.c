#include "binary_trees.h"

/**
 * binary_tree_leaves - Counts the leaves in a binary tree
 * @tree: Pointer to the root node of the tree to count the leaves
 *
 * Return: The number of leaves in the tree, or 0 if tree is NULL
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
size_t left_leaves = 0, right_leaves = 0;
if (tree == NULL)
return (0);
if (tree->left == NULL && tree->right == NULL)
return (1);
if (tree->left != NULL)
left_leaves = binary_tree_leaves(tree->left);
if (tree->right != NULL)
right_leaves = binary_tree_leaves(tree->right);
return (left_leaves + right_leaves);
}
