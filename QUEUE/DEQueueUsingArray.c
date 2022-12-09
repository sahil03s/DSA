#include <stdio.h>
#include <limits.h>

#define size 10

int queue[size];
int front = -1, rear = -1;

void enqueue_rear(int x)
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

void enqueue_front(int x)
{
    if((front == 0 && rear == size-1) || front == rear + 1 )
    {
        printf("Overflow!\n");
        return;
    }
    
    if(front == -1)
        front = rear = 0;
    else if(front == 0 && rear != size-1)
        front = size - 1;
    else 
        front--;

    queue[front] = x;

}


int dequeue_front()
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

int dequeue_rear()
{
    if(front == -1)
    {
        printf("Underflow!\n");
        return INT_MIN;
    }
    int x = queue[rear];
    if(front == rear)
        front = rear = -1;
    else if(rear == 0)
        rear = size - 1;
    else
        rear --;
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
    enqueue_front(1);
    enqueue_front(2);
    enqueue_front(3);
    enqueue_front(4);
    enqueue_rear(2);
    enqueue_rear(3);
    enqueue_rear(4);
    enqueue_rear(5);
    enqueue_rear(6);
    enqueue_rear(7);
    enqueue_rear(8);
    enqueue_rear(9);
    display();
    dequeue_front();
    display();
    dequeue_rear();
    display();
    enqueue_front(0);
    display();
    enqueue_rear(0);
    display();
    enqueue_rear(2);
    display();
}