#include <iostream>
#include <vector>

using namespace std;

class Node{
    public :
    int data;
    Node *next;
    Node(){

    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    ~Node()
    {
        this->next = NULL;
        delete next;
    }
};

class Stack{
    Node *head;
    public :
    Stack(){
        head = NULL;
    }
    Stack(int data)
    {
        head = new Node(data);
    }

    void push(int data)
    {
        Node *temp = new Node(data);
        temp->next = head;
        head = temp;
    }

    void pop()
    {
        if(head == NULL)
        {
            cout << "Stack Underflow!\n\n";
            return;
        }

        Node *temp = head;
        head = head->next;
        delete(temp);
    }

    int peek()
    {
        if(head == NULL)
        {
            cout << "Stack is empty!\n\n";
            return INT_MIN;
        }

        return head->data;
    }

    bool isEmpty()
    {
        return head==NULL;
    }
};

int main()
{
    Stack s;
    s.push(5);
    s.push(4);
    s.push(3);
    s.push(2);
    s.push(0);
    cout << s.peek() << "\n";
    s.pop();
    cout << s.peek() << "\n";
    return 0;
}