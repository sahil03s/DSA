#include <iostream>

using namespace std;

class Node {
    public :
    int data;
    Node* next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

class queue {
    Node *front;
    Node *rear;

    public :
    queue()
    {
        front = NULL;
        rear = NULL;
    }

    void enqueue(int data)
    {
        Node *temp = new Node(data);
        if(rear == NULL)
            front = rear = temp;
        
        else
        {
            rear->next = temp;
            rear = rear->next;
        }
    }

    void dequeue()
    {
        if(front == NULL)
        {
            cout << "Queue underflow!" << endl;
            return;
        }

        if(front == rear)
        {
            delete front;
            front = rear = NULL;
        }
        else
        {
            Node *temp = front;
            front = front->next;
            delete temp;
        }
    }

    int peek()
    {
        if(front == NULL)
        {
            cout << "Queue underflow!" << endl;
            return -1;
        }

        return front->data;
    }

    bool empty()
    {
        if(front == NULL)
            return true;
        else
            return false;
    }
};

int main()
{
    queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    cout << q.peek() << endl;
    q.dequeue();
    q.dequeue();
    cout << q.peek() << endl;
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);
    q.dequeue();
    q.dequeue();
    q.dequeue();
    cout << q.peek() << endl;
    return 0;
}