#include <iostream>
#include <map>

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

//Removes duplicates elements from Sorted Linked List
void removeDuplicates(Node* &head)
{
    Node *t = head;

    while(t)
    {
        if(t->next != NULL && t->next->data == t->data)
        {
            Node *temp = t->next;
            t->next = temp->next;
            delete temp;
        }
        else
        {
            t = t->next;
        }
    }
}

//Removes duplicates elements from Unsorted Linked List
void removeDuplicatesUnsortedLL(Node* &head)
{
    map<int, bool> visited;
    Node *curr = head;
    Node *prev = NULL;

    while(curr)
    {
        if(visited[curr->data] == true)
        {
            prev->next = curr->next;
            delete curr;
            curr = prev;
        }

        visited[curr->data] = true;

        prev = curr;
        curr = curr->next;
    }
    // T.C. = O(n)
    // S.C. = O(n)

    /*
    Node *curr = head;
    
    while(curr)
    {
        Node *temp = curr->next;
        Node* prev = curr;
        while(temp)
        {

            if(temp->data == curr->data)
            {
                prev->next = temp->next;
                delete temp;
                temp = prev->next;
            }
            else
            {
                prev = temp;
                temp = temp->next;
            }
        }
        curr = curr->next;
    }
    //T.C. = O(n^2)
    //S.C. = O(1)
    */
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
    insertAtBeginning(head, 0);
    insertAtBeginning(head, 5);
    insertAtBeginning(head, 5);
    insertAtBeginning(head, 4);
    insertAtBeginning(head, 4);
    insertAtBeginning(head, 0);
    insertAtBeginning(head, 3);
    insertAtBeginning(head, 1);
    insertAtBeginning(head, 3);
    insertAtBeginning(head, 2);
    insertAtBeginning(head, 3);
    insertAtBeginning(head, 5);
    insertAtBeginning(head, 3);
    insertAtBeginning(head, 2);
    insertAtBeginning(head, 1);
    insertAtBeginning(head, 1);
    insertAtBeginning(head, 1);
    insertAtBeginning(head, 5);
    insertAtBeginning(head, 1);
    insertAtBeginning(head, 0);
    insertAtBeginning(head, 0);
    print(head);
    removeDuplicatesUnsortedLL(head);
    print(head);


    return 0;
}