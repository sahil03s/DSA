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
        nextCurr = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextCurr;
    }
    head = prev;
}
void reverseRecursive(Node* &head, Node* curr, Node* prev)
{
    if(curr == NULL)
    {
        head = prev;
        return;
    }
    

    reverseRecursive(head, curr->next, curr);
    curr->next = prev;

}
Node* getMiddle(Node* head)
{
    if(head == NULL)
        return head;

    Node *fast = head->next;
    Node *slow = head;

    while(fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;

    // int count = 0;
    // Node* temp = head;
    // while(temp)
    // {
    //     count++;
    //     temp = temp->next;
    // }
    // count /= 2;

    // temp = head;
    // while(count)
    // {
    //     temp = temp->next;
    //     count--;
    // }

    // return temp;

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
    reverseRecursive(head,head, NULL);
    print(head);


    return 0;
}