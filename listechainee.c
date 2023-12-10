#include "listechainee.h"



Node* createNode(char* key, int value) {
    if (key == NULL) {
        exit(1);
    }
    Node* newNode = malloc(sizeof(Node));
    if (newNode == NULL){
        exit(1);
    }
    else{
        newNode->key = strdup(key);
        newNode->value = value;
        newNode->next = NULL;
    }
    return newNode;
}

int addNode(Node** head, char* key, int value) { 
    if(!head){
        exit(1);
    }
     if (key == NULL) {
        exit(1);
    }
    if (*head == NULL) {
        Node* newNode = createNode(key, value);
        if (!newNode) {
            exit(1);
        }
        *head = newNode;
    } 
    else {
        Node* current = *head;
        while (current->next != NULL) { 
            if(strcmp(current->key, key) == 0){
                printf("the key already exists \n");
                return 0;
            }
        current = current->next;
        }
        if(strcmp(current->key, key) == 0){
            printf("the key already exists \n");    
            return 0;
        }
        Node* newNode = createNode(key, value);
        if (!newNode) {
            exit(1);
        }
        current->next = newNode;
    }
    return 1;
}

void freeList(Node* head) { 
    if(!head){
        exit(1);
    }
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        free(temp->key);
        temp -> key = NULL;
        free(temp);
    }
}

void displayList(Node* head) {
    if(!head){
        exit(1);
    }
    Node* current = head;
    while (current != NULL) {
        printf("%d/%s ->", current->value, current->key);
        current = current->next;
    }
}

void updateNodeValue(Node* head, char* key, int newValue) {
     if (head == NULL || key == NULL) {
        exit(1);
    }
    Node* current = head;
    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            // Clé trouvée, mettre à jour la valeur
            current->value = newValue;
            return;  // Sortir de la boucle dès que la mise à jour est effectuée
        }
        current = current->next;
    }
}