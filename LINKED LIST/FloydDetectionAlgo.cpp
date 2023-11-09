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

Node* floydDetectionLoop(Node* head)
{
    if(head == NULL)
        return NULL;
    
    Node* slow = head;
    Node* fast = head;

    while(fast != NULL)
    {
        fast = fast->next;
        if(fast)
            fast = fast->next;
        
        slow = slow->next;

        if(fast == slow)
            return fast; 
    }
    return NULL;
}
Node* startOfLoop(Node* head)
{
    Node* fast = floydDetectionLoop(head);
    if(fast == NULL)
        return NULL;

    Node* slow = head;

    while(slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
}

void removeLoop(Node* &head)
{
    Node* start = startOfLoop(head);
    Node* temp = start;

    
    do
    {
        temp = temp->next;
    }while(temp->next != start);

    temp->next = NULL;

}

int main()
{
    Node *tail = NULL;
    insertAtBeginning(tail, 0);
    insertAtBeginning(tail, 10);
    insertAtBeginning(tail, 1);
    insertAtBeginning(tail, 2);
    insertAtEnd(tail, 6);
    insertAtEnd(tail, 7);
    print(tail);
    cout << floydDetectionLoop(tail->next)->data << endl;
    cout << (startOfLoop(tail->next))->data << endl;
    Node *head = tail->next;
    removeLoop(head);
    
    while(head)
    {
        cout << head->data << " ";
        head = head->next;
    }

    return 0;
}