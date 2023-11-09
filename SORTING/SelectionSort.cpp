#include <iostream>
#include <vector>

using namespace std;

void selectionSort(vector<int>& arr)
{
    for(int i=0; i<arr.size()-1; i++)
    {
        int min = i;

        for(int j=i+1; j<arr.size(); j++)
        {
            if(arr[j] < arr[min])
                min = j;
        }

        if(min != i)
            swap(arr[min],arr[i]);

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
    //vector<int> v{5,4,3,2,1};

    print(v);

    selectionSort(v);

    print(v);

    return 0;
}