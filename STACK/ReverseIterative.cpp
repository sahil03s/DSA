#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// T.C. = O(n)  S.C. = O(n)
void reverse(stack<int> &stack)
{
    vector<int> v;
    while(!stack.empty())
    {
        v.push_back(stack.top());
        stack.pop();
    }

    for(int i=0; i<v.size(); i++)
    {
        stack.push(v[i]);
    }
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
   
    cout << "Before reversing :\n";
    print(stack);

    reverse(stack);

    cout << "\n\nAfter reversing :\n";
    print(stack);
    cout << "\n";


    return 0;
}
