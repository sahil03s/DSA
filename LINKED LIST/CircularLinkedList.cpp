#include <iostream>

using namespace std;

class Node
{
    public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        this->next = NULL;
    }

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    Node(int data, Node *ptr)
    {
        this->data = data;
        this->next = ptr;
    }   
    ~Node()
    {
        if(this->next != NULL)
        {
            this->next = NULL;
            delete next;
        }
    } 
};

void insertAtBeginning(Node* &tail, int data)
{
    Node *temp = new Node(data);

    if(tail == NULL)
    {
        tail = temp;
        tail->next = tail;

    }
    else
    {
        temp->next = tail->next;
        tail->next = temp;
    }
}
void insertAtEnd(Node* &tail, int data)
{
    Node *temp = new Node(data);
    
    if(tail == NULL)
    {
        tail = temp;
        tail->next = tail;
    }
    else
    {
        temp->next = tail->next;
        tail->next = temp;
        tail = temp;
    }
}
void insertAtPosition(Node* &tail, int data, int position)
{
    if(position == 1)
    {
        insertAtBeginning(tail, data);
        return;
    }

    if(tail == NULL)
    {
        cout << "Position not available!" << endl;
        return;
    }

    Node *temp = tail->next;

    for(int i=1; temp && i<position-1; i++)
        temp = temp->next;
    
    if(temp == NULL)
    {
        cout << "Position not available!" << endl;
        return;
    }
    else
    {
        Node *t = new Node(data);
        t->next = temp->next;
        temp->next = t;

        if(temp == tail)
            tail = t;
    }
    

}
void deleteValue(Node* &tail, int value)
{
    if(tail == NULL)
    {
        cout << "No elements present!\n\n";
        return;
    }

    Node *temp = tail;
    do
    {
        temp = temp->next;
    }while(temp->next != tail->next && temp->next->data != value);
    
    if(temp->next->data != value)
    {
        cout << "Value not found!" << endl;
        return;
    }
    else
    {
        Node *t = temp->next;
        temp->next = t->next;
        if(t == tail)
            tail = temp;
        delete t;
    }
}
void deletePosition(Node* &tail, int position)
{
    if(tail == NULL)
    {
        cout << "No elements present!\n\n";
        return;
    }

    if(position == 1)
    {
        Node *temp = tail->next;
        if(temp == tail)
            tail = NULL;
        else
            tail->next = temp->next;
        delete temp;
        return;
    }

    Node* temp = tail->next;
    for(int i=1; i<position-1; i++)
        temp = temp->next;

    Node *t = temp->next;
    temp->next = t->next;
    if(t == tail)
        tail = temp;
    delete t;
}
void reverse(Node* &tail)
{
    Node *prev = tail;
    Node *curr = tail->next;
    Node *nextCurr = tail->next;
    Node *ptr = tail->next;
    
    do
    {
        nextCurr = nextCurr->next;
        curr->next = prev;
        prev = curr;
        curr = nextCurr;
    }while(curr != ptr);
    tail = ptr;
}
void reverseRecursive(Node* &tail, Node* curr, Node* prev, Node* &ptr, int flag)
{
    if(curr == ptr)
    {
        if(flag)
            flag = 0;
        else
            return;
    }

    reverseRecursive(tail, curr->next, curr, ptr, flag);
    curr->next = prev;

    
    tail = curr;

}
void print(Node *tail)
{
    if(tail == NULL)
        return;
    
    Node *head = tail->next;
    do
    {
        cout << head->data << " " ;
        head = head->next;
    }  while(head != tail->next);

    cout << "\n\n";
}

int main()
{
    Node *tail = NULL;
    insertAtBeginning(tail, 0);
    insertAtBeginning(tail, 1);
    insertAtBeginning(tail, 2);
    insertAtBeginning(tail, 3);
    insertAtEnd(tail, 6);
    insertAtEnd(tail, 7);
    print(tail);
    deletePosition(tail, 2);
    print(tail);


    return 0;
}