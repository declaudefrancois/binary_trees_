#include "binary_trees.h"

/**
 * find_inorder_successor - finds the successor of a node
 * using the inorder traversal
 * @node: the node
 * Return: a pointer to the inorder successor
 */
bst_t *find_inorder_successor(bst_t *node)
{
		node = node->right;
		while (node->left)
		{
			node = node->left;
		}
		return (node);
}

/**
 * replace_node_with_successor - replaces the node with its successor
 * @root: the root of the tree
 * @node: the node to be replaced
 */
void replace_node_with_successor(bst_t **root, bst_t *node)
{
	bst_t *successor;

	successor = find_inorder_successor(node);
	if (successor->parent)
		successor->parent->left = successor->right;
	if (successor->right)
		successor->right->parent = successor->parent;
	node->right->parent = successor;
	node->left->parent = successor;
	successor->right = node->right;
	successor->left = node->left;
	successor->parent = node->parent;
	if (node == *root)
		*root = successor;
	else if (node->parent)
	{
		if (node->parent && node == node->parent->left)
			node->parent->left = successor;
		else
			node->parent->right = successor;
	}
}

/**
 * one_child - handles the case when node has one child
 * @node: node
 * @child: right OR left child of node
 */
void one_child(bst_t *node, bst_t *child)
{
	child->parent = node->parent;
	if (node == node->parent->right)
		node->parent->right = child;
	else
		node->parent->left = child;
}
/**
 * bst_remove - a function that removes a node from a Binary Search Tree
 * @root: a pointer to the root node of the tree
 * @value: the value to remove in the tree
 * Return: a pointer to the root
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *node;

	if (!root)
		return (NULL);
	node = (bst_t *)root;
	while (node)
	{
		if (node->n == value)
		{
			if (node->left && node->right)
			{
				replace_node_with_successor(&root, node);
			}
			else if (node->left && node->parent)
			{
				one_child(node, node->left);
			}
			else if (node->right && node->parent)
			{
				one_child(node, node->right);
			}

			else if ((node->left || node->right) && !node->parent)
			{
				node->left->parent = NULL;
				root = node->left;
			}
			free(node);
			return (root);
		}
		else if (node->n > value)
			node = node->left;
		else if (node->n < value)
			node = node->right;
	}
	return (root);
}
