#include "binary_trees.h"

/**
 * heap_insert - Inserts a value into a Max Binary Heap
 * @root: Double pointer to the root node of the Heap
 * @value: Value to store in the node to be inserted
 * Return: Pointer to the inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
    heap_t *new_node, *parent;
    if (!root)
        return (NULL);

    new_node = binary_tree_node(NULL, value);
    if (!new_node)
        return (NULL);

    if (!*root)
    {
        *root = new_node;
        return (new_node);
    }

    parent = get_parent(*root);
    if (!parent->left)
        parent->left = new_node;
    else
        parent->right = new_node;

    new_node->parent = parent;
    return (new_node);
}

/**
 * get_parent - Helper function to get the parent node of the new node
 * @root: Pointer to the root node of the Heap
 * Return: Pointer to the parent node of the new node
 */
heap_t *get_parent(heap_t *root)
{
    heap_t *parent;
    size_t size;

    size = binary_tree_size(root);
    if (size % 2 == 0)
        parent = find_parent_even(root, size);
    else
        parent = find_parent_odd(root, size);

    return (parent);
}

/**
 * find_parent_even - Helper function to find the parent node of the new node
 * when the number of nodes in the Heap is even
 * @root: Pointer to the root node of the Heap
 * @size: Number of nodes in the Heap
 * Return: Pointer to the parent node of the new node
 */
heap_t *find_parent_even(heap_t *root, size_t size)
{
    heap_t *parent = root;
    size_t i;

    for (i = 0; i < size / 2 - 1; i++)
    {
        if (i % 2 == 0)
            parent = parent->left;
        else
            parent = parent->right;
    }

    return (parent);
}

/**
 * find_parent_odd - Helper function to find the parent node of the new node
 * when the number of nodes in the Heap is odd
 * @root: Pointer to the root node of the Heap
 * @size: Number of nodes in the Heap
 * Return: Pointer to the parent node of the new node
 */
heap_t *find_parent_odd(heap_t *root, size_t size)
{
    heap_t *parent = root;
    size_t i;

    for (i = 0; i < size / 2; i++)
    {
        if (i % 2 == 0)
            parent = parent->left;
        else
            parent = parent->right;
    }

    return (parent);
}
