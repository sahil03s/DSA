#include <iostream>

using namespace std;

//T.C. = O(log n)   S.C. = O(log n)
void heapify(int arr[], int n, int i)
{
    int left = 2*i;
    int right = 2*i+1;
    int smallest = i;

    if(left <= n && arr[left] < arr[smallest])
        smallest = left;

    if(right <= n && arr[right] < arr[smallest])
        smallest = right;

    if(smallest != i)
    {
        swap(arr[i],arr[smallest]);
        heapify(arr, n, smallest);
    }
}

//T.C. = O(nlog n)   S.C. = O(log n)
void buildMinHeap(int arr[], int n)
{
    for(int i=n/2; i; i--)
        heapify(arr, n, i);
}


//T.C. = O(log n)   S.C. = O(log n)
int heapExtractMin(int arr[], int &n)
{
    if(n == 0)
    {
        cout << "Heap Underflow!" << endl;
        return INT_MAX;
    }

    int mini = arr[1];
    arr[1] = arr[n];
    n--;
    heapify(arr, n, 1);

    return mini;
}

//T.C. = O(nlog n)   S.C. = O(log n)
void heapSort(int arr[], int n)
{
    buildMinHeap(arr, n);
    int size = n;
    while(size>1)
    {
        swap(arr[1], arr[size]);
        size--;
        heapify(arr, size, 1);
    }
}

//T.C. = O(log n)   S.C. = O(1)
void insertKey(int arr[], int &n, int val)
{
    n++;
    arr[n] = val;

    int idx = n;
    int parent = idx/2;

    while(idx>1 && arr[idx] < arr[parent])
    {
        swap(arr[idx], arr[parent]);
        idx = parent;
        parent = idx/2;
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
    int heap[] = {-1, 78, 66, 33, 12, 21, 3};
    int n = 6;
    print(heap, n);
    buildMinHeap(heap, n);
    print(heap, n);
    insertKey(heap, n, 1);
    print(heap, n);
    heapSort(heap, n);
    print(heap, n);

}