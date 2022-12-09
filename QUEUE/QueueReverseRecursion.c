#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct node
{
    int data;
    struct node *next;
} node;



void enqueue(node **front, node **rear, int x)
{
    node *temp = (node*)malloc(sizeof(node));
    if(!temp)
    {
        printf("Overflow!\n");
        return;
    }

    temp->data = x;
    temp->next = NULL;

    if(!*front)
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
    node *q = *front;
    if(*front == *rear)
        *front = *rear = NULL;
    else
        *front = (*front)->next;

    free(q);
    return x;
}

int first(node *front)
{
    if(!front)
    {
        printf("Underflow!\n");
        return INT_MIN;
    }
    return front->data;
}

int last(node *rear)
{
    if(!rear)
    {
        printf("Underflow!\n");
        return INT_MIN;
    }
    return rear->data;
}

void display(node *front)
{
    printf("\n");
    if(!front)
    {
        printf("No Elements\n");
        return;
    }
    while(front)
    {
        printf("%d ",front->data);
        front = front->next;
    }
    printf("\n");
}
void reverse(node **front, node **rear)
{
    if(!*front)
        return;
    int x = dequeue(front,rear);
    reverse(front,rear);
    enqueue(front, rear, x);
}
int size(node *front)
{
    int count = 0;
    while(front)
    {
        count++;
        front = front->next;
    }
    return count;
}

void reverse_k1(node **front, node **rear, int k)
{
    static int i = 0;
    if(i == k)
        return;
    int x = dequeue(front, rear);
    i++;
    reverse_k1(front,rear,k);
    enqueue(front, rear, x);
}
void reverse_k2(node **front, node **rear, int k)
{
    int n = size(*front);
    int i = 0, x;
    while(i < n-k)
    {
        x = dequeue(front,rear);
        enqueue(front,rear,x);
        i++;
    }
}
void reverse_k(node **front, node **rear, int k)
{
    reverse_k1(front,rear,k);
    reverse_k2(front,rear,k);
}
void main()
{
    node *front = NULL, *rear = NULL;
    display(front);
    enqueue(&front, &rear,10);
    enqueue(&front, &rear,9);
    enqueue(&front, &rear,8);
    display(front);
    dequeue(&front,&rear);
    display(front);
    enqueue(&front, &rear,8);
    enqueue(&front, &rear,8);
    dequeue(&front,&rear);
    display(front);
    enqueue(&front, &rear,7);
    display(front);
    enqueue(&front, &rear,6);
    enqueue(&front, &rear,5);
    display(front);
    dequeue(&front,&rear);
    dequeue(&front,&rear);
    display(front);
    dequeue(&front,&rear);
    dequeue(&front,&rear);
    dequeue(&front,&rear);
    dequeue(&front,&rear);
    display(front);
    dequeue(&front,&rear);
    dequeue(&front,&rear);
    display(front);
    enqueue(&front,&rear,1);
    enqueue(&front,&rear,2);
    enqueue(&front,&rear,3);
    enqueue(&front,&rear,4);
    enqueue(&front,&rear,5);
    enqueue(&front,&rear,6);
    enqueue(&front,&rear,7);
    display(front);
    reverse(&front,&rear);
    display(front);
    reverse(&front,&rear);
    display(front);
    reverse_k(&front,&rear,4);
    display(front);
    
}