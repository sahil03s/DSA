/*
I/P : 1->2->3->4->5->6->7->8  (k=3)
O/P : 3->2->1->6->5->4->7->8
*/

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

void insertAtBeginning(Node* &head, int data)
{
    Node *temp = new Node(data);
    temp->next = head;
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
    
    temp->next = new Node(data);
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
        t->next = temp->next;
        temp->next = t;
    }
    

}
void insertAtTail(Node* &tail, int data)
{
    Node *temp = new Node(data);
    tail->next = temp;
    tail = temp;
}
void deleteValue(Node* &head, int value)
{
    if(head && head->data == value)
    {
        Node *temp = head;
        head = head->next;
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
        temp->next = temp->next->next;
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
    delete t;
}
void reverse(Node* &head)
{
    Node *prev = NULL;
    Node *curr = head;
    Node *nextCurr = head;
    
    while(curr)
    {
        nextCurr = nextCurr->next;
        curr->next = prev;
        prev = curr;
        curr = nextCurr;
    }
    head = prev;
}
void reverseRecursive(Node* &head, Node* curr, Node* prev)
{
    if(curr == NULL)
        return;
    
    head = curr;

    reverseRecursive(head, curr->next, curr);
    curr->next = prev;

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

Node* reverse_k_order(Node *curr, int &k)
{
    if(curr == NULL)
        return NULL;
    
    Node *temp = curr;
    for(int i=0;temp && i<k-1; i++)
        temp = temp->next;
    
    if(temp == NULL)
        return curr;
    
    temp = curr;
    Node *prev = NULL;
    for(int i=0; i<k; i++)
    {
        temp->next = prev;
        prev = temp;
        temp = temp->next;
    }
    curr->next = reverse_k_order(temp, k);

    return prev;

    
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
    int k = 3;
    head = reverse_k_order(head, k);
    print(head);

    return 0;
}