#include <iostream>

using namespace std;

class queue {
    int *arr;
    int size;
    int front, rear;

    public :
    queue(int size)
    {
        this->size = size;
        arr = new int[size];
        front = rear = -1;
    }

    void enqueueFront(int data)
    {
        if( (front == 0 && rear == size-1) || (front == rear + 1) )
        {
            cout << "Queue overflow!" << endl;
            return;
        }

        if(front == -1)
            front = rear = 0;
        else if(front == 0)
            front = size-1;
        else
            front--;
        
        arr[front] = data;

    }

    void enqueueRear(int data)
    {
        if( (front == 0 && rear == size-1) || (front == rear + 1) )
        {
            cout << "Queue overflow!" << endl;
            return;
        }

        if(front == -1)
        {
            front = rear = 0;
        }
        else if(rear == size-1)
            rear = 0;
        else
            rear++;
        
        arr[rear] = data;
    }

    void dequeueFront()
    {
        if(front == -1)
        {
            cout << "Queue underflow!" << endl;
            return;
        }

        if(front == rear)
            front = rear = -1;
        else if(front == size-1)
            front = 0;
        else
            front++;
    }

    void dequeueRear()
    {
        if(front == -1)
        {
            cout << "Queue underflow!" << endl;
            return;
        }

        if(front == rear)
            front = rear = -1;
        else if(rear == 0)
            rear = size-1;
        else
            rear--;
    }

    int peekFront()
    {
        if(front == -1)
        {
            cout << "Queue underflow!" << endl;
            return -1;
        }

        return arr[front];
    }

    int peekRear()
    {
        if(rear == -1)
        {
            cout << "Queue underflow!" << endl;
            return -1;
        }

        return arr[rear];
    }

    bool empty()
    {
        if(front == -1)
            return true;
        else
            return false;
    }
};

int main()
{
    queue q(10);
    q.enqueueFront(1);
    q.enqueueFront(2);
    q.enqueueFront(4);
    q.enqueueFront(3);
    q.enqueueRear(2);
    q.enqueueRear(3);
    q.enqueueRear(4);
    cout << q.peekFront() << endl;
    cout << q.peekRear() << endl;
    q.enqueueRear(5);
    q.enqueueRear(6);
    q.enqueueRear(7);
    q.enqueueRear(8);
    cout << q.peekFront() << endl;
    cout << q.peekRear() << endl;
    q.enqueueRear(9);
    q.dequeueFront();
    q.dequeueRear();
    cout << q.peekFront() << endl;
    cout << q.peekRear() << endl;
    q.enqueueRear(2);
    return 0;
}