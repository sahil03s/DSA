#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct queue
{
    int *array;
    int rear,front,size;
} queue;

queue* createQueue(int n)
{
    queue *q = (queue *)malloc(sizeof(queue));
    if(!q)
        return NULL;

    q->size = n;
    q->front = q->rear = -1;
    q->array = malloc(n * sizeof(int));

    return q;
}

void enqueue(queue *q, int x)
{
    if(q->rear == q->size - 1)
    {
        printf("Overflow\n");
        return;
    }
    if(q->front == -1)
        q->front = q->rear = 0;
    else
        q->rear++;

    q->array[q->rear] = x;
}

int dequeue(queue *q)
{
    if(q->front == -1)
    {
        printf("Underflow\n");
        return INT_MIN;
    }
    int x = q->array[q->front];
    if(q->front == q->rear)
        q->front = q->rear = -1;
    else
        q->front++;
    
    return x;
}

void display(queue *q)
{
    printf("\n");
    if(q->front == -1)
    {
        printf("No elements\n");
        return;
    }

    int i = q->front;
    while(i <= q->rear)
        printf("%d ",q->array[i++]);
    
    printf("\n");
}
int isEmpty(queue *q)
{
    return q->front == -1;
}
void push(queue **q1, queue **q2, int x)
{
    if((*q1)->rear == (*q1)->size - 1)
    {
        printf("Overflow!\n");
        return;
    }

    enqueue(*q2,x);

    while(!isEmpty(*q1))
        enqueue(*q2, dequeue(*q1));
    
    queue *temp = *q1;
    *q1 = *q2;
    *q2 = temp;
    
}

int pop(queue *q1)
{
    return dequeue(q1);
}

void main()
{
    int n;
    printf("Enter the size of queue : ");
    scanf("%d",&n);
    queue *q1 = createQueue(n);
    queue *q2 = createQueue(n);
    int opt = 0,data;
    while(opt != 4)
    {
        printf("\n1. Enqueue\n2.Dequeue\n3.Display\n4.Exit");
        printf("\nChoose an option : ");
        scanf("%d",&opt);
        while(opt < 1 || opt > 4)
        {
            printf("Choose valid option : ");
            scanf("%d",&opt);
        }
        switch(opt)
        {
            case 1 :
                printf("Enter element : ");
                scanf("%d",&data);
                push(&q1,&q2,data);
                break;
            case 2 :
                printf("%d is dequeued.\n",pop(q1));
                break;
            case 3 :
                display(q1);
                break;
            case 4 :
                printf("Thank u!\n");
                break;
        }
    }
}