#include <iostream>

using namespace std;

class Node{
    public : 
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
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
void print(Node *head)


{
    while(head)
    {
        cout << head->data << " " ;
        head = head->next;
    }
    cout << "\n\n";
}

Node* getMiddle(Node *head)
{
    if(head == NULL)
        return head;
    
    Node *slow = head;
    Node *fast = head->next;

    while(fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow;
}

Node* mergeSortedLL(Node* left, Node* right)
{
    if(left == NULL)
        return right;
    if(right == NULL)
        return left;

    Node *head = (left->data <= right->data) ? left : right ;

    if(head == right)
        right = left;

    Node *curr = head;

    while(right && curr->next)
    {
        if(right->data >= curr->data && right->data <= curr->next->data)
        {
            Node *next = right->next;
            right->next = curr->next;
            curr->next = right;
            right = next;
        }

        curr = curr->next;
    }

    if(right)
    {
        curr->next = right;
    }

    return head;
}

Node* mergeSort(Node *head)
{
    if(head == NULL || head->next == NULL)
        return head;

    Node *mid = getMiddle(head);

    Node *left = head;
    Node *right = mid->next;
    mid->next = NULL;

    left = mergeSort(left);
    right = mergeSort(right);

    return mergeSortedLL(left, right);
}

int main()
{
    Node *head = new Node(10);
    insertAtEnd(head,8);
    insertAtEnd(head,5);
    insertAtEnd(head,7);
    insertAtEnd(head,12);
    insertAtEnd(head,0);
    insertAtEnd(head,1);
    insertAtEnd(head,6);
    insertAtEnd(head,4);
    print(head);
    head = mergeSort(head);
    print(head);
    return 0;
}