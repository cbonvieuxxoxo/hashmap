/**
 * @file liste_chainee.h
 * @brief Header file for a simple linked list implementation with key-value pairs.
 */

#ifndef LISTE_CHAINEE_H
#define LISTE_CHAINEE_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * @struct Node
 * @brief Represents a node in the linked list with key-value pairs.
 */
typedef struct Node {
    char* key;           /**< The key of the node. */
    int value;           /**< The value associated with the key. */
    struct Node* next;   /**< Pointer to the next node in the list. */
} Node;

/**
 * @brief Creates a new node with the given key and value.
 *
 * @param key The key for the new node.
 * @param value The value associated with the key.
 * @return A pointer to the newly created node.
 */
Node* createNode(char* key, int value);

/**
 * @brief Adds a new node with the specified key and value to the linked list.
 *
 * If a node with the same key already exists, the function prints an error message
 * and does not add the duplicate key.
 *
 * @param head A pointer to the head of the linked list.
 * @param key The key for the new node.
 * @param value The value associated with the key.
 * @return 1 if the node is successfully added, 0 if a node with the same key already exists.
 */
int addNode(Node** head, char* key, int value);

/**
 * @brief Frees the memory allocated for the entire linked list.
 *
 * @param head A pointer to the head of the linked list.
 */
void freeList(Node* head);

/**
 * @brief Displays the key-value pairs in the linked list.
 *
 * @param head A pointer to the head of the linked list.
 */
void displayList(Node* head);

/**
 * @brief Updates the value associated with a specific key in the linked list.
 *
 * If the key is not found, the function does nothing.
 *
 * @param head A pointer to the head of the linked list.
 * @param key The key to be updated.
 * @param newValue The new value to be associated with the key.
 */
void updateNodeValue(Node* head, char* key, int newValue);

#endif
