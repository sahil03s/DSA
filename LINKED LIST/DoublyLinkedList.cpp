#include <iostream>

using namespace std;

class Node
{
    public:
    Node *prev;
    int data;
    Node *next;
    Node()
    {
        this->prev = NULL;
        this->data = 0;
        this->next = NULL;
    }

    Node(int data)
    {
        this->prev = NULL;
        this->data = data;
        this->next = NULL;
    }

    Node(int data, Node *ptr)
    {
        this->prev = NULL;
        this->data = data;
        this->next = ptr;
    }

    Node(Node *ptr1, int data, Node *ptr2)
    {
        this->prev = ptr1;
        this->data = data;
        this->next = ptr2;
    }   

    ~Node()
    {
        if(this->prev != NULL)
        {
            this->prev = NULL;
            delete prev;
        }

        if(this->next != NULL)
        {
            this->next = NULL;
            delete next;
        }
        
    } 
};

void insertAtBeginning(Node* &head, int data)
{
    Node *temp = new Node(data);
    temp->prev = NULL;
    temp->next = head;

    if(head)
        head->prev = temp;
        
    head = temp;
}
void insertAtEnd(Node* &head, int data)
{
    if(head == NULL)
    {
        head = new Node(data);
        return;
    }

    Node *temp = head;
    while(temp->next)
        temp = temp->next;
    
    Node *t = new Node(data);
    t->prev = temp;
    temp->next = t;

}
void insertAtPosition(Node* &head, int data, int position)
{
    if(position == 1)
    {
        insertAtBeginning(head, data);
        return;
    }

    Node *temp = head;

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
        t->prev = temp;
        t->next = temp->next;
        t->next->prev = t;
        temp->next = t;
    }
    

}
void insertAtTail(Node* &tail, int data)
{
    Node *temp = new Node(data);
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}
void deleteValue(Node* &head, int value)
{
    if(head && head->data == value)
    {
        Node *temp = head;
        head = head->next;
        head->prev = NULL;
        delete temp;
        return;
    }

    Node *temp = head;
    while(temp->next && temp->next->data != value)
        temp = temp->next;
    
    if(temp->next == NULL)
    {
        cout << "Value not found!" << endl;
        return;
    }
    else
    {
        Node *t = temp->next;
        temp->next = t->next;
        t->next->prev = temp;
        delete t;
    }
}
void deletePosition(Node* &head, int position)
{
    if(head == NULL)
    {
        cout << "No elements present!\n\n";
        return;
    }

    if(position == 1)
    {
        Node *temp = head;
        head = head->next;
        head->prev = NULL;
        delete temp;
        return;
    }

    Node* temp = head;
    for(int i=1; temp && i<position-1; i++)
        temp = temp->next;
    
    if(temp == NULL || temp->next == NULL)
    {
        cout << "Position not present!\n\n";
        return;
    }

    Node *t = temp->next;
    temp->next = t->next;
    if(t->next)
        t->next->prev = temp;
    delete t;
}
void reverse(Node* &head)
{
    Node *prevNode = NULL;
    Node *curr = head;
    Node *nextCurr = head;
    
    while(curr)
    {
        nextCurr = nextCurr->next;
        curr->next = prevNode;
        curr->prev = nextCurr;
        prevNode = curr;
        curr = nextCurr;
    }
    head = prevNode;
}
void reverseRecursive(Node* &head, Node* curr, Node* prevNode)
{
    if(curr == NULL)
        return;
    
    head = curr;

    reverseRecursive(head, curr->next, curr);
    curr->prev = curr->next;
    curr->next = prevNode;

}
void print(Node *head)
{
    while(head)
    {
        cout << head->data << " " ;
        head = head->next;
    }
    cout << "\n\n";
}

int main()
{
    Node *head = new Node();
    print(head);
    insertAtBeginning(head, 1);
    insertAtBeginning(head, 2);
    insertAtBeginning(head, 3);
    insertAtBeginning(head, 4);
    insertAtBeginning(head, 5);
    print(head);
    deletePosition(head,2);
    print(head);

    return 0;
}