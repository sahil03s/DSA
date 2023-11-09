#include <iostream>
#include <vector>

using namespace std;

void insertionSort(vector<int>& arr)
{
    for(int i=1; i<arr.size(); i++)
    {
        int key = arr[i];

        int j;

        for(j=i-1; j>=0; j--)
        {
            if(arr[j] > key)
                arr[j+1] = arr[j];
            else
                break;
        }

        arr[j+1] = key;

    }
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

    insertionSort(v);

    print(v);

    return 0;
}