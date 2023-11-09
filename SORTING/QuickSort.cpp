#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int>& arr, int lb, int ub)
{
    int pivot = arr[lb];
    int start = lb;
    int end = ub;

    while(start<end)
    {
        while(start<=ub && arr[start] <= pivot)
            start++;
        
        while(end>=lb && arr[end] > pivot)
            end--;
        
        if(start < end)
            swap(arr[start], arr[end]);
    }

    swap(arr[lb], arr[end]);

    return end;
}

// int partition(vector<int>& arr, int lb, int ub)
// {
//     int pivot = arr[ub];
//     int start = lb;
//     int end = ub;

//     while(start<end)
//     {
//         while(start<=ub && arr[start] < pivot)
//             start++;
        
//         while(end>=lb && arr[end] >= pivot)
//             end--;
        
//         if(start < end)
//             swap(arr[start], arr[end]);
//     }

//     swap(arr[ub], arr[start]);

//     return start;
// }

// int partition(vector<int>& arr, int lb, int ub)
// {
//     int pivot = arr[lb];
//     int i=ub+1;
//     for(int j=ub; j>lb; j--)
//     {
//         if(arr[j] > pivot)
//         {
//             i--;
//             swap(arr[i],arr[j]);
//         }
//     }

//     swap(arr[lb],arr[i-1]);

//     return i-1;
// }

// int partition(vector<int>& arr, int lb, int ub)
// {
//     int pivot = arr[ub];
//     int i=lb-1;
//     for(int j=lb; j<ub; j++)
//     {
//         if(arr[j] <= pivot)
//         {
//             i++;
//             swap(arr[i],arr[j]);
//         }
//     }

//     swap(arr[ub],arr[i+1]);

//     return i+1;
// }



void quickSort(vector<int>& arr, int lb, int ub)
{
    if(lb<ub)
    {
        int loc = partition(arr, lb, ub);
        quickSort(arr, lb, loc-1);
        quickSort(arr, loc+1, ub);
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

    quickSort(v, 0, v.size()-1);

    print(v);

    return 0;
}