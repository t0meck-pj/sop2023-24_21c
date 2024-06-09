#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node * previous;
    struct Node * next;
} Node;

void append(Node **head, int data){
    if (*head == NULL){
        *head = (Node*)malloc(sizeof(Node));
        if (*head == NULL){
            printf("Blad alokacji pamieci");
            return -1;
        }
        (*head) -> data = data;
        (*head) -> previous = NULL;
        (*head) -> next = NULL;
    }
    else{
        Node *current = *head;
        while (current -> next != NULL){
            current = current -> next;
        }
        current -> next = (Node*)malloc(sizeof(Node));
        if (current == NULL){
            printf("Blad alokacji pamieci");
            return -1;
        }
        current -> next -> data = data;
        current -> next -> previous = current;
        current -> next -> next = NULL;
    }
}

void push(Node **head, int data){
    if(*head == NULL){
        *head = (Node*)malloc(sizeof(Node));
        if (*head == NULL){
            printf("Blad alokacji pamieci");
            return -1;
        }
        (*head) -> data = data;
        (*head) -> previous = NULL;
        (*head) -> next = NULL;
    }
    else{
        Node *current;
        current = (Node*)malloc(sizeof(Node));
        if (current == NULL){
            printf("Blad alokacji pamieci");
            return -1;
        }
        current -> data = data;
        current -> previous = NULL;
        current -> next = (*head);
        (*head) -> previous = current;
        *head = current;
    }
}

void pop_front(Node **head){
    if((*head) -> next == NULL){
        *head=NULL;
    }
    else{
        Node *current;
        current = (*head) -> next;
        free(*head);
        *head = current;
        (*head) -> previous = NULL;
    }
}

void pop_back(Node **head){
    if((*head) -> next == NULL){
        *head = NULL;
    }
    else{
        Node *current = *head;
        while(current -> next -> next != NULL){
            current = current -> next;
        }
        free(current -> next);
        current -> next = NULL;
    }
}

void show(Node *head){
    Node *current = head;
    while (current != NULL){
        printf("%d", current -> data);
        printf("\n");
        current = current -> next;
    }
    printf("\n");
}

void size(Node *head){
    Node *current = head;
    int counter = 0;
    while (current != NULL){
        counter++;
        current = current -> next;
    }
    printf("The size is: %d\n", counter);
}


int main(){
    Node *head = NULL;

    push(&head, 6);
    pop_front(&head);

    append(&head, 1);
    append(&head, 2);
    append(&head, 3);
    push(&head, 4);
    show(head);

    size(head);

    pop_back(&head);
    push(&head, 5);
    show(head);
    

    pop_front(&head);
    show(head);

    Node *current = head;
    Node *next_node;
    while (current != NULL) {
        next_node = current->next;
        free(current);
        current = next_node;
    }

    return 0;
}
