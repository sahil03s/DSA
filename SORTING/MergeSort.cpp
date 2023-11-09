#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& arr, int lb, int mid, int ub)
{
    vector<int> temp(ub-lb+1, 0);
    
    int k=0;
    int i=lb;
    int j=mid+1;

    while(i<=mid && j<=ub)
    {
        if(arr[i] <= arr[j])
        {
            temp[k] = arr[i];
            k++;
            i++;
        }
        else
        {
            temp[k] = arr[j];
            k++;
            j++;
        }
    }

    while(i<=mid)
    {
        temp[k] = arr[i];
        k++; 
        i++;
    }

    while(j<=ub)
    {
        temp[k] = arr[j];
        k++;
        j++;
    }

    k=0;
    for(int i=lb; i<=ub; i++,k++)
    {
        arr[i] = temp[k];
    }
}

void mergeSort(vector<int>& arr, int lb, int ub)
{
    if(lb < ub)
    {
        int mid = lb + (ub-lb)/2;
        mergeSort(arr, lb, mid);
        mergeSort(arr, mid+1, ub);
        merge(arr, lb, mid, ub);
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

    mergeSort(v, 0, v.size()-1);

    print(v);

    return 0;
}