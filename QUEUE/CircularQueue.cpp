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

    void enqueue(int data)
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

    void dequeue()
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

    int peek()
    {
        if(front == -1)
        {
            cout << "Queue underflow!" << endl;
            return -1;
        }

        return arr[front];
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
    queue q(5);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    cout << q.peek() << endl;
    q.dequeue();
    q.dequeue();
    cout << q.peek() << endl;
    q.enqueue(4);
    q.enqueue(5);
    q.dequeue();
    q.dequeue();
    q.enqueue(6);
    cout << q.peek() << endl;
    return 0;
}