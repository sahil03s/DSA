#include <iostream>
#include <vector>

using namespace std;

int parent(int i) { return i/2; }
int left(int i) { return 2*i; }
int right(int i) { return 2*i+1; }

//T.C. = O(log n)   S.C. = O(log n)
void heapify(int arr[], int n, int i)
{
    int left = 2*i;
    int right = 2*i+1;
    int largest = i;

    if(left <= n && arr[left] > arr[largest])
        largest = left;
        
    if(right <= n && arr[right] > arr[largest])
        largest = right;
        
    if(largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

//T.C. = O(nlog n)   S.C. = O(log n)
void buildMaxHeap(int arr[], int n)
{
    for(int i=n/2; i; i--)
        heapify(arr,n,i);
}

//T.C. = O(log n)   S.C. = O(log n)
int heapExtractMax(int arr[], int &n)
{
    if(n ==  0)
    {
        cout << "Heap underflow!" << endl;
        return INT_MIN;
    }

    int maxi = arr[1];

    arr[1] = arr[n];
    n--;

    heapify(arr, n, 1);

    return maxi;
}


//T.C. = O(nlog n)   S.C. = O(log n)
void heapSort(int arr[], int n)
{
    buildMaxHeap(arr,n);
    int size = n;
    while(size > 1)
    {
        swap(arr[1],arr[size]);
        size--;
        heapify(arr,size,1);
    }
}

//T.C. = O(log n)   S.C. = O(1)
void insertKey(int arr[], int &n, int val)
{
    n++;
    arr[n] = val;

    int i = n;
    int parentIdx = i/2;
    while(i>1 && arr[i] > arr[parentIdx])
    {
        swap(arr[i],arr[parentIdx]);
        i = parentIdx;
        parentIdx = i/2;
    }
}

//T.C. = O(n)   S.C. = O(1)
void print(int arr[], int n)
{
    cout << endl ;
    for(int i=1; i<=n; i++)
        cout << arr[i] << " ";

    cout << "\n";
}

int main()
{
    int heap[100] = {-1, 54, 53, 55, 52, 50};
    int n = 5;
    buildMaxHeap(heap, n);
    print(heap, n);
    heapExtractMax(heap, n);
    print(heap, n);
    heapSort(heap,n);
    print(heap, n);
    return 0;
}