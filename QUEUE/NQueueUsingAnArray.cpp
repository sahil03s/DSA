#include <iostream>

using namespace std;

//implementation of N queues using single array
class NQueue {
    int *arr; //array that will hold the actual data pushed into diff queues
    int *front; //stores n elements each denoting front of each of the N queues
    int *rear; //stores n elements each denoting rear of each of the N queues
    int *next; //contains (size) no. of elements, if i'th index is vacant in arr, next[i] stores next available free space else if i'th index is filled in arr, next[i] points to next element in the queue
    int n; //no.of queues to be implemented
    int size; //size of arr
    int freeSpot; //next immediately available free space

    public :
    //initialisation of data structure
    NQueue(int n, int size)
    {
        this->n = n;
        this->size = size;
        arr = new int[size];
        next = new int[size];
        front = new int[n];
        rear = new int[n];

        //initially first available free space is 0
        freeSpot = 0;

        //all fronts and rears are -1
        for(int i=0; i<n; i++)
            front[i] = rear[i] = -1;

        //for 0th index, next available free space is 1, for 1st index, it is 2 and so on...except for the last index for which there is no next available free space
        for(int i=0; i<size; i++)
            next[i] = i+1;
        
        next[size-1] = -1;
    }

    void enqueue(int m, int data)
    {
        //if freeSpot = -1, no free space is available which means queue is full
        if(freeSpot == -1)
        {
            cout << "Queue is full !" << endl;
            return;
        }

        //find next available free space at which data can be stored, it can be found from freeSpot 
        int index = freeSpot;

        //update freeSpot to next available free space because current freeSpot will be filled
        freeSpot = next[index];
        
        //push data at index
        arr[index] = data;
        
        //if data which is pushed is first element for queue, update front for the queue
        if(front[m-1] == -1)
            front[m-1] = index;

        //else if elements are present in the queue, last element of the queue (which is pointed by rear currently) must point to its next element i.e. index....this can be done by setting next[last element's index] to index....last element's index is current non-updated rear
        else
            next[rear[m-1]] = index;
        

        //since next[i] points to next element in the queue, next[index] must be set to -1 because index is the last element in this queue till now
        next[index] = -1;

        //update rear for the queue
        rear[m-1] = index;
    }

    int dequeue(int m)
    {
        //if front = -1, queue is empty, return -1
        if(front[m-1] == -1)
        {
            cout << "Queue is empty!" << endl;
            return -1;
        }

        //find index which is to be popped...it is pointed by front of the queue
        int index = front[m-1];

        //updating front to next element in the queue...next element in the queue is pointed by next[index]
        front[m-1] = next[index];

        //since index is now vacant, next[index] must now contain next available free space (which can be found from freeSpot because freeSpot points to next available free space)
        next[index] = freeSpot;

        //next available free space is index position as it is now vacant, so freeSpot points to index now
        freeSpot = index;
        
        //return element at index which is popped
        return arr[index];
    }

    bool empty(int m)
    {
        return (front[m-1] == -1);
    }

};

int main()
{
    NQueue q(3,6);
    q.enqueue(1,10);
    q.enqueue(1,20);
    q.enqueue(2,30);
    q.enqueue(3,40);
    q.enqueue(1,50);
    q.enqueue(2,60);

    cout << q.dequeue(1) << endl;
    cout << q.dequeue(2) << endl;
    cout << q.dequeue(1) << endl;
    cout << q.dequeue(2) << endl;
    cout << ( (q.empty(2)==1)?"Empty":"Not empty" ) << endl;
    cout << ( (q.empty(1)==1)?"Empty":"Not empty" ) << endl;
    cout << q.dequeue(1) << endl;
    cout << q.dequeue(3) << endl;
    cout << ( (q.empty(1)==1)?"Empty":"Not empty" ) << endl;
    return 0;
}