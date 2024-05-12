#include <stdio.h>
#include <stdlib.h>

typedef struct element
{
    int data;
    struct element *next;
} listElement;

listElement *head;

/* dodaje element na końcu listy */
void push(int value)
{
    listElement *current;

    if (head == NULL)
    {
        head = (listElement *)malloc(sizeof(listElement));
        head->data = value;
        return;
    }

    current = head;
    while (current->next != NULL)
        current = (listElement *)current->next;

    current->next = (listElement *)malloc(sizeof(listElement));
    current = current->next;
    current->data = value;
}

/* usuwa ostatni element i go zwraca */
int pop()
{
    int v;
    listElement *current, *prev = NULL;

    if (head == NULL)
        return -1;

    current = head;
    while (current->next != NULL)
    {
        prev = current;
        current = (listElement *)current->next;
    }

    v = current->data;
    free(current);
    if (prev != NULL)
        prev->next = NULL;
    else
        head = NULL;

    return v;
}

/* zwraca element na pozycji */
int get(int index)
{
    int i = 0;
    listElement *current;

    if (head == NULL)
        return -1;

    current = head;
    while (i < index)
    {
        current = (listElement *)current->next;
        if (current == NULL)
            break;
        i++;
    }

    if (current == NULL)
        return -2;

    return current->data;
}

/* dodaje element na początku */
void shift(int value)
{
    listElement *prevHead, *newHead;

    if (head == NULL)
    {
        push(value);
        return;
    }

    prevHead = head;
    newHead = (listElement *)malloc(sizeof(listElement));

    newHead->data = value;
    newHead->next = prevHead;
    head = newHead;
}

/* usuwa element z początku i go zwraca */
int unshift()
{
    int v;
    listElement *newHead;

    if (head == NULL)
        return -1;

    newHead = head->next;
    v = head->data;
    free(head);
    head = newHead;

    return v;
}

int main(int argc, char **argv)
{
    shift(10);
    push(20);
    push(30);
    push(40);
    push(50);

    printf("%d\n", get(4)); /* 50 */
    pop();
    printf("%d\n", get(4)); /* -2 */
    shift(60);
    printf("%d\n", get(4));    /* 40 */
    printf("%d\n", get(0));    /* 60 */
    printf("%d\n", unshift()); /* 60 */
    printf("%d\n", get(0));    /* 10 */
    printf("%d\n", pop());     /* 40 */
    printf("%d\n", pop());     /* 30 */
    printf("%d\n", pop());     /* 20 */
    printf("%d\n", pop());     /* 10 */
    printf("%d\n", pop());     /* -1 */
    printf("%d\n", pop());     /* -1 */
    push(10);
    printf("%d\n", get(0));    /* 10 */
    printf("%d\n", unshift()); /* 10 */
    printf("%d\n", unshift()); /* -1 */

    return 0;
}
