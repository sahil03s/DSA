#include <iostream>
#include <vector>

using namespace std;

void insertionSort(vector<int>& arr, int lb , int ub)
{
    if(lb>ub)
        return;
    
    int key = arr[lb];
    int i;
    for(i=lb-1; i>=0 && arr[i]>key; i--)
    {
        arr[i+1] = arr[i];
    }

    arr[i+1] = key;

    insertionSort(arr, lb+1, ub);
}

void print(vector<int> arr)
{
    cout << "Array is : " ;
    
    for(int i : arr)
    {
        cout << i << " ";
    }
    cout << endl << endl;
}

int main()
{
    vector<int> v{7,5,0,8,4,6,7,1,0,0,1};

    print(v);

    insertionSort(v,1,v.size()-1);

    print(v);

    return 0;
}