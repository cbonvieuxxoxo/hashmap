#include "abr.h"



TreeNode* createTreeNode(char* key, int value, int hash) {
     if (key == NULL) {
        exit(2);
    }
    TreeNode* newNode = malloc(sizeof(TreeNode));
    if (newNode == NULL) {
        exit(2);
    }
    newNode->key = hash;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->list = NULL;
    addNode(&(newNode->list), key, value);
    return newNode;
}

void insertABR(TreeNode** root, char* key, int value, int hash) {
    if(root == NULL || key == NULL){
        exit(2);
    }
    if (*root == NULL) {
        *root = createTreeNode(key, value, hash);
    } 
    else {
        if (hash == (*root)->key) {                   
            addNode(&((*root)->list), key, value);
        } 
        else {
            insertABR((hash < (*root)->key) ? &((*root)->left) : &((*root)->right), key, value, hash);
        }
    }
}

void freeTree(TreeNode* root) {
    if (root != NULL) {
        freeTree(root->left);
        root -> left = NULL;
        freeTree(root->right);
        root -> right = NULL;
        freeList(root->list);
        root->list = NULL;
        free(root);
    }
}

void displayTree(TreeNode* root) {
    if (root != NULL) {
        displayTree(root->left);
        displayList(root->list);
        printf("\n");
        displayTree(root->right);
    }
}

TreeNode* search(TreeNode* root, int hash) {
    if (root == NULL){
        return NULL;
    }
    if(root->key == hash){
        return root;
    }
    else if (root->key > hash){
        return search(root->left, hash);
    }
    return search(root->right, hash);
}