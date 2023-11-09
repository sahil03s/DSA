#include <iostream>
#include <vector>

using namespace std;

void bubbleSort(vector<int>& arr)
{
    for(int i=0; i<arr.size()-1; i++)
    {
        for(int j=0; j<arr.size()-1-i; j++)
        {
            if(arr[j] > arr[j+1])
            {
                swap(arr[j],arr[j+1]);
            }
        }
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

    bubbleSort(v);

    print(v);

    return 0;
}