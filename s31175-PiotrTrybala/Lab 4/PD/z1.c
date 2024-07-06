#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node *next;
};

void insert(struct Node** lista, int value)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        
    newNode->value = value;
    
    newNode->next = NULL;
    
    if (*lista == NULL) {
        *lista = newNode;
        return;
    }
    
    struct Node* current = *lista;
    while (current->next != NULL) {
        current = current->next;
    }
    
    current->next = newNode;
}

void printNode(struct Node**lista, int index) {
    int i=0;
    struct Node* current = *lista;
    
    while (current->next != NULL) {
        if (i==index) {
            printf("%i",current->value);
            return;
        }
        else {
            i++;
            current = current->next;
        }
    }
    printf("%i",current->value);
}

int main(int argc, char* argv[]) {
    
    struct Node* lista = NULL;
    insert(&lista, 20);
    insert(&lista, 30);
    insert(&lista, 40);
    insert(&lista, 50);

    printNode(&lista, 2);

    return 0;
}