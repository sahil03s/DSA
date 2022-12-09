#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct node
{
    int data;
    int priority;
    struct node *next;
} node;

void enqueue(node **head, int x, int p)
{
    node *temp = (node*)malloc(sizeof(node));
    if(!temp)
    {
        printf("Overflow!");
        return;
    }

    temp->data = x;
    temp->priority = p;
    if(!*head || (*head)->priority < temp->priority)
    {
        temp->next = *head;
        *head = temp;
    }
    else
    {
        node *q = *head, *prev = NULL;
        for(;q != NULL && q->priority >= temp->priority; q = q->next)
            prev = q;

        temp->next = q;
        prev->next = temp;

    }
}

int dequeue(node **head)
{
    if(!*head)
    {
        printf("Underflow!");
        return INT_MIN;
    }
    int x = (*head)->data;
    node *q = *head;
    *head = (*head)->next;
    free(q);
    return x;
}

int peek(node *head)
{
    if(!head)
    {
        printf("Overflow!");
        return INT_MIN;
    }
    return head->data;
}
void display(node *head)
{
    printf("\n");
    if(!head)
    {
        printf("Overflow!");
        return;
    }
    while(head)
    {
        printf("%d ",head->data);
        head = head->next;
    }
    printf("\n");
}

void main()
{
    node *head = NULL;
    display(head);
    enqueue(&head,2,5);
    display(head);
    enqueue(&head,3,3);
    display(head);
    enqueue(&head,4,1);
    display(head);
    enqueue(&head,0,5);
    display(head);
    dequeue(&head);
    display(head);
    dequeue(&head);
    display(head);
    enqueue(&head,10,5);
    display(head);
    enqueue(&head,11,12);
    display(head);
}