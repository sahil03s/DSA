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


int getLength(Node *tail)
{
    if(tail == NULL)
        return 0;

    Node *head = tail->next;
    int count = 0;

    do
    {
        count++;
        head = head->next;
    } while (head != tail->next);
    
    return count;
}

Node* split(Node* &tail)
{
    if(tail == NULL || tail->next == NULL)
        return NULL;

    Node* slow = tail->next;
    Node* fast = slow->next;

    while(fast != tail)
    {
        fast = fast->next;
        if(fast != tail)
            fast = fast->next;
        slow = slow->next;
    }

    swap(fast->next,slow->next);

    return slow;

    // T.C. = O(n)
    // S.C. = O(1)



    /*
    if(tail == NULL)
        return NULL;

    int len = (getLength(tail)+1)/2;
    
    Node *tail2 = tail;
    tail = tail->next;
    for(int i=1; i<len; i++)
    {
        tail = tail->next;
    }
    
    Node *temp = tail->next;
    tail->next = tail2->next;
    tail2->next = temp;

    return tail2;
    
    //T.C. = O(n)
    //S.C. = O(1)
    */
}

int main()
{
    Node *tail = NULL;
    insertAtBeginning(tail, 0);
    insertAtBeginning(tail, 1);
    insertAtBeginning(tail, 2);
    insertAtBeginning(tail, 3);
    insertAtBeginning(tail, 5);
    insertAtBeginning(tail, 6);
    insertAtBeginning(tail, 7);
    
    print(tail);
    Node *tail2 = split(tail);
    print(tail2);
    print(tail);



    return 0;
}