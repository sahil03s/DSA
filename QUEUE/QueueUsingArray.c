#include <stdio.h>
#include <limits.h>

#define size 10
int queue[size];
int front = -1, rear = -1;

void enqueue(int x)
{
    if(rear == size-1)
    {
        printf("Overflow!");
        return;
    }
    if(front == -1)
        front = rear = 0;
    else
        rear++;
    queue[rear] = x;
}

int dequeue()
{
    if(front == -1)
    {
        printf("Underflow!");
        return INT_MIN;
    }
    int x = queue[front];
    if(front == rear)
        front = rear = -1;
    else
        front++;
    return x;
}

int first()
{
    if(front == -1)
    {
        printf("Underflow!");
        return INT_MIN;
    }
    else
    return queue[front];
}

int last()
{
    if(rear == -1)
    {
        printf("Underflow!");
        return INT_MAX;
    }
    return queue[rear];
}


void display()
{
    int i = front;
    while(i <= rear)
    {
        printf("%d ",queue[i++]);
    }
    printf("\n");
}

void main()
{
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    enqueue(6);
    display();
    dequeue();
    dequeue();
    display();
    enqueue(7);
    enqueue(64);
    enqueue(47);
    enqueue(34);
    enqueue(23);
    enqueue(12);
    display();
    dequeue();
    display();
    enqueue(12);
    display();
    printf("\n%d",first());
    printf("\n%d",last());
}