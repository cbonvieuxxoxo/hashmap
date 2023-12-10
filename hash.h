/**
 * @file hash.h
 * @brief Header file for an implementation of a Hashmap with an Augmented Binary Search Tree (ABR)
 *        and associated linked lists for collision resolution.
 */

#ifndef HASH_H
#define HASH_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "abr.h"

/**
 * @struct Hashmap
 * @brief Represents a Hashmap with an Augmented Binary Search Tree (ABR).
 */
typedef struct Hashmap {
    int size;          /**< The number of elements in the hashmap. */
    TreeNode* head;    /**< The root of the ABR in the hashmap. */
} Hashmap;

/**
 * @brief Creates a new Hashmap.
 *
 * @return A pointer to the newly created Hashmap.
 */
Hashmap* createHM();

/**
 * @brief Computes a hash value for a given string.
 *
 * @param prenom The string for which to compute the hash value.
 * @return The computed hash value.
 */
int functionHash(char* prenom);

/**
 * @brief Adds a key-value pair to the Hashmap.
 *
 * @param map A pointer to the Hashmap.
 * @param key The key to be added.
 * @param value The value associated with the key.
 * @return 1 if the key-value pair is successfully added, 0 otherwise.
 */
int addHM(Hashmap* map, char* key, int value);

/**
 * @brief Retrieves the tree node with a specific key in the Hashmap.
 *
 * @param map A pointer to the Hashmap.
 * @param key The key to search for.
 * @return A pointer to the tree node with the specified key, or NULL if not found.
 */
TreeNode* getHM(Hashmap* map, char* key);

/**
 * @brief Retrieves the number of elements in the Hashmap.
 *
 * @param map A pointer to the Hashmap.
 * @return The number of elements in the Hashmap.
 */
int sizeHM(Hashmap* map);

/**
 * @brief Displays the contents of the Hashmap and associated linked lists.
 *
 * @param map A pointer to the Hashmap.
 */
void display(Hashmap* map);

/**
 * @brief Updates the value associated with a specific key in the Hashmap.
 *
 * @param map A pointer to the Hashmap.
 * @param key The key to be updated.
 * @param newValue The new value to be associated with the key.
 * @return 1 if the update is successful, 0 if the key is not found.
 */
int updateHM(Hashmap* map, char* key, int newValue);

/**
 * @brief Frees the memory allocated for the Hashmap and its associated structures.
 *
 * @param map A pointer to the Hashmap.
 */
void freeHM(Hashmap* map);

/**
 * @brief Removes a key and its associated value from the Hashmap.
 *
 * @param map A pointer to the Hashmap.
 * @param key The key to be removed.
 * @return 1 if the removal is successful, 0 if the key is not found.
 */
int removeHM(Hashmap* map, char* key);

#endif
