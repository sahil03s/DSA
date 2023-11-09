#include <iostream>
#include <vector>

using namespace std;

int merge(vector<int>& arr, int lb, int mid, int ub)
{
    vector<int> temp(ub-lb+1, 0);
    
    int k=0;
    int i=lb;
    int j=mid+1;
    int count = 0;

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
            count += mid+1-i;
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
    return count;
}

int mergeSort(vector<int>& arr, int lb, int ub)
{
    int count = 0;
    if(lb < ub)
    {
        int mid = lb + (ub-lb)/2;
        count += mergeSort(arr, lb, mid);
        count += mergeSort(arr, mid+1, ub);
        count += merge(arr, lb, mid, ub);
    }
    return count;
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
    vector<int> v{0,14,7,15 ,9,17,1,4,13,2 ,6,12 ,5,3,8 ,11,10,19,16,18};

    print(v);

    cout << mergeSort(v, 0, v.size()-1) << endl;

    print(v);

    return 0;
}

