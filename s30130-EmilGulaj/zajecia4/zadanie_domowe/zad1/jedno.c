#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node * next;
} Node;

void append(Node **head, int data){
    if (*head == NULL){
        *head = (Node*)malloc(sizeof(Node));
        (*head) -> data = data;
        (*head) -> next = NULL;
    }
    else{
        Node *current = *head;
        while (current -> next != NULL){
            current = current -> next;
        }
        current -> next = (Node*)malloc(sizeof(Node));
        current -> next -> data = data;
        current -> next -> next = NULL;
    }
}

void push(Node **head, int data){
    Node  *current;
    current = (Node*)malloc(sizeof(Node));
    current -> data = data;
    current -> next = *head;
    *head = current;
}

void pop_front(Node **head){
    Node *current;
    if (*head != NULL){
        current = (*head) -> next;;
        free(*head);
        *head = current;
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
    
    return 0;
}
