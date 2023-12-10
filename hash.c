#include "hash.h"



Hashmap* createHM() {
    Hashmap* map = (Hashmap*)malloc(sizeof(Hashmap));
     if (map == NULL){
        exit(3);
    }
    if (map != NULL) {
        map->head = NULL;
        map->size = 0;
    }
    return map;
}

int functionHash(char* prenom) {
    if (prenom == NULL){
        exit(3);
    }
    int resultat = 0;
    while (*prenom != 0) {
        resultat += *prenom;
        prenom++;
    }
    return resultat;
}

int addHM(Hashmap* map, char* key, int value) {
    if (map == NULL || key == NULL) {
        return 0;
    }
    int hashValue = functionHash(key);
    insertABR(&((map)->head), key, value, hashValue);
    map->size++;
    return 1;
}

int sizeHM(Hashmap* map) {
    if (map == NULL){
        exit(3);
    }
    return map ? map->size : 0;
}

void display(Hashmap* map) {
    if (map != NULL) {
        displayTree(map->head);
        printf("\n");
    }
    else exit(3);
}

void freeHM(Hashmap* map){
    if (map == NULL){
        exit(3);
    }
    freeTree(map->head);
    free(map);
}

TreeNode* getHM(Hashmap* map, char* key) { 
    if (map == NULL || key == NULL){
        return NULL;
    }
    int hashValue = functionHash(key);
    return search(map->head, hashValue);
}

int updateHM(Hashmap* map, char* key, int newValue) {
    if (map == NULL || key == NULL) {
        return 0;
    }
    TreeNode* new = getHM(map, key);
    if (new != NULL) {
        updateNodeValue(map->head->list, key, newValue);
        printf("Mise à jour de la valeur pour la clé '%s' effectuée.\n", key);
        return 1;
    } else {
        printf("Clé '%s' non trouvée. Aucune mise à jour effectuée.\n", key);
        return 0;
    }
}

int removeHM(Hashmap* map, char* key) {
    if (map == NULL || key == NULL) {
        return 0;
    }
    int hashValue = functionHash(key);
    TreeNode* root = map->head;
    TreeNode* parent = NULL;
    TreeNode* current = root;
    while (current != NULL && current->key != hashValue) {
        parent = current;
        current = (hashValue < current->key) ? current->left : current->right;
    }
    if (current == NULL) {
        printf("Clé '%s' non trouvée. Aucune suppression effectuée.\n", key);
        return 0;
    }
    if (current->list != NULL && current->list->next == NULL) {
        freeList(current->list);
        current->list = NULL;
        if (current->left == NULL && current->right == NULL) {
            if (parent == NULL) {
                free(current);
                map->head = NULL;
            } else {
                if (parent->left == current) {
                    parent->left = NULL;
                } else {
                    parent->right = NULL;
                }
                free(current);
            }
        }
        else if (current->left == NULL) {
            if (parent == NULL) {
                map->head = current->right;
                free(current);
            } else {
                if (parent->left == current) {
                    parent->left = current->right;
                } else {
                    parent->right = current->right;
                }
                free(current);
            }
        } else if (current->right == NULL) {
            if (parent == NULL) {
                map->head = current->left;
                free(current);
            } else {
                if (parent->left == current) {
                    parent->left = current->left;
                } else {
                    parent->right = current->left;
                }
                free(current);
            }
        }
        else {
            TreeNode* successor = current->right;
            TreeNode* successorParent = current;
            while (successor->left != NULL) {
                successorParent = successor;
                successor = successor->left;
            }
            current->key = successor->key;
            freeList(current->list);
            current->list = successor->list;
            if (successorParent->left == successor) {
                successorParent->left = successor->right;
            } else {
                successorParent->right = successor->right;
            }
            free(successor);
        }
        map->size--;
        printf("Suppression de la clé '%s' effectuée.\n", key);
        return 1;
    }
    else if (current->list != NULL) {
        Node* prev = NULL;
        Node* temp = current->list;
        while (temp != NULL && strcmp(temp->key, key) != 0) {
            prev = temp;
            temp = temp->next;
        }
        if (prev == NULL) {
            current->list = temp->next;
        } else {
            prev->next = temp->next;
        }
        free(temp->key);
        free(temp);
        map->size--;
        printf("Suppression de la clé '%s' effectuée.\n", key);
        return 1;
    }
    printf("Clé '%s' non trouvée. Aucune suppression effectuée.\n", key);
    return 0;
}
