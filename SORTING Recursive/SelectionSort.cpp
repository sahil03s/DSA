#include <iostream>
#include <vector>

using namespace std;

void selectionSort(vector<int>& arr, int lb, int ub)
{
    if(lb > ub)
        return;

    int idx = lb;
    for(int i=lb; i<=ub; i++)
    {
        if(arr[idx] > arr[i])
            idx = i;
    }

    if(idx != lb)
        swap(arr[idx],arr[lb]);

    selectionSort(arr, lb+1, ub);
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

    selectionSort(v,0,v.size()-1);

    print(v);

    return 0;
}