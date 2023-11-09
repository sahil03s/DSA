#include <iostream>
#include <vector>

using namespace std;

void bubbleSort(vector<int>& arr, int n)
{
    if(n<=1)
        return;
    
    for(int i=0; i<n-1; i++)
    {
        if(arr[i] > arr[i+1])
        {
            int temp = arr[i];
            arr[i] = arr[i+1];
            arr[i+1] = temp;
        }
    }
    
    bubbleSort(arr,n-1);
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

    bubbleSort(v, v.size());

    print(v);

    return 0;
}