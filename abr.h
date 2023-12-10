/**
 * @file abr.h
 * @brief Header file for an implementation of an Augmented Binary Search Tree (ABR)
 *        with associated linked lists for each node.
 */

#ifndef ABR_H
#define ABR_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "listechainee.h"

/**
 * @struct TreeNode
 * @brief Represents a node in the Augmented Binary Search Tree (ABR).
 */
typedef struct TreeNode {
    int key;                /**< The key of the tree node. */
    struct Node* list;      /**< Linked list associated with the tree node. */
    struct TreeNode* left;  /**< Pointer to the left child of the tree node. */
    struct TreeNode* right; /**< Pointer to the right child of the tree node. */
} TreeNode;

/**
 * @brief Creates a new tree node with the given key, value, and hash.
 *
 * @param key The key for the new tree node.
 * @param value The value associated with the key (for the linked list).
 * @param hash The hash value used for comparison in the ABR.
 * @return A pointer to the newly created tree node.
 */
TreeNode* createTreeNode(char* key, int value, int hash);

/**
 * @brief Inserts a new node with the specified key and value into the ABR.
 *
 * If a node with the same hash value already exists, the function adds the key-value
 * pair to the associated linked list.
 *
 * @param root A pointer to the root of the ABR.
 * @param key The key for the new node.
 * @param value The value associated with the key.
 * @param hash The hash value used for comparison in the ABR.
 */
void insertABR(TreeNode** root, char* key, int value, int hash);

/**
 * @brief Frees the memory allocated for the entire ABR and associated linked lists.
 *
 * @param root A pointer to the root of the ABR.
 */
void freeTree(TreeNode* root);

/**
 * @brief Displays the ABR and associated linked lists in an in-order traversal.
 *
 * @param root A pointer to the root of the ABR.
 */
void displayTree(TreeNode* root);

/**
 * @brief Searches for a tree node with a specific hash value in the ABR.
 *
 * @param root A pointer to the root of the ABR.
 * @param hash The hash value to search for.
 * @return A pointer to the tree node with the specified hash value, or NULL if not found.
 */
TreeNode* search(TreeNode* root, int hash);

/**
 * @brief Removes a node with a specific key from the ABR and associated linked lists.
 *
 * @param root A pointer to the root of the ABR.
 * @param key The key to be removed.
 */
void removeNode(TreeNode* root, char* key);

#endif
