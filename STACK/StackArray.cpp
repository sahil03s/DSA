#include <iostream>

using namespace std;

class Stack{
    int top;
    int *arr;
    int size;

    public :
    Stack(int size)
    {
        this->size = size;
        top = -1;
        arr = new int[size];
    }

    void push(int data)
    {
        if(top == size-1)
        {
            cout << "Stack overflow!" << endl;
            return;   
        }
        
        top++;
        arr[top] = data;
    }

    void pop()
    {
        if(top == -1)
        {
            cout << "Stack Underflow!" << endl;
            return;
        }

        top--;
    }

    int peek()
    {
        if(top == -1)
        {
            cout << "Stack Underflow!" << endl;
            return INT_MIN;
        }

        return arr[top];
        
    }

    bool isEmpty()
    {
        return top==-1;
    }
};

int main()
{
    Stack s(5);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    s.pop();
    cout << s.peek() << endl << endl;

    return 0;
}