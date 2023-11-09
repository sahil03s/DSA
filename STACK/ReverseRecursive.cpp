#include <iostream>
#include <stack>

using namespace std;

//T.C. = O(n)  S.C. = O(n)
//insertAtBottom function pushes the num into stack at its bottom
void insertAtBottom(stack<int> &stack, int num)
{
    //if stack is empty, push it and return
    if(stack.empty())
    {
        stack.push(num);
        return;
    }

    //pop the top element and call insertAtBottom function recursively
    int top = stack.top();
    stack.pop();
    insertAtBottom(stack, num);

    //push the popped element back
    stack.push(top);
}

// T.C. = O(n^2)  S.C. = O(n)
void reverse(stack<int> &stack)
{
    //base case
    if(stack.empty())
    {
        return;
    }

    //pop the top element
    int num = stack.top();
    stack.pop();

    //reverse the remaining stack by calling reverse function recursively
    reverse(stack);

    //after remaining stack is reversed, push the popped element at the bottom of reversed stack
    insertAtBottom(stack, num);
}

void print(stack<int> &stack)
{
    
    if(stack.empty())
        return;
    
    //pop the top element and print it
    int num = stack.top();
    cout << num << " ";
    stack.pop();

    //call print function recursively to print all the elements
    print(stack);

    //push back the popped element
    stack.push(num);
}

int main()
{
    stack<int> stack;

    stack.push(10);
    stack.push(9);
    stack.push(8);
    stack.push(7);
    stack.push(6);
    stack.push(5);
    stack.push(4);
    stack.push(3);
    stack.push(2);
    stack.push(1);
    stack.push(0);
   
    print(stack);
    cout << "\n";

    reverse(stack);

    print(stack);
    cout << "\n";


    return 0;
}
