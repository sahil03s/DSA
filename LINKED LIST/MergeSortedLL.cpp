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

Node* mergeSortedLL(Node* &head1, Node* &head2)
{
    //Cases when one of the list is empty, return the other list
    if(head1 == NULL)
        return head2;

    if(head2 == NULL)
        return head1;

    //choosing head with smaller first element, so that we will insert nodes of other head in this head
    Node *head = (head1->data<=head2->data) ? head1 : head2 ;

    //keeping in head2 -> head with greater first element 
    if(head == head2)
        head2 = head1;

    Node *curr1 = head;
    Node *curr2 = head2;
    Node *next2 = head2;

    while(curr2 && curr1->next)
    {
        //if 2nd list node comes between curr element and its next element, modifications are done
        if(curr2->data >= curr1->data && curr2->data <= curr1->next->data)
        {
            next2 = curr2->next;
            curr2->next = curr1->next;
            curr1->next = curr2;
            curr2 = next2;
        }
        
        curr1 = curr1->next;
    }
    
    //if 2nd list contains element it needs to be added to 1st list (which is to be returned). This occurs when while loop ends because of curr1->next becoming null
    if(curr2)
        curr1->next = curr2;

    return head;
    
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
    Node *head1 = new Node(3);
    insertAtEnd(head1,7);
    insertAtEnd(head1,8);
    insertAtEnd(head1,10);
    Node *head2 = NULL;
    insertAtEnd(head2,1);
    insertAtEnd(head2,2);
    insertAtEnd(head2,4);
    insertAtEnd(head2,5);
    insertAtEnd(head2,11);


    print(head1);
    print(head2);

    Node *head = mergeSortedLL(head1, head2);
    print(head);
    return 0;
}