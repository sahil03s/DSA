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

}
Node* reverse(Node* head)
{
    Node *prev = NULL;
    Node *curr = head;
    Node *nextCurr = NULL;

    while(curr)
    {
        nextCurr = curr->next;
        curr->next = prev; 
        prev = curr;
        curr = nextCurr;
    }

    return prev;
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

Node* addLL(Node* &head1, Node* &head2)
{
    //If one list is empty, return the other one
    if(head1 == NULL)
        return head2;
    if(head2 == NULL)
        return head1;   
    
    //reversing the list since addition is done starting from ones place
    head1 = reverse(head1);
    head2 = reverse(head2);
    int carry = 0;

    //head will be returned as answer
    Node *head = head1;
    Node *prev1 = head1;

    //keep adding digits until one of the list is empty
    while(head1 && head2)
    {
        int sum = head1->data + head2->data + carry;
        carry = sum/10;
        head1->data = sum%10;

        prev1 = head1;
        head1 = head1->next;
        head2 = head2->next; 
    }

    //case when second list has digits while first list has none
    if(head2)
    {
        head1 = head2;
        prev1->next = head2;
    }


    while(head1)
    {
        int sum = head1->data + carry;
        carry = sum/10;
        head1->data = sum%10;

        prev1 = head1;
        head1 = head1->next;
    }

    //if carry is still left while both list have reached null, add a new node with value = carry
    if(carry)
    {
        prev1->next = new Node(carry);
    }

    return reverse(head);

}


int main()
{
    Node *head1 = new Node(1);

    print(head1);
    
    Node *head2 = new Node(9);
    insertAtEnd(head2,9);
    insertAtEnd(head2,9);
    insertAtEnd(head2,9);
    insertAtEnd(head2,9);
    insertAtEnd(head2,9);

    print(head2);

    Node *head = addLL(head1,head2);
    print(head);

    return 0;
}