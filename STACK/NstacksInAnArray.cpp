#include <iostream>

using namespace std;

//NStack implements N stacks in one single array
class NStack
{
public:
    int *arr; //stores the elements in stacks
    int *top; //stores the indices of top elements of n stacks
    
    // next array is of the same size as arr, next[idx] keeps two things, if idx position is vacant in the arr, next[idx] keeps track of next available free space in the array, else if idx position is filled in the arr, next[idx] keeps track of next element in stack i.e. element which is just below the idx element in the stack
    int *next;
    
    
    int size; //stores the size of arr
    int n;    //no. of stacks to be implemented
    int freeSpot; //stores next free space available index
    
    //initialisation of Nstack data structure
    NStack(int N, int S)
    {
        // T.C. = O(1)    S.C. = O(n+s)
        size = S;
        n = N;
        freeSpot = 0;    //initially first free available space is 0
        arr = new int[S]; 
        top = new int[N];   // n stacks implies n tops
        next = new int[S];  
            
        //initially all tops are -1
        for(int i=0; i<N; i++)
            top[i] = -1;        
        
        //initially for i'th index, i+1 is the next available free space, except for the last index for which there is no available free space, so next[lastIndex] = -1 
        for(int i=0; i<S; i++)
            next[i] = i+1;
        
        next[S-1] = -1;
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
        //if freeSpot = -1, it means array is full and no free space is available, return false in such case
        if(freeSpot == -1)
            return false;
        
        //for pushing x, first we find the first free available space, we can get it from freeSpot
        int idx = freeSpot;

        //freeSpot must be updated to the next free available space, we can get it from next[idx] because next[idx] keeps index of next free available space if that index is not filled in array
        freeSpot = next[idx];

        //pushing x to stack by filling it in array at index
        arr[idx] = x;

        //since now index position is fiiled in the array, so next[idx] needs to point to the previous element in the stack which is pointed currently by top[m-1]
        next[idx] = top[m-1];

        //top gets updated to idx since idx is the recently pushed element
        top[m-1] = idx;

        return true;
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        //if top = -1, it means that stack is empty, so return -1
        if(top[m-1] == -1)
            return -1;
        
        //getting the index at which element to be popped is present
        int idx = top[m-1];

        //x is the element which is to be popped and will be returned
        int x = arr[idx];

        //top which is currently at index will now point to next element in the stack, which is stored at next[idx]
        top[m-1] = next[idx];

        //since now index position is vacant, next[idx] needs to hold the next free available space
        next[idx] = freeSpot;

        //freeSpot needs to be updated to index which is now vacant
        freeSpot = idx;

        return x;
    }
};

int main()
{
    NStack stack(3,6);

    cout << ( (stack.push(10,1) == 1)?"True":"False" ) << endl;
    cout << ( (stack.push(20,1) == 1)?"True":"False" ) << endl;
    cout << ( (stack.push(30,2) == 1)?"True":"False" ) << endl;
    cout << ( (stack.push(40,1) == 1)?"True":"False" ) << endl;
    cout << ( (stack.push(50,2) == 1)?"True":"False" ) << endl;
    cout << ( (stack.push(60,1) == 1)?"True":"False" ) << endl;
    cout << ( (stack.push(70,3) == 1)?"True":"False" ) << endl;
    cout << stack.pop(1) << endl;
    cout << stack.pop(1) << endl;
    cout << stack.pop(1) << endl;
    cout << stack.pop(2) << endl;
    cout << stack.pop(3) << endl;
    cout << stack.pop(2) << endl;
    return 0;
}