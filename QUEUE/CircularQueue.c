#include <stdio.h>
#include <limits.h>

#define size 10

int queue[size];
int front = -1, rear = -1;

void enqueue(int x)
{
    if((front == 0 && rear == size-1) || front == rear + 1 )
    {
        printf("Overflow!\n");
        return;
    }
    
    if(front == -1)
        front = rear = 0;
    else if(rear == size - 1 && front != 0)
        rear = 0;//
    else
        rear++;
    queue[rear] = x;
}
int dequeue()
{
    if(front == -1)
    {
        printf("Underflow!\n");
        return INT_MIN;
    }
    int x = queue[front];
    if(front == rear)
        front = rear = -1;
    else if(front == size - 1)
        front = 0;
    else
        front++;
    return x;
}

int first()
{
    if(front == -1)
    {
        printf("Underflow!\n");
        return INT_MIN;
    }
    return queue[front];
}
int last()
{
    if(front == -1)
    {
        printf("Underflow!\n");
        return INT_MIN;
    }
    return queue[rear];
}

void display()
{
    int i = front - 1;
    if(front == -1)
    {
        printf("Underflow!\n");
        return;
    }

    printf("\n");
    do
    {
        i++;
        printf("%d ",queue[i]);
        if(i == size - 1 )
            i = -1;
        
    }while(i != rear);
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
    enqueue(8);
    enqueue(9);
    enqueue(10);
    enqueue(11);
    enqueue(12);
    display();
    printf("\n%d\t%d\n",first(),last());
    enqueue(13);
    display();
    dequeue();
    dequeue();
    display();
    printf("\n%d\t%d\n",first(),last());
    enqueue(13);
    enqueue(14);
    display();
    printf("\n%d\t%d\n",first(),last());
    dequeue();
    enqueue(14);
    display();
    printf("\n%d\t%d\n",first(),last());
}