#include <iostream>
#include <stack>

using namespace std;

//T.C. = O(n)  S.C. = O(n)
//insert function pushes the num into stack in sorted ascending order 
void insert(stack<int> &stack, int num)
{
    //if either stack is empty or top element is greater than or equal to num, push it and return
    if(stack.empty() || stack.top() >= num)
    {
        stack.push(num);
        return;
    }

    //pop the top element and call insert function recursively
    int top = stack.top();
    stack.pop();
    insert(stack, num);

    //push the popped element back
    stack.push(top);
}

//T.C. = O(n^2)  S.C. = O(n)
void sort(stack<int> &stack)
{
    //base case
    if(stack.empty())
    {
        return;
    }

    //pop the top element
    int num = stack.top();
    stack.pop();

    //sort the remaining stack by calling sort function recursively
    sort(stack);

    //after remaining stack is sorted, push the popped element back in sorted manner
    insert(stack, num);
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
    print(stack);
    cout << "\n";
    stack.push(9);
    stack.push(8);
    stack.push(7);
    stack.push(6);
    stack.push(5);
    print(stack);
    cout << "\n";
    print(stack);
    cout << "\n";
    stack.pop();
    stack.pop();
    stack.push(5);
    stack.push(6);
    stack.push(7);
    stack.push(8);
    print(stack);
    cout << "\n";
    print(stack);
    cout << "\n";
    sort(stack);
    print(stack);
    cout << "\n";
    return 0;
}
