#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

void enqueue(node **front,node **rear, int x)
{
    node *temp = (node *)malloc(sizeof(node));
    if(!temp)
        return;
    
    temp->data = x;
    temp->next = NULL;

    if(!*rear)
        *front = *rear = temp;
    else
    {
        (*rear)->next = temp;
        *rear = temp;
    }
}

int dequeue(node **front, node **rear)
{
    if(!*front)
    {
        printf("Underflow!\n");
        return INT_MIN;
    }
    int x = (*front)->data;
    if(*front == *rear)

    {
        free(*front);
        *front = *rear = NULL;
    }
    else
    {
        node *temp = *front;
        *front = (*front)->next;
        free(temp);
    }

    return x;
}
void display(node *front)
{
    if(!front)
    {
        printf("Underflow!");
        return;
    }
    printf("\n");

    while(front)
    {
        printf("%d ",front->data);
        front = front->next;
    }
    printf("\n");
}
void main()
{
    node *front = NULL, *rear = NULL;
    enqueue(&front,&rear,1);
    display(front);
    enqueue(&front,&rear,2);
    enqueue(&front,&rear,3);
    enqueue(&front,&rear,4);
    enqueue(&front,&rear,5);
    enqueue(&front,&rear,6);
    display(front);
    enqueue(&front,&rear,7);
    enqueue(&front,&rear,8);
    enqueue(&front,&rear,9);
    display(front);
    dequeue(&front,&rear);
    dequeue(&front,&rear);
    dequeue(&front,&rear);
    display(front);
    dequeue(&front,&rear);
    dequeue(&front,&rear);
    dequeue(&front,&rear);
    dequeue(&front,&rear);
    dequeue(&front,&rear);
    display(front);

}